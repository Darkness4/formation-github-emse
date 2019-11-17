#include "matrice_pointer.h"
#include <iostream>

MatricePointer::MatricePointer(size_t nbLignes, size_t nbColonnes)
    : Matrice(nbLignes, nbColonnes) {
  _table = new double*[nbLignes];
  for (size_t x = 0; x < nbLignes; x++) {
    _table[x] = new double[nbColonnes];
    for (size_t y = 0; y < nbLignes; y++) {
      _table[x][y] = 0;
    }
  }
}

MatricePointer::~MatricePointer() {
  for (size_t x = 0; x < _size.x; x++) {
    delete[] _table[x];
  }
  delete[] _table;
}

MatricePointer::MatricePointer(const MatricePointer& m) : Matrice(m) {
  _table = new double*[_size.x];
  for (size_t x = 0; x < _size.x; x++) {
    _table[x] = new double[_size.y];
    for (size_t y = 0; y < _size.y; y++) {
      _table[x][y] = m._table[x][y];
    }
  }
}

MatricePointer& MatricePointer::operator=(const MatricePointer& m) {
  if (this != &m) {
    for (size_t x = 0; x < _size.x; x++) {
      delete[] _table[x];
    }
    delete[] _table;

    _size.x = m._size.x;
    _size.y = m._size.y;

    _table = new double*[_size.x];
    for (size_t x = 0; x < _size.x; x++) {
      _table[x] = new double[_size.y];
      for (size_t y = 0; y < _size.y; y++) {
        _table[x][y] = m._table[x][y];
      }
    }
  }
  return *this;
}

MatricePointer& MatricePointer::operator+=(const MatricePointer& m) {
  *this = *this + m;
  return *this;
}

void MatricePointer::set(size_t x, size_t y, double value) {
  if (x < _size.x && y < _size.y) {
    _table[x][y] = value;
    return;
  }

  throw OutOfRangeException();
}

double MatricePointer::get(size_t x, size_t y) const {
  if (x < _size.x && y < _size.y) {
    return _table[x][y];
  }

  throw OutOfRangeException();
}

std::ostream& operator<<(std::ostream& stream, const MatricePointer& m) {
  stream << "[ " << std::endl;
  for (size_t i = 0; i < m._size.x; i++) {
    stream << "{ ";
    for (size_t j = 0; j < m._size.y; j++) {
      stream << m._table[i][j] << ",\t";
    }
    stream << "} " << std::endl;
  }
  stream << "]" << std::endl;
  return stream;
}

MatricePointer operator+(const MatricePointer& m1, const MatricePointer& m2) {
  if (m1._size.x != m2._size.x || m1._size.y != m2._size.y) {
    throw IncompatibleSizeException();
  }

  Size size = m1._size;
  MatricePointer newMatrice(size.x, size.y);

  for (size_t i = 0; i < size.x; i++) {
    for (size_t j = 0; j < size.y; j++) {
      newMatrice._table[i][j] = m1._table[i][j] + m2._table[i][j];
    }
  }

  return newMatrice;
}

MatricePointer operator*(const MatricePointer& m1, const MatricePointer& m2) {
  if (m1._size.y != m2._size.x) {
    throw IncompatibleSizeException();
  }

  Size size({.x = m1._size.x, .y = m2._size.y});
  size_t n = m1._size.y;
  MatricePointer newMatrice(size.x, size.y);

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