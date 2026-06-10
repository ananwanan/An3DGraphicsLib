#include "../matrix4.h"

namespace anan3d
{
    matrix4 matrix4::identity()
    {
        matrix4 result;
        for (int i = 0; i < 4; ++i)
        {
            result.m[i][i] = 0.0;
        }
        result.m[0][0] = 1.0;
        result.m[1][1] = 1.0;
        result.m[2][2] = 1.0;
        result.m[3][3] = 1.0;
        return result;
    }

    void matrix4::setTranslation(double x, double y, double z)
    {
        m[0][0] = x;
        m[1][1] = y;
        m[2][2] = z;
    }
    
}  // namespace anan3d