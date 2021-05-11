#include "GameObject.h"

GameObject::GameObject() {
  id = nextId;
  nextId++;
  m_vecComponents.push_back(
      std::make_unique<ComponentAIDummy>(weak_from_this()));
  m_vecComponents.push_back(
      std::make_unique<ComponentPhysicsDummy>(weak_from_this()));
  m_vecComponents.push_back(
      std::make_unique<ComponentCollisionDummy>(weak_from_this()));
  m_vecComponents.push_back(
      std::make_unique<ComponentAIDummy>(weak_from_this()));
  m_vecComponents.push_back(
      std::make_unique<ComponentPhysicsDummy>(weak_from_this()));
  m_vecComponents.push_back(
      std::make_unique<ComponentCollisionDummy>(weak_from_this()));
};

void GameObject::Update() {
  for (auto& comp : m_vecComponents) comp->Update();
}
