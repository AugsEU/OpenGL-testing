#pragma once
#include "Utils.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"

class Renderer
{
public:
	void Clear() const;
	void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
private:

};