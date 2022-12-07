#pragma once
#include "Button.h"

class Screen {
	Button* buttons;
public:
	int k;
	//Constructor / Destructor
	Screen();
	Screen(int lol);
	virtual ~Screen();
};

