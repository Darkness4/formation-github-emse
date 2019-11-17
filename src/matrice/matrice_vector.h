#pragma once
#include <vector>
#include "matrice.h"

class MatriceVector : public Matrice {
 private:
  std::vector<std::vector<double>> _table;

 public:
  MatriceVector(size_t nbLignes = 0, size_t nbColonnes = 0);
  virtual void set(size_t x, size_t y, double value) override;
  virtual double get(size_t x, size_t y) const override;
  friend std::ostream& operator<<(std::ostream& stream, const MatriceVector& m);
  friend MatriceVector operator+(const MatriceVector& m1,
                                 const MatriceVector& m2);
  friend MatriceVector operator*(const MatriceVector& m1,
                                 const MatriceVector& m2);
  MatriceVector& operator+=(const MatriceVector& m);
};