#include "matrice_vector.h"
#include <iostream>

MatriceVector::MatriceVector(size_t nbLignes, size_t nbColonnes)
    : Matrice(nbLignes, nbColonnes) {
  _table.resize(nbLignes);
  for (size_t i = 0; i < nbLignes; ++i) {
    _table[i].resize(nbColonnes);
  }
}

MatriceVector& MatriceVector::operator+=(const MatriceVector& m) {
  *this = *this + m;
  return *this;
}

void MatriceVector::set(size_t x, size_t y, double value) {
  if (x < _size.x && y < _size.y) {
    _table[x][y] = value;
    return;
  }

  throw OutOfRangeException();
}

double MatriceVector::get(size_t x, size_t y) const {
  if (x < _size.x && y < _size.y) {
    return _table[x][y];
  }

  throw OutOfRangeException();
}

std::ostream& operator<<(std::ostream& stream, const MatriceVector& m) {
  stream << "[ " << std::endl;
  for (std::vector<double> line : m._table) {
    stream << "{ ";
    for (double& data : line) {
      stream << data << ",\t";
    }
    stream << "} " << std::endl;
  }
  stream << "]" << std::endl;
  return stream;
}

MatriceVector operator+(const MatriceVector& m1, const MatriceVector& m2) {
  if (m1._size.x != m2._size.x || m1._size.y != m2._size.y) {
    throw IncompatibleSizeException();
  }

  Size size = m1._size;
  MatriceVector newMatrice(size.x, size.y);

  for (size_t i = 0; i < size.x; i++) {
    for (size_t j = 0; j < size.y; j++) {
      newMatrice._table[i][j] = m1._table[i][j] + m2._table[i][j];
    }
  }

  return newMatrice;
}

MatriceVector operator*(const MatriceVector& m1, const MatriceVector& m2) {
  if (m1._size.y != m2._size.x) {
    throw IncompatibleSizeException();
  }

  Size size({.x = m1._size.x, .y = m2._size.y});
  auto n = m1._size.y;
  MatriceVector newMatrice(size.x, size.y);

  // Ligne par ligne
  for (size_t i = 0; i < size.x; i++) {
    for (size_t j = 0; j < size.y; j++) {
      newMatrice._table[i][j] = 0;
      for (size_t k = 0; k < n; k++) {
        newMatrice._table[i][j] += m1._table[i][k] * m2._table[k][j];
      }
    }
  }

  return newMatrice;
}