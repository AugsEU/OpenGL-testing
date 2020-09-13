#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(const void* Data, unsigned int Size)
{
	glGenBuffers(1, &mRendererID);
	glBindBuffer(GL_ARRAY_BUFFER, mRendererID);
	glBufferData(GL_ARRAY_BUFFER, Size, Data, GL_STATIC_DRAW);//Put data in buffer
}

VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &mRendererID);
}

void VertexBuffer::Bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, mRendererID);
}

void VertexBuffer::UnBind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}