#pragma once

#include <memory>

class Object : public std::enable_shared_from_this<Object> {
 protected:
  static int nextId;
  int id = 0;

 public:
  virtual ~Object() = default;
  virtual void Update() = 0;
};