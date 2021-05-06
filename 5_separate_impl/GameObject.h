#pragma once
#include <vector>

#include "ComponentAIDummy.h"
#include "ComponentCollisionDummy.h"
#include "ComponentPhysicsDummy.h"
#include "Object.h"

class GameObject : protected Object {
  std::vector<Component*> m_vecComponents = {};

 public:
  GameObject();

  ~GameObject() override;

  void Update() override;

  int GetId() { return id; }
};
