#include "Shader.h"

Shader::Shader(const std::string vFile, const std::string fFile)
{
	mRendererID = glCreateProgram();//create program
	unsigned int vShader = CompileShader(ReadFile(vFile), GL_VERTEX_SHADER);//create shader
	unsigned int fShader = CompileShader(ReadFile(fFile), GL_FRAGMENT_SHADER);

	GLCall(glAttachShader(mRendererID, vShader));//copy to program
	GLCall(glAttachShader(mRendererID, fShader));

	GLCall(glLinkProgram(mRendererID));//Link the program
	GLCall(glValidateProgram(mRendererID));

	GLCall(glDeleteShader(vShader));//delete shaders
	GLCall(glDeleteShader(fShader));

}

Shader::~Shader()
{
}

void Shader::Bind() const
{
	glUseProgram(mRendererID);
}

void Shader::Unbind() const
{
	glUseProgram(0);
}

unsigned int Shader::GetUniformLocation(const std::string& Name) const
{
	const char* UniName = Name.c_str();//convert to c string
	return glGetUniformLocation(mRendererID, UniName);
}

unsigned int Shader::CompileShader(const std::string& Source, unsigned int type)
{
	unsigned int id = glCreateShader(type);//create shader
	const char* src = Source.c_str();//convert to c string
	GLCall(glShaderSource(id, 1, &src, nullptr));//fill source into the shader
	GLCall(glCompileShader(id));//compile shader

	//Error handling
	int success;
	char infoLog[512];
	GLCall(glGetShaderiv(id, GL_COMPILE_STATUS, &success));

	if (!success)
	{
		GLCall(glGetShaderInfoLog(id, 512, NULL, infoLog));
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" <<
			infoLog << std::endl;
	}

	return id;
}