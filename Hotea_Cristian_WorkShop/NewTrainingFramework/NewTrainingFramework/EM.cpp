#include <stdafx.h>
#include "EM.h"
#include "../Utilities/memDbg.h"
#include "FBO.h"
#include "cstring"
#include "Vertex.h"
EManager* EManager::ms_pEManager;
EManager* EManager::GetInstance()
{
	if(ms_pEManager == NULL) {
		ms_pEManager = new EManager();
	}
	return ms_pEManager;
}
void EManager::DestroyInstance() 
{
	if(ms_pEManager) {
		delete ms_pEManager;
		ms_pEManager = NULL;
	}
}
EManager::EManager() 
{

}
EManager::~EManager() 
{
	delete[] m_pShaders;
	delete[] m_pFBO;
	delete[] m_pEffects;
}
void EManager::Init(){
	FILE *f;
	errno_t err = fopen_s(&f,"../EM.txt","r");
	
	if(err)
		printf_s("nu s-a deschis\n");
	else {
		fscanf_s( f, "#SHADERS\nNRSHADERS %d\n",&m_nrShaders);
		m_pShaders = new Shaders[m_nrShaders];
	
		for(int i = 0 ; i < m_nrShaders ; i++) {
			fscanf_s( f, "ID %d\n",&m_pShaders[i].id);
			fscanf_s( f, "FILE %s\n",m_pShaders[i].fileVS,260);
			fscanf_s( f, "FILE %s\n",m_pShaders[i].fileFS,260);
			m_pShaders[i].Init();
		}
		
		fscanf_s( f, "#FBO\nNRFBO %d\n",&m_nrFBO);
		m_pFBO = new FBO[m_nrFBO];
	
		for(int i = 0 ; i < m_nrFBO ; i++)
			m_pFBO[i].Init();
		
		fscanf_s( f, "#EFFECTS\nNREFFECTS %d\n",&m_nreffects);
		m_pEffects = new Effects[m_nreffects];

		for(int i = 0 ; i < m_nreffects ; i++) {
			fscanf_s( f, "ID %d\nNRPASSES %d\nNAME %s\n",&m_pEffects[i].id,&m_pEffects[i].m_nrPasses,m_pEffects[i].name,100);
			m_pEffects[i].m_pPass = new Pass[m_pEffects[i].m_nrPasses];
			
			for(int j = 0 ; j < m_pEffects[j].m_nrPasses ; j++) {
				fscanf_s( f, "IDPASS %*d\nTARGETFB %d\n", &m_pEffects[i].m_pPass[j].idFBO);
				fscanf_s( f, "TEXTURES %d\n", &m_pEffects[i].m_pPass[j].texttype);
				fscanf_s(f, "SHADERID %d\n",&m_pEffects[i].m_pPass[j].idshader);
			
				m_pEffects[i].m_pPass[j].shader = EManager::GetInstance()->GetShaderbyID(m_pEffects[i].m_pPass[j].idshader);
				
			}
			
		}
		fclose(f);
	}
	Vertex v[4];
	v[0].pos = Vector3(0,0,0);
	v[1].pos = Vector3(1,0,0);
	v[2].pos = Vector3(1,1,0);
	v[3].pos = Vector3(0,1,0);
	
	v[0].uv = Vector2(0,0);
	v[1].uv = Vector2(1,0);
	v[2].uv = Vector2(1,1);
	v[3].uv = Vector2(0,1);
	
	GLuint i[6] = {0,1,2,2,0,3};
	
	glGenBuffers(1,&vb);
	glBindBuffer(GL_ARRAY_BUFFER, vb);
	glBufferData(GL_ARRAY_BUFFER, 4*sizeof(Vertex), v, GL_STATIC_DRAW);

	glGenBuffers(1,&ib);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ib);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6*sizeof(GLuint), i, GL_STATIC_DRAW);
	
}
void EManager::Draw(short int effectpressed) {
	glDisable(GL_DEPTH_TEST);
	EManager::m_pEffects[0].Draw();
	glEnable(GL_DEPTH_TEST);

}
Shaders* EManager::GetShaderbyID(int ID) {

	for(int i = 0 ; i < m_nrShaders ; i++)
		if(m_pShaders[i].id == ID) {
			
			return &m_pShaders[i];
		}
	return NULL;
}