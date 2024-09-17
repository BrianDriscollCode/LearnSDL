
#include "CollisionHandler.h"


CollisionHandler::CollisionHandler() {}

void CollisionHandler::InitCollisionBox(float sizeXRef, float sizeYRef)
{
    sizeX = sizeXRef;
    sizeY = sizeYRef;
}

BoxCollision CollisionHandler::CalculateDirectionalCollisionX(std::unordered_map<int, Entity*>* allEntitiesUnderId, Entity* entity, int uniqueId)
{

    // Calculate boundaries of the current entity
    float entityLeft = entity->currentPosition.x - (sizeX / 2.0f);
    float entityRight = entity->currentPosition.x + (sizeX / 2.0f);
    float entityTop = entity->currentPosition.y + (sizeY / 2.0f);
    float entityBottom = entity->currentPosition.y - (sizeY / 2.0f);

    // Loop through all entities in level
    for (auto i = allEntitiesUnderId->begin(); i != allEntitiesUnderId->end(); i++)
    {
        Entity* entityComparator = i->second;
        int entityComparatorId = i->first;

        // If the entity is the same, skip
        if (uniqueId == entityComparatorId)
            continue;

        // Calculate boundaries of the comparator entity
        float entityComparatorLeft = entityComparator->currentPosition.x - (entityComparator->collisionBox.sizeX / 2.0f);
        float entityComparatorRight = entityComparator->currentPosition.x + (entityComparator->collisionBox.sizeX / 2.0f);
        float entityComparatorTop = entityComparator->currentPosition.y + (entityComparator->collisionBox.sizeY / 2.0f);
        float entityComparatorBottom = entityComparator->currentPosition.y - (entityComparator->collisionBox.sizeY / 2.0f);

        // Calculate collision with the precision of 0.001f
        const float epsilon = 0.001f; 
        bool rightCol = (entityRight >= entityComparatorLeft || fabs(entityRight - entityComparatorLeft) < epsilon);
        bool leftCol = (entityLeft <= entityComparatorRight || fabs(entityLeft - entityComparatorRight) < epsilon);
        bool topCol = (entityTop >= entityComparatorBottom || fabs(entityTop - entityComparatorBottom) < epsilon); 
        bool bottomCol = (entityBottom <= entityComparatorTop || fabs(entityBottom - entityComparatorTop) < epsilon); 

        // Check for overlap
        bool xOverlap = rightCol && leftCol;
        bool yOverlap = topCol && bottomCol;

        // If x and y axis overlap, then is colliding
        bool isColliding = xOverlap && yOverlap;

        // Get distances for x or y axis collision check (so both collisions don't active at same time for a single object)
        float currentDistanceX = (std::round(std::abs(entity->currentPosition.x - entityComparator->currentPosition.x) * 100) / 100);
        float currentDistanceY = (std::round(std::abs(entity->currentPosition.y - entityComparator->currentPosition.y) * 100) / 100);

        CollisionTypeSelector entityCollisionType = entity->collisionBox.collisionType;
        CollisionTypeSelector comparatorCollisionType = entityComparator->collisionBox.collisionType;

        // If both X and Y overlap, a collision has occurred
        if (xOverlap && yOverlap && comparatorCollisionType != CollisionTypeSelector::NONE && entityCollisionType != CollisionTypeSelector::NONE)
        {
            if (currentDistanceX > currentDistanceY)
            {
                // Further logic to determine collision direction
                if (entity->currentPosition.x < entityComparator->currentPosition.x)
                {
                    entity->currentPosition.x = std::min(entity->currentPosition.x, entityComparatorLeft - entity->size.x / 2.0f);
                    return RIGHT_COL;
                }
                else
                {
                    entity->currentPosition.x = std::max(entity->currentPosition.x, entityComparatorRight + entity->size.x / 2.0f);
                    return LEFT_COL;
                }
            }
        }
    }

    return NO_COL; // No collision
}

