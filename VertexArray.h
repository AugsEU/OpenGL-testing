#pragma once
#include "Utils.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

class VertexArray
{
public:
	VertexArray();
	~VertexArray();

	void AddBuffer(const VertexBuffer& VB, const VertexBufferLayout& Layout);

	void Bind() const;
	void Unbind() const;
private:
	unsigned int mRendererID;
};

