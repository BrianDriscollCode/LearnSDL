
#include "CollisionBox.h"


CollisionBox::CollisionBox() {}

void CollisionBox::InitCollisionBox(float sizeXRef, float sizeYRef)
{
    sizeX = sizeXRef;
    sizeY = sizeYRef;
}

BoxCollision CollisionBox::CalculateDirectionalCollisionX(std::unordered_map<int, Entity*>* allEntitiesUnderId, Entity* entity, int uniqueId)
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
        float entityComparatorLeft = entityComparator->currentPosition.x - (entityComparator->size.x / 2.0f);
        float entityComparatorRight = entityComparator->currentPosition.x + (entityComparator->size.x / 2.0f);
        float entityComparatorTop = entityComparator->currentPosition.y + (entityComparator->size.y / 2.0f);
        float entityComparatorBottom = entityComparator->currentPosition.y - (entityComparator->size.y / 2.0f);

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

        // If both X and Y overlap, a collision has occurred
        if (xOverlap && yOverlap)
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

BoxCollision CollisionBox::CalculateDirectionalCollisionY(std::unordered_map<int, Entity*>* allEntitiesUnderId, Entity* entity, int uniqueId)
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
        float entityComparatorLeft = entityComparator->currentPosition.x - (entityComparator->size.x / 2.0f);
        float entityComparatorRight = entityComparator->currentPosition.x + (entityComparator->size.x / 2.0f);
        float entityComparatorTop = entityComparator->currentPosition.y + (entityComparator->size.y / 2.0f);
        float entityComparatorBottom = entityComparator->currentPosition.y - (entityComparator->size.y / 2.0f);

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

        // If both X and Y overlap, a collision has occurred
        if (isColliding)
        {
            if (currentDistanceY > currentDistanceX) 
            {
                // Further logic to determine collision direction
                if (entity->currentPosition.y < entityComparator->currentPosition.y)
                {
                    entity->currentPosition.y = std::min(entity->currentPosition.y, entityComparatorTop - entity->size.y / 2.0f);
                    return TOP_COL;
                }
                else
                {
                    entity->currentPosition.y = std::max(entity->currentPosition.y, entityComparatorBottom + entity->size.y / 2.0f);
                    return BOTTOM_COL;
                }
            }
        }
    }

    return NO_COL; // No collision
}

bool CollisionBox::TriggerCollision(std::unordered_map<int, Entity*>* allEntitiesUnderId, Entity* entity, int uniqueId)
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
        float entityComparatorLeft = entityComparator->currentPosition.x - (entityComparator->size.x / 2.0f);
        float entityComparatorRight = entityComparator->currentPosition.x + (entityComparator->size.x / 2.0f);
        float entityComparatorTop = entityComparator->currentPosition.y + (entityComparator->size.y / 2.0f);
        float entityComparatorBottom = entityComparator->currentPosition.y - (entityComparator->size.y / 2.0f);

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

        // If both X and Y overlap, a collision has occurred
        if (isColliding)
        {
            return true;
        }
    }

    return false;
}