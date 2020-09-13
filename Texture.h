#pragma once
#include "Utils.h"
#include "Lib/stb_image.h"

class Texture
{
public:
	Texture(const std::string Path);
	~Texture();

	void Bind(unsigned int slot = 0) const;
	void Unbind() const;

	inline int GetWidth() const { return mWidth; }
	inline int GetHeight() const { return mHeight; }
private:
	unsigned int mRendererID;
	std::string mFilePath;
	unsigned char* mLocalBuffer;
	int mWidth, mHeight, mBPP;
};

