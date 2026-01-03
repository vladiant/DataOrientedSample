#pragma once

#include <vector>

#include "ComponentAIDummy.h"
#include "ComponentCollisionDummy.h"
#include "ComponentPhysicsDummy.h"
#include "Object.h"

class GameObject : protected Object {
  std::vector<void*> m_vecComponents = {};

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
    for (size_t i = 0; i < m_vecComponents.size();) {
      delete static_cast<ComponentAIDummy<>*>(m_vecComponents[i++]);
      delete static_cast<ComponentPhysicsDummy<>*>(m_vecComponents[i++]);
      delete static_cast<ComponentCollisionDummy<>*>(m_vecComponents[i++]);
      delete static_cast<ComponentAIDummy<>*>(m_vecComponents[i++]);
      delete static_cast<ComponentPhysicsDummy<>*>(m_vecComponents[i++]);
      delete static_cast<ComponentCollisionDummy<>*>(m_vecComponents[i++]);
    }
  };

  void Update() override {
    for (size_t i = 0; i < m_vecComponents.size();) {
      static_cast<ComponentAIDummy<>*>(m_vecComponents[i++])->Update();
      static_cast<ComponentPhysicsDummy<>*>(m_vecComponents[i++])->Update();
      static_cast<ComponentCollisionDummy<>*>(m_vecComponents[i++])->Update();
      static_cast<ComponentAIDummy<>*>(m_vecComponents[i++])->Update();
      static_cast<ComponentPhysicsDummy<>*>(m_vecComponents[i++])->Update();
      static_cast<ComponentCollisionDummy<>*>(m_vecComponents[i++])->Update();
    }
  }

  int GetId() { return id; }
};
