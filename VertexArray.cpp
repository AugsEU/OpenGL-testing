#include "VertexArray.h"

VertexArray::VertexArray()
{
	GLCall(glGenVertexArrays(1, &mRendererID));
}

VertexArray::~VertexArray()
{
	GLCall(glDeleteVertexArrays(1, &mRendererID));
}

void VertexArray::AddBuffer(const VertexBuffer& VB, const VertexBufferLayout& Layout)
{
	VB.Bind();
	Bind();
	const auto& Elements = Layout.GetElements();
	unsigned int offset = 0;
	for (size_t i = 0; i < Elements.size(); i++)
	{
		const auto& Element = Elements[i];
		GLCall(glEnableVertexAttribArray(i));
		GLCall(glVertexAttribPointer(i, Element.count, Element.type, Element.normalized, Layout.GetStride(), (const void*)offset));
		offset += Element.count * VertexBufferElement::GetSizeOfType(Element.type);
	}
	
}

void VertexArray::Bind() const
{
	GLCall(glBindVertexArray(mRendererID));
}

void VertexArray::Unbind() const
{
	GLCall(glBindVertexArray(0));
}
