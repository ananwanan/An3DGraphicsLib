#include <iostream>
#include <matrix4.h>

using namespace anan3d;

int main(int, char**)
{
  const matrix4 matrix = matrix4::identity();
  matrix.debug();

  return 0;
}
