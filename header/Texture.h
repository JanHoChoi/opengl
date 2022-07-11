#pragma once

#ifndef TEXTURE_H
#define TEXTURE_H

#include <glad/glad.h>

class Texture
{
public:
	Texture(const char* resPath, unsigned int format);
	~Texture();

	unsigned int textureID;

private:
	int width;
	int height;
	int nrChannels;
	unsigned char* data;
};

#endif
