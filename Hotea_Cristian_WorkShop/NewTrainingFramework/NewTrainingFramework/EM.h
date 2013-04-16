#pragma once
#include "../Utilities/utilities.h"
#include "Shaders.h"
#include "FBO.h"
#include "Effects.h" 
class EManager {
protected:
	EManager();
	~EManager();
	EManager(const EManager&);
	EManager& operator=(const EManager&);
	static EManager *ms_pEManager;
public:
	int m_nrShaders;
	Shaders *m_pShaders;
	int m_nrFBO;
	FBO *m_pFBO;
	int m_nreffects;
	Effects *m_pEffects;
	GLint hVBO;
	GLuint vb,ib;
	void Init();
	void Draw(short int);
	Shaders* GetShaderbyID(int ID);
	static EManager* GetInstance();
	static void DestroyInstance();
};