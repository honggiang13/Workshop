#include <stdafx.h>
#include "Effects.h"
#include "EM.h"
#include "../Utilities/memDbg.h"
void Effects::Draw() {
	
	for(int i=0;i<m_nrPasses;i++) {
		glBindFramebuffer(GL_FRAMEBUFFER,0);
		m_pPass[i].Draw();
		
	}
}