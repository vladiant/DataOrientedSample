#pragma once

#include <vector>

#include "ComponentAIDummy.h"
#include "ComponentCollisionDummy.h"
#include "ComponentPhysicsDummy.h"

class ComponentsManager {
  int maxEntities = 0;
  int maxId = 0;
  std::vector<ComponentPhysicsDummy> arrPhysicsComps;
  std::vector<ComponentAIDummy> arrAIComps;
  std::vector<ComponentCollisionDummy> arrCollisionComps;

  std::vector<ComponentPhysicsDummy> arrPhysicsComps2;
  std::vector<ComponentAIDummy> arrAIComps2;
  std::vector<ComponentCollisionDummy> arrCollisionComps2;

 public:
  ComponentsManager(int numEntities);

  void CreateComponentsForId(int id);

  void Update();
};