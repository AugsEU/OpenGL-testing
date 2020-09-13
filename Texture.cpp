#include "Texture.h"

Texture::Texture(const std::string Path) :
	mFilePath(Path), mWidth(0), mHeight(0), mBPP(0),
	mLocalBuffer(nullptr), mRendererID(0)
{
	//Load texture
	stbi_set_flip_vertically_on_load(1);
	mLocalBuffer = stbi_load(Path.c_str(), &mWidth, &mHeight, &mBPP, 4);

	GLCall(glGenTextures(1, &mRendererID));
	GLCall(glBindTexture(GL_TEXTURE_2D, mRendererID));

	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));

	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT));
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT));

	GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, mWidth, mHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, mLocalBuffer));
	GLCall(glBindTexture(GL_TEXTURE_2D, 0));

	if (mLocalBuffer)
	{
		stbi_image_free(mLocalBuffer);
	}

}

Texture::~Texture()
{
	GLCall(glDeleteTextures(1, &mRendererID));
}

void Texture::Bind(unsigned int slot) const
{
	GLCall(glActiveTexture(GL_TEXTURE0 + slot));
	GLCall(glBindTexture(GL_TEXTURE_2D, mRendererID));

}

void Texture::Unbind() const
{
	GLCall(glBindTexture(GL_TEXTURE_2D, 0));
}
