#pragma once
#include "../Utilities/utilities.h"
#include "Pass.h"
class Effects {
public:	
	int id;
	char name[100];
	int m_nrPasses;
	Pass *m_pPass;
	void Draw();
};