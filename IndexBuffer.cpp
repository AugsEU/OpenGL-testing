#include "IndexBuffer.h"

IndexBuffer::IndexBuffer(const unsigned int* Data, unsigned int Count) : mCount(Count)
{
	GLCall(glGenBuffers(1, &mRendererID));
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mRendererID));
	GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, Count * sizeof(unsigned int), Data, GL_STATIC_DRAW));//Put data in buffer
}

IndexBuffer::~IndexBuffer()
{
	GLCall(glDeleteBuffers(1, &mRendererID));
}

void IndexBuffer::Bind() const
{
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mRendererID));
}

void IndexBuffer::UnBind() const
{
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}