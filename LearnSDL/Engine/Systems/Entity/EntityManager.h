#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <unordered_map>
#include <vector>
#include <string>
#include <cmath>
#include <string>

// External Libraries
#include <SDL.h>

// GLM

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

// Engines systems
#include "../Engine/Systems/Entity/Entity.h"

// Utilities
#include "../Engine/Utilities/Enum/BoxCollision.h"


class Entity;

using EntityType = std::string;

class EntityManager
{
public:
	EntityManager();
	int CreateEntity(glm::vec3 position);

	void RegisterEntity(EntityType type, int uniqueId, Entity* entity);
	BoxCollision CalculateDirectionalCollisions(int UniqueId);


	Entity* GetEntity(int uniqueId);

private:
	std::unordered_map<EntityType, std::vector<Entity*>> allEntitiesUnderType;
	//std::unordered_map<int, std::vector<Entity*>> allEntitiesUnderId;
	std::unordered_map<int, Entity*> allEntitiesUnderId;
	int uniqueId = 0;
};

#endif