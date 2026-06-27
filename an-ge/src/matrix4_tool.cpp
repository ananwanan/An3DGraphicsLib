#include <matrix4.h>

NP_BEGIN

matrix4 matrix4::identity()
{
  matrix4 result;
  // index = row * 4 + col
  result.m_data[0]  = 1.0;
  result.m_data[5]  = 1.0;
  result.m_data[10] = 1.0;
  result.m_data[15] = 1.0;
  return result;
}

NP_END