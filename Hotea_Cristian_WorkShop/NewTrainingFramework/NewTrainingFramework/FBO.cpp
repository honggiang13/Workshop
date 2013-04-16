#include <stdafx.h>
#include "FBO.h"
#include "../Utilities/memDbg.h"
#include "Globals.h"
FBO::~FBO() {

}
void FBO::Init() {
	glGenFramebuffers(1,&hFBO);
	glBindFramebuffer(GL_FRAMEBUFFER, hFBO);
	
	glGenTextures(1,&htexColor);
	glBindTexture(GL_TEXTURE_2D, htexColor);
	
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, Globals::screenWidth, Globals::screenHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,GL_TEXTURE_2D, htexColor, 0);
	
	glBindTexture(GL_TEXTURE_2D, 0);
	glGenTextures(1,&htexDepth);
	glBindTexture(GL_TEXTURE_2D, htexDepth);
	
	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, Globals::screenWidth, Globals::screenHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT,GL_TEXTURE_2D, htexDepth, 0);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	
	glBindTexture(GL_TEXTURE_2D,0);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}