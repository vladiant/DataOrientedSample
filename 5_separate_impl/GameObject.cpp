#include "GameObject.h"

GameObject::GameObject() {
  id = nextId;
  nextId++;
  m_vecComponents.push_back(new ComponentAIDummy(this));
  m_vecComponents.push_back(new ComponentPhysicsDummy(this));
  m_vecComponents.push_back(new ComponentCollisionDummy(this));
  m_vecComponents.push_back(new ComponentAIDummy(this));
  m_vecComponents.push_back(new ComponentPhysicsDummy(this));
  m_vecComponents.push_back(new ComponentCollisionDummy(this));
};

GameObject::~GameObject() {
  for (auto& comp : m_vecComponents) delete comp;
};

void GameObject::Update() {
  for (auto& comp : m_vecComponents) comp->Update();
}
