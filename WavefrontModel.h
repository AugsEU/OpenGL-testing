#pragma once

#include "Utils.h"

#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"
#include "Renderer.h"

class WavefrontModel
{
public:
	WavefrontModel();
	~WavefrontModel();
	void LoadOBJ(const std::string& OBJPath);
	std::unique_ptr<VertexBuffer> mVB;
	std::unique_ptr<IndexBuffer> mIB;
};

