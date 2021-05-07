#include "GameObject.h"

GameObject::GameObject() {
  id = nextId;
  nextId++;
  m_vecComponents.push_back(std::make_shared<ComponentAIDummy>(this));
  m_vecComponents.push_back(std::make_shared<ComponentPhysicsDummy>(this));
  m_vecComponents.push_back(std::make_shared<ComponentCollisionDummy>(this));
  m_vecComponents.push_back(std::make_shared<ComponentAIDummy>(this));
  m_vecComponents.push_back(std::make_shared<ComponentPhysicsDummy>(this));
  m_vecComponents.push_back(std::make_shared<ComponentCollisionDummy>(this));
};

void GameObject::Update() {
  for (auto& comp : m_vecComponents) comp->Update();
}
