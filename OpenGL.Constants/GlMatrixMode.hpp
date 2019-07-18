#pragma once
#ifndef _GL_MATRIX_MODE_HPP_
#define _GL_MATRIX_MODE_HPP_

// https://docs.microsoft.com/en-us/windows/win32/opengl/glmatrixmode

namespace OpenGL
{
    // The glMatrixMode function specifies which matrix is the current matrix.
    // Mode: The matrix stack that is the target for subsequent matrix operations. 
    // The mode parameter can assume one of three values.
    inline void __stdcall SetMatrixMode(const GLenum mode)
    {
        ::glMatrixMode(mode);
    }

    // The primitive or primitives that will be create from vertices presented between glBegin and the
    // subsequent glEnd. The following are accepted symbolic constants and their meanings.
    class MatrixMode
    {
    private:
        GLenum value;

    public:
        inline constexpr MatrixMode(const GLenum &value = 0) noexcept : value{ value } { }
        inline constexpr operator const GLenum&() const noexcept { return value; }
        using Type = GLenum;

        enum : GLenum
        {
            // Applies subsequent matrix operations to the modelview matrix stack.
            ModelView = GL_MODELVIEW,

            // Applies subsequent matrix operations to the projection matrix stack.
            Projection = GL_PROJECTION,

            // Applies subsequent matrix operations to the texture matrix stack.
            Texture = GL_TEXTURE,
        };
    };
}

#endif // !_GL_MATRIX_MODE_HPP_


