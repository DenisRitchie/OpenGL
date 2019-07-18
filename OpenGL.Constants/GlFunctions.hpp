#pragma once
#ifndef _GL_FUNCTIONS_HPP_
#define _GL_FUNCTIONS_HPP_

namespace OpenGL
{
    // The glLoadIdentity function replaces the current matrix with the identity matrix.
    // https://docs.microsoft.com/en-us/windows/win32/opengl/glloadidentity
    inline void __stdcall LoadIdentity()
    {
        ::glLoadIdentity();
    }

    inline void __stdcall HexColor3d(const GLuint red, const GLuint green, const GLuint blue)
    {
        using namespace Helper;
        glColor3d(Red(red), Green(green), Blue(blue));
    }

    inline void __stdcall HexColor(const COLORREF color)
    {
        using namespace Helper;
        glColor3d(Blue(GetBValue(color)), Green(GetGValue(color)), Red(GetRValue(color)));
    }
}

#endif // !_GL_FUNCTIONS_HPP_

