#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(x) GLClearError(); x; ASSERT(GLErrors(#x, __FILE__, __LINE__));

static void GLClearError()
{
	while (glGetError() != GL_NO_ERROR);
}

static bool GLErrors(const char* func, const char* file, int line)
{
	if (GLenum MyError = glGetError())
	{
		std::cout << "GL ERROR:" << MyError << " with " << func << " at " << line << " in " << file << std::endl;
		return false;
	}
	return true;
}

static std::string ReadFile(const std::string Path)
{
	std::ifstream t(Path);
	std::stringstream buffer;
	buffer << t.rdbuf();
	return buffer.str();
}

static std::vector<std::string> SplitBySpaces(const std::string& str)
{
	std::string buf;                 // Have a buffer string
	std::stringstream ss(str);       // Insert the string into a stream

	std::vector<std::string> tokens; // Create vector to hold our words

	while (ss >> buf)
		tokens.push_back(buf);

	return tokens;
}