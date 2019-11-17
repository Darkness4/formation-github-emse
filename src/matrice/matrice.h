#pragma once
#include "my_exceptions.h"

struct Size {
  size_t x;
  size_t y;
};

class Matrice {
 protected:
  Size _size;

 public:
  Matrice(size_t nbLignes = 0, size_t nbColonnes = 0) {
    _size.x = nbLignes;
    _size.y = nbColonnes;
  }
  virtual Size size() const { return _size; };
  virtual void set(size_t x, size_t y, double value) = 0;
  virtual double get(size_t x, size_t y) const = 0;
};