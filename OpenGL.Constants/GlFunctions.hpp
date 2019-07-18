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
}

#endif // !_GL_FUNCTIONS_HPP_

