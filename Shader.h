#pragma once
#include "Utils.h"
class Shader
{
public:
	Shader(const std::string vFile, const std::string fFile);
	~Shader();

	void Bind() const;
	void Unbind() const;

	unsigned int GetUniformLocation(const std::string& Name) const;

private:
	unsigned int CompileShader(const std::string& Source, unsigned int type);

	unsigned int mRendererID;
	
};

