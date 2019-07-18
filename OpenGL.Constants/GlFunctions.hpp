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

    // https://developer.android.com/reference/android/graphics/Color.html
    inline void __stdcall ArgbColor(const COLORREF &color)
    {
        using namespace Helper;
        GLdouble alpha = (color >> 24) & 0xff;
        GLdouble red   = (color >> 16) & 0xff;
        GLdouble green = (color >>  8) & 0xff;
        GLdouble blue  = (color      ) & 0xff;
        glColor4d(Red(red), Green(green), Blue(blue), Alpha(alpha));
    }

    // https://developer.android.com/reference/android/graphics/Color.html
    inline void __stdcall RgbColor(const COLORREF &color)
    {
        using namespace Helper;
        GLdouble red   = (color >> 16) & 0xff;
        GLdouble green = (color >>  8) & 0xff;
        GLdouble blue  = (color      ) & 0xff;
        glColor3d(Red(red), Green(green), Blue(blue));
    }
}

#endif // !_GL_FUNCTIONS_HPP_

