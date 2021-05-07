#pragma once

class Object {
 protected:
  static int nextId;
  int id = 0;

 public:
  virtual ~Object() = default;
  virtual void Update() = 0;
};