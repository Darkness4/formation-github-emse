#pragma once
#include "matrice.h"

class MatricePointer : public Matrice {
 private:
  double** _table;

 public:
  MatricePointer(size_t nbLignes = 0, size_t nbColonnes = 0);
  ~MatricePointer();
  MatricePointer(const MatricePointer&);
  virtual void set(size_t x, size_t y, double value) override;
  virtual double get(size_t x, size_t y) const override;
  friend std::ostream& operator<<(std::ostream& stream,
                                  const MatricePointer& m);
  friend MatricePointer operator+(const MatricePointer& m1,
                                  const MatricePointer& m2);
  friend MatricePointer operator*(const MatricePointer& m1,
                                  const MatricePointer& m2);
  MatricePointer& operator=(const MatricePointer& m);
  MatricePointer& operator+=(const MatricePointer& m);
};