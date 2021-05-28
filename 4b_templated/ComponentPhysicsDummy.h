#pragma once

#include <cmath>

template <typename T = void>
class ComponentPhysicsDummy {
 public:
  ComponentPhysicsDummy(T* parent) { m_Parent = parent; };
  ComponentPhysicsDummy(int ObjectId) { m_GameObjectId = ObjectId; }
  ComponentPhysicsDummy() = default;

  void Update(double deltaTime = 0.0013) {
    m_ElapsedDt += deltaTime;
    double arbVal = cos(m_ElapsedDt) *
                    sqrt(m_ElapsedDt * deltaTime + m_ElapsedDt * deltaTime) / 2;
    arbVal += sin(arbVal) * cos(arbVal) * tan(arbVal);
  }

 private:
  T* m_Parent = nullptr;
  double m_ElapsedDt = 0.0;
  int m_GameObjectId = 0;
  double dataValue = 0.0;
};
