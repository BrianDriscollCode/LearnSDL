#ifndef REGULARBOX_H
#define REGULARBOX_H

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

#include "../Engine/Utilities/Helper/ReferenceHelper.h"
#include "../Engine/Entity/Entity.h"

class RegularBox
{
public:
	RegularBox();
	Entity entity;

	void Tick();

	void DrawSelf();

};


#endif