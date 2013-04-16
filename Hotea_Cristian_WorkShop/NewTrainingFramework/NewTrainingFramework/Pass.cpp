#include <stdafx.h>
#include "Pass.h"
#include "EM.h"
#include "Shaders.h"
#include "Vertex.h"
#include "../Utilities/memDbg.h"
void Pass::Draw() {
	glUseProgram(shader->program);
	glBindBuffer(GL_ARRAY_BUFFER, EManager::GetInstance()->vb);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EManager::GetInstance()->ib);
	if(shader->a_posNLoc != -1) {
		glEnableVertexAttribArray(shader->a_posNLoc);
		glVertexAttribPointer(shader->a_posNLoc, 3, GL_FLOAT,GL_FALSE,sizeof(Vertex),0 );
	
	}
	if(shader->a_uvLoc != -1) {
		glEnableVertexAttribArray(shader->a_uvLoc);
		glVertexAttribPointer(shader->a_uvLoc, 2, GL_FLOAT,GL_FALSE,sizeof(Vertex),(GLvoid *)(4*sizeof(Vector3)));
	
	}
	if(shader->u_texColor1Loc != -1) {
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, EManager::GetInstance()->m_pFBO[0].htexColor);
		glUniform1i(shader->u_texColor1Loc, 0);
	
	}
	
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);	
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindTexture(GL_TEXTURE_2D,0);
}
