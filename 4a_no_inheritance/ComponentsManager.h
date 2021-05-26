#pragma once

#include "ComponentAIDummy.h"
#include "ComponentCollisionDummy.h"
#include "ComponentPhysicsDummy.h"

class ComponentsManager {
  int maxEntities = 0;
  int maxId = 0;
  ComponentPhysicsDummy* arrPhysicsComps = nullptr;
  ComponentAIDummy* arrAIComps = nullptr;
  ComponentCollisionDummy* arrCollisionComps = nullptr;

  ComponentPhysicsDummy* arrPhysicsComps2 = nullptr;
  ComponentAIDummy* arrAIComps2 = nullptr;
  ComponentCollisionDummy* arrCollisionComps2 = nullptr;

 public:
  ComponentsManager(int numEntities) : maxEntities(numEntities) {
    arrPhysicsComps = new ComponentPhysicsDummy[maxEntities];
    arrAIComps = new ComponentAIDummy[maxEntities];
    arrCollisionComps = new ComponentCollisionDummy[maxEntities];

    arrPhysicsComps2 = new ComponentPhysicsDummy[maxEntities];
    arrAIComps2 = new ComponentAIDummy[maxEntities];
    arrCollisionComps2 = new ComponentCollisionDummy[maxEntities];
  };

  ~ComponentsManager() {
    delete[] arrPhysicsComps;
    delete[] arrAIComps;
    delete[] arrCollisionComps;

    delete[] arrPhysicsComps2;
    delete[] arrAIComps2;
    delete[] arrCollisionComps2;
  }

  void CreateComponentsForId(int id) {
    if (maxId < id) maxId = id;

    arrPhysicsComps[id] = ComponentPhysicsDummy(id);
    arrAIComps[id] = ComponentAIDummy(id);
    arrCollisionComps[id] = ComponentCollisionDummy(id);

    arrPhysicsComps2[id] = ComponentPhysicsDummy(id);
    arrAIComps2[id] = ComponentAIDummy(id);
    arrCollisionComps2[id] = ComponentCollisionDummy(id);
  }

  void Update() {
    for (int i = 0; i < maxId; i++) {
      arrAIComps[i].Update();
      arrPhysicsComps[i].Update();
      arrCollisionComps[i].Update();
      arrAIComps2[i].Update();
      arrPhysicsComps2[i].Update();
      arrCollisionComps2[i].Update();
    }
  }
};