//
// Created by anan on 2026/6/9.
//

#include <stdexcept>
#include <vector3.h>

NP_BEGIN

const vector3 vector3::AXIS_X = vector3{ 1, 0, 0 };
const vector3 vector3::AXIS_Y = vector3{ 0, 1, 0 };
const vector3 vector3::AXIS_Z = vector3{ 0, 0, 1 };

vector3::vector3(double x, double y, double z) : x(x), y(y), z(z) { }

vector3 vector3::identity() { return vector3{ 0, 0, 0 }; }

NP_END