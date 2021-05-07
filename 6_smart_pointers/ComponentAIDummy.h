#pragma once

#include "Component.h"

class ComponentAIDummy : public Component {
 public:
  ComponentAIDummy(Object* parent) { m_Parent = parent; };
  ComponentAIDummy(int ObjectId) { m_GameObjectId = ObjectId; }
  ComponentAIDummy() = default;
  ~ComponentAIDummy() override = default;

  void Update(double deltaTime = 0.0013) override;
};