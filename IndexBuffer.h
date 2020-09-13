#pragma once
#include "Utils.h"

class IndexBuffer
{
private:
	unsigned int mRendererID;
	unsigned int mCount;
public:
	IndexBuffer(const unsigned int* Data, unsigned int Count);
	~IndexBuffer();

	void Bind() const;
	void UnBind() const;

	inline unsigned int GetCount() const{ return mCount;}
};