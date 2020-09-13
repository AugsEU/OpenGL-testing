#pragma once
#include "Utils.h"

struct VertexBufferElement
{
	unsigned int type;
	unsigned int count;

	GLboolean normalized;

	static unsigned int GetSizeOfType(unsigned int Type)
	{
		switch (Type)
		{
		case GL_FLOAT:			return 4;
		case GL_UNSIGNED_INT:	return 4;
		case GL_UNSIGNED_BYTE:	return 1;
		}
		ASSERT(false);
		return 0;
	}
};

class VertexBufferLayout
{
public:
	VertexBufferLayout() {}

	template<typename T>
	void Push(unsigned int count)
	{
		static_assert(false);
	}

	template<>
	void Push<float>(unsigned int count)
	{
		mElements.push_back({ GL_FLOAT, count, false });
		mStride += VertexBufferElement::GetSizeOfType(GL_FLOAT) * count;
	}

	template<>
	void Push<unsigned int>(unsigned int count)
	{
		mElements.push_back({ GL_UNSIGNED_INT, count, false });
		mStride += VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT) * count;
	}

	template<>
	void Push<unsigned char>(unsigned int count)
	{
		mElements.push_back({ GL_UNSIGNED_BYTE, count, true });
		mStride += VertexBufferElement::GetSizeOfType(GL_UNSIGNED_BYTE) * count;
	}

	inline const std::vector<VertexBufferElement> GetElements() const { return mElements; }
	inline unsigned int GetStride() const { return mStride; }
private:
	std::vector< VertexBufferElement> mElements;
	unsigned int mStride;
};

