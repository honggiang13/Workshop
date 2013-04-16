#pragma once
#include "../Utilities/utilities.h"
#include "Shaders.h"
class Pass {
public:
	GLint idFBO;
	GLuint vb,ib;
	GLint texttype;
	GLint idshader;
	Shaders* shader;
	int m_nrOtherData;
	float *m_pOtherData;
	void Draw();	
	void Init();
};