#pragma once
#ifndef _MAIN_HPP_
#define _MAIN_HPP_
#include <framework.h>

using namespace OpenGL;
using namespace OpenGL::Helper;
using namespace Glut;

std::tuple<int, int, int, int> GetBound(const int &width, const int &height)
{
    const auto &desktop_size = DesktopSize();
    const auto &window_coord = CenteredCoordinates(desktop_size, width, height);
    return std::tuple_cat(window_coord, std::make_tuple(width, height));
}

#endif // !_MAIN_HPP_

