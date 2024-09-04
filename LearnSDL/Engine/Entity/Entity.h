#ifndef ENTITY_H
#define ENTITY_H

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

class Entity
{
public:
	glm::vec3 position;

	Entity();


	void MoveEntity();
	//void update(float deltaTime);
};

#endif