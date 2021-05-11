#pragma once

#include <memory>
#include <vector>

#include "ComponentAIDummy.h"
#include "ComponentCollisionDummy.h"
#include "ComponentPhysicsDummy.h"
#include "Object.h"

class GameObject : public Object {
  std::vector<std::unique_ptr<Component>> m_vecComponents;

 public:
  GameObject();

  ~GameObject() override = default;

  void Update() override;

  int GetId() { return id; }
};
