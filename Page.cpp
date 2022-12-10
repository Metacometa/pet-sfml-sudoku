#include "Page.h"

Page::Page()
{
}

Page::~Page() {
	for (auto* i : interfaceComponents)
		delete i;
}
