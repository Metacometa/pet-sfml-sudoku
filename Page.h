#pragma once
#include "Button.h"

class Page {
	std::vector<InterfaceComponent*> interfaceComponents;
public:
	//Constructor / Destructor
	Page();
	virtual ~Page();
};

