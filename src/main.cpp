#include <iostream>
#include "matrice/matrice_pointer.h"
#include "matrice/matrice_vector.h"

void testVector();
void testPointer();

int main() {
  testVector();
  testPointer();
  return 0;
}

void testVector() {
  std::cout << "MatriceVector" << std::endl;
  MatriceVector matrice1(3, 2);
  std::cout << "Size: (" << matrice1.size().x << ", " << matrice1.size().y
            << ")" << std::endl;
  matrice1.set(0, 0, 1.0);
  matrice1.set(1, 1, 1.0);
  std::cout << matrice1;
  std::cout << "M[1, 1]:" << matrice1.get(1, 1) << std::endl;
  MatriceVector matrice2(2, 3);
  matrice2.set(0, 0, 1.0);
  matrice2.set(1, 1, 1.0);
  std::cout << matrice2;
  try {
    MatriceVector matrice3 = matrice1 + matrice2;
    std::cout << matrice3;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  try {
    MatriceVector matrice4 = matrice1 * matrice2;
    std::cout << matrice4;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  matrice1 = matrice2;
}

void testPointer() {
  std::cout << "MatricePointer" << std::endl;
  MatricePointer matrice1(3, 2);
  std::cout << "Size: (" << matrice1.size().x << ", " << matrice1.size().y
            << ")" << std::endl;
  matrice1.set(0, 0, 1.0);
  matrice1.set(1, 1, 1.0);
  std::cout << matrice1;
  std::cout << "M[1, 1]:" << matrice1.get(1, 1) << std::endl;
  MatricePointer matrice2(2, 3);
  matrice2.set(0, 0, 1.0);
  matrice2.set(1, 1, 1.0);
  std::cout << matrice2;
  try {
    MatricePointer matrice3 = matrice1 + matrice2;
    std::cout << matrice3;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  try {
    MatricePointer matrice4 = matrice1 * matrice2;
    std::cout << matrice4;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  matrice1 = matrice2;
}