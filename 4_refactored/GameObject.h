#pragma once

#include <vector>

#include "ComponentAIDummy.h"
#include "ComponentCollisionDummy.h"
#include "ComponentPhysicsDummy.h"
#include "Object.h"

class GameObject : protected Object {
  std::vector<Component*> m_vecComponents = {};

 public:
  GameObject() {
    id = nextId;
    nextId++;
    m_vecComponents.push_back(new ComponentAIDummy(this));
    m_vecComponents.push_back(new ComponentPhysicsDummy(this));
    m_vecComponents.push_back(new ComponentCollisionDummy(this));
    m_vecComponents.push_back(new ComponentAIDummy(this));
    m_vecComponents.push_back(new ComponentPhysicsDummy(this));
    m_vecComponents.push_back(new ComponentCollisionDummy(this));
  };
  
  ~GameObject() override {
    for (auto& comp : m_vecComponents) delete comp;
  };

  void Update() override {
    for (auto& comp : m_vecComponents) comp->Update();
  }

  int GetId() { return id; }
};
