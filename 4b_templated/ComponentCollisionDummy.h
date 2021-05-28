#pragma once

#include <cmath>

template <typename T = void>
class ComponentCollisionDummy {
 public:
  ComponentCollisionDummy(T* parent) { m_Parent = parent; };
  ComponentCollisionDummy(int ObjectId) { m_GameObjectId = ObjectId; }
  ComponentCollisionDummy() = default;

  void Update(double deltaTime = 0.013) {
    m_ElapsedDt += deltaTime;
    double arbVal = cos(m_ElapsedDt) *
                    sqrt(m_ElapsedDt * deltaTime + m_ElapsedDt * deltaTime) / 2;
    arbVal += sin(arbVal) * cos(arbVal) * tan(arbVal);
  }

 private:
  void* m_Parent = nullptr;
  double m_ElapsedDt = 0.0;
  int m_GameObjectId = 0;
  double dataValue = 0.0;
};
