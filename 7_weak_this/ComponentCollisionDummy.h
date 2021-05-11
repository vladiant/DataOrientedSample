#pragma once

#include <memory>

#include "Component.h"

class ComponentCollisionDummy : public Component {
 public:
  ComponentCollisionDummy(std::weak_ptr<Object> parent) { m_Parent = parent; };
  ComponentCollisionDummy(int ObjectId) { m_GameObjectId = ObjectId; }
  ComponentCollisionDummy() = default;
  ~ComponentCollisionDummy() override = default;

  void Update(double deltaTime = 0.013) override;
};
