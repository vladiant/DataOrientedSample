#include "ComponentAIDummy.h"

#include <cmath>

void ComponentAIDummy::Update(double deltaTime) {
  m_ElapsedDt += deltaTime;
  double arbVal = cos(m_ElapsedDt) *
                  sqrt(m_ElapsedDt * deltaTime + m_ElapsedDt * deltaTime) / 2;
  arbVal += sin(arbVal) * cos(arbVal) * tan(arbVal);
}
