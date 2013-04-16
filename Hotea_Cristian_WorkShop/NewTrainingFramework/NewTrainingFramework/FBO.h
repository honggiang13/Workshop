#pragma once
#include "../Utilities/utilities.h"
class FBO {
public:
	GLuint hFBO, htexColor, htexDepth;
	void Init();
	~FBO();
	GLint GethTexColor();
	GLint GethTexDepth();
	GLint GethFBO();
};