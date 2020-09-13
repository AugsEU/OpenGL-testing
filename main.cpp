#include "Utils.h"

#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"
#include "Renderer.h"
#include "WavefrontModel.h"
#include "Texture.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	GLCall(glViewport(0, 0, width, height));

}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

int main(int argc, char* argv[])
{
	//GLFW INIT
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//Create window
	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return-1;
	}

	//std::cout << "GL Version 330" << std::endl;
	//Make GL Context
	glfwMakeContextCurrent(window);

	//Load GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to init GLAD" << std::endl;
		return -1;
	}


	//For window re-sizing 
	GLCall(glfwSetFramebufferSizeCallback(window, framebuffer_size_callback));

	//Define Coordinates
	GLCall(glViewport(0, 0, 800, 600));

	//
	//Drawing a triangle set up
	//
	//Define Triangle
	//static const float V_pos[] = {
	//	-0.5f, -0.5f,
	//	 0.5f, -0.5f,
	//	 0.5f,  0.5f,
	//	-0.5f,  0.5f
	//};

	//static const unsigned int SquareIdx[] = {
	//	0, 1, 2,
	//	2, 3, 0
	//};

	{
		////Create VAO
		VertexArray VAO;

		////Create vertex buffer
		//VertexBuffer MyVB(V_pos, 4 * 2 * sizeof(float));
		WavefrontModel OBJLoader;
		OBJLoader.LoadOBJ("C:\\Users\\August\\Documents\\Models\\Test.obj");
		//Set layout of buffer
		VertexBufferLayout Layout;
		Layout.Push<float>(3);//Add a coordinate element
		VAO.AddBuffer(*OBJLoader.mVB, Layout);
		//VAO.AddBuffer(MyVB, Layout);

		
		//Create index buffer
		//IndexBuffer MyIB(SquareIdx, 6);

		//Create shaders
		Shader sProgram("./res/shaders/Basic/Vertex.shader", "./res/shaders/Basic/Fragment.shader");
		sProgram.Bind();

		Texture myTexture("C:\\Users\\August\\Pictures\\DKACFLAG.png");
		myTexture.Bind(0);

		//Unbind everything
		VAO.Unbind();
		//MyIB.UnBind();
		//MyVB.UnBind();
		sProgram.Unbind();

		//Set uniform
		unsigned int UniLocation = sProgram.GetUniformLocation("u_Color");
		float r = 0.0f;

		Renderer MyRenerer;
		glfwSwapInterval(1);
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

		while (!glfwWindowShouldClose(window))
		{

			//Render
			MyRenerer.Clear();

			sProgram.Bind();
			if (r > 1.0f)
			{
				r = 0.0f;
			}
			r += 0.001;
			if (UniLocation != -1)
			{
				GLCall(glUniform4f(UniLocation, r, 0.1f, 0.1f, 1.0f));
			}

			MyRenerer.Draw(VAO, *OBJLoader.mIB, sProgram);

			//Swap buffers
			GLCall(glfwSwapBuffers(window));
			GLCall(glfwPollEvents());
		}

	}
	glfwTerminate();
	return 0;
}

