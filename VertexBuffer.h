#pragma once
#include "Utils.h"

class VertexBuffer
{
private:
	unsigned int mRendererID;
public:
	VertexBuffer(const void* Data, unsigned int Size);
	~VertexBuffer();

	void Bind() const;
	void UnBind() const;
};