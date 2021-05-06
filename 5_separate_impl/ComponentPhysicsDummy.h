#pragma once

#include "Component.h"

class ComponentPhysicsDummy : public Component {
 public:
  ComponentPhysicsDummy(Object* parent) { m_Parent = parent; };
  ComponentPhysicsDummy(int ObjectId) { m_GameObjectId = ObjectId; }
  ComponentPhysicsDummy() = default;
  ~ComponentPhysicsDummy() override = default;

  void Update(double deltaTime = 0.0013) override;
};