BoxCollision CollisionHandler::CalculateDirectionalCollisionY(std::unordered_map<int, Entity*>* allEntitiesUnderId, Entity* entity, int uniqueId)
{
    // Calculate boundaries of the current entity
    float entityLeft = entity->currentPosition.x - (sizeX / 2.0f);
    float entityRight = entity->currentPosition.x + (sizeX / 2.0f);
    float entityTop = entity->currentPosition.y + (sizeY / 2.0f);
    float entityBottom = entity->currentPosition.y - (sizeY / 2.0f);

    // Loop through all entities in level
    for (auto i = allEntitiesUnderId->begin(); i != allEntitiesUnderId->end(); i++)
    {
        Entity* entityComparator = i->second;
        int entityComparatorId = i->first;

        // If the entity is the same, skip
        if (uniqueId == entityComparatorId)
            continue;

        // Calculate boundaries of the comparator entity
        float entityComparatorLeft = entityComparator->currentPosition.x - (entityComparator->collisionBox.sizeX / 2.0f);
        float entityComparatorRight = entityComparator->currentPosition.x + (entityComparator->collisionBox.sizeX / 2.0f);
        float entityComparatorTop = entityComparator->currentPosition.y + (entityComparator->collisionBox.sizeY / 2.0f);
        float entityComparatorBottom = entityComparator->currentPosition.y - (entityComparator->collisionBox.sizeY / 2.0f);

        // Calculate collision with the precision of 0.001f
        const float epsilon = 0.001f;
        bool rightCol = (entityRight >= entityComparatorLeft || fabs(entityRight - entityComparatorLeft) < epsilon);
        bool leftCol = (entityLeft <= entityComparatorRight || fabs(entityLeft - entityComparatorRight) < epsilon);
        bool topCol = (entityTop >= entityComparatorBottom || fabs(entityTop - entityComparatorBottom) < epsilon); 
        bool bottomCol = (entityBottom <= entityComparatorTop || fabs(entityBottom - entityComparatorTop) < epsilon); 

        // Check for overlap
        bool xOverlap = rightCol && leftCol;
        bool yOverlap = topCol && bottomCol;

        // If x and y axis overlap, then is colliding
        bool isColliding = xOverlap && yOverlap;
       
        // Get distances for x or y axis collision check (so both collisions don't active at same time for a single object)
        float currentDistanceX = (std::round(std::abs(entity->currentPosition.x - entityComparator->currentPosition.x) * 100) / 100);
        float currentDistanceY = (std::round(std::abs(entity->currentPosition.y - entityComparator->currentPosition.y) * 100) / 100);

        CollisionTypeSelector entityCollisionType = entity->collisionBox.collisionType;
        CollisionTypeSelector comparatorCollisionType = entityComparator->collisionBox.collisionType;


        // If both X and Y overlap, a collision has occurred
        if (isColliding && comparatorCollisionType != CollisionTypeSelector::NONE && entityCollisionType != CollisionTypeSelector::NONE)
        {
            // Fixes tunneling edge case, instead of moving through when currentDistances are the same, 
            // we bias toward the y axis
            if (currentDistanceX == currentDistanceY)
            {
                currentDistanceY += 0.01f;
            }
            // Check if should be a top or bottom collision
            if (currentDistanceY > currentDistanceX)
            {
                // Further logic to determine collision direction
                if (entity->currentPosition.y < entityComparator->currentPosition.y)
                {
                    entity->currentPosition.y = std::min(entity->currentPosition.y,  entityComparatorBottom - entity->size.y / 2.0f);
                    return TOP_COL;
                }
                else
                {
                    entity->currentPosition.y = std::max(entity->currentPosition.y, entityComparatorTop + entity->size.y / 2.0f);
                    return BOTTOM_COL;
                }
            }
        }
    }

    return NO_COL; // No collision
}

bool CollisionHandler::TriggerCollision(std::unordered_map<int, Entity*>* allEntitiesUnderId, Entity* entity, int uniqueId)
{
    // Calculate boundaries of the current entity
    float entityLeft = entity->currentPosition.x - (sizeX / 2.0f);
    float entityRight = entity->currentPosition.x + (sizeX / 2.0f);
    float entityTop = entity->currentPosition.y + (sizeY / 2.0f);
    float entityBottom = entity->currentPosition.y - (sizeY / 2.0f);

    // Loop through all entities in level
    for (auto i = allEntitiesUnderId->begin(); i != allEntitiesUnderId->end(); i++)
    {
        Entity* entityComparator = i->second;
        int entityComparatorId = i->first;

        // If the entity is the same, skip
        if (uniqueId == entityComparatorId)
            continue;

        // Calculate boundaries of the comparator entity
        float entityComparatorLeft = entityComparator->currentPosition.x - (entityComparator->collisionBox.sizeX / 2.0f);
        float entityComparatorRight = entityComparator->currentPosition.x + (entityComparator->collisionBox.sizeX / 2.0f);
        float entityComparatorTop = entityComparator->currentPosition.y + (entityComparator->collisionBox.sizeY / 2.0f);
        float entityComparatorBottom = entityComparator->currentPosition.y - (entityComparator->collisionBox.sizeY / 2.0f);

        // check above code for ref comments if need explanation
        const float epsilon = 0.001f;
        bool rightCol = (entityRight >= entityComparatorLeft || fabs(entityRight - entityComparatorLeft) < epsilon);
        bool leftCol = (entityLeft <= entityComparatorRight || fabs(entityLeft - entityComparatorRight) < epsilon);
        bool topCol = (entityTop >= entityComparatorBottom || fabs(entityTop - entityComparatorBottom) < epsilon);
        bool bottomCol = (entityBottom <= entityComparatorTop || fabs(entityBottom - entityComparatorTop) < epsilon);

        bool xOverlap = rightCol && leftCol;
        bool yOverlap = topCol && bottomCol;

        bool isColliding = xOverlap && yOverlap;

        float currentDistanceX = (std::round(std::abs(entity->currentPosition.x - entityComparator->currentPosition.x) * 100) / 100);
        float currentDistanceY = (std::round(std::abs(entity->currentPosition.y - entityComparator->currentPosition.y) * 100) / 100);

        CollisionTypeSelector entityCollisionType = entity->collisionBox.collisionType;
        CollisionTypeSelector comparatorCollisionType = entityComparator->collisionBox.collisionType;

        // If both X and Y overlap, a collision has occurred
        if (isColliding && comparatorCollisionType != CollisionTypeSelector::NONE && entityCollisionType != CollisionTypeSelector::NONE)
        {
            return true;
        }
    }

    return false;
}