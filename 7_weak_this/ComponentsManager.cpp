#include "ComponentsManager.h"

ComponentsManager::ComponentsManager(int numEntities)
    : maxEntities(numEntities) {
  arrPhysicsComps.resize(maxEntities);
  arrAIComps.resize(maxEntities);
  arrCollisionComps.resize(maxEntities);

  arrPhysicsComps2.resize(maxEntities);
  arrAIComps2.resize(maxEntities);
  arrCollisionComps2.resize(maxEntities);
};

void ComponentsManager::CreateComponentsForId(int id) {
  if (maxId < id) maxId = id;

  arrPhysicsComps[id] = ComponentPhysicsDummy(id);
  arrAIComps[id] = ComponentAIDummy(id);
  arrCollisionComps[id] = ComponentCollisionDummy(id);

  arrPhysicsComps2[id] = ComponentPhysicsDummy(id);
  arrAIComps2[id] = ComponentAIDummy(id);
  arrCollisionComps2[id] = ComponentCollisionDummy(id);
}

void ComponentsManager::Update() {
  for (int i = 0; i < maxId; i++) {
    arrAIComps[i].Update();
    arrPhysicsComps[i].Update();
    arrCollisionComps[i].Update();
    arrAIComps2[i].Update();
    arrPhysicsComps2[i].Update();
    arrCollisionComps2[i].Update();
  }
}