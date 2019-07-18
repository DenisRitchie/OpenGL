#pragma once
#ifndef _GL_CLEAR_HPP_
#define _GL_CLEAR_HPP_

// https://docs.microsoft.com/en-us/windows/win32/opengl/glclear

namespace OpenGL
{
    // he glClear function sets the bitplane area of the window to values previously selected by glClearColor, glClearIndex, glClearDepth, glClearStencil, and glClearAccum. 
    // You can clear multiple color buffers simultaneously by selecting more than one buffer at a time using glDrawBuffer.
    // The pixel - ownership test, the scissor test, dithering, and the buffer writemasks affect the operation of glClear.
    // The scissor box bounds the cleared region.
    // The glClear function ignores the alpha function, blend function, logical operation, stenciling, texture mapping, and z - buffering.
    // The glClear function takes a single argument(mask) that is the bitwise OR of several values indicating which buffer is to be cleared.
    // The value to which each buffer is cleared depends on the setting of the clear value for that buffer.
    // If a buffer is not present, a glClear call directed at that buffer has no effect.
    // The following functions retrieve information related to glClear:
    // glGet with argument GL_ACCUM_CLEAR_VALUE
    // glGet with argument GL_DEPTH_CLEAR_VALUE
    // glGet with argument GL_INDEX_CLEAR_VALUE
    // glGet with argument GL_COLOR_CLEAR_VALUE
    // glGet with argument GL_STENCIL_CLEAR_VALUE
    inline void __stdcall Clear(const GLbitfield mask)
    {
        ::glClear(mask);
    }

    // Bitwise OR operators of masks that indicate the buffers to be cleared. The four masks are as follows.
    class ClearMask
    {
    private:
        GLbitfield value;

    public:
        inline constexpr ClearMask(const GLbitfield &value = ColorBufferBit) noexcept : value{ value } { }
        inline constexpr operator const GLbitfield&() const noexcept { return value; }
        using Type = GLbitfield;

        enum : GLbitfield
        {
            // The depth buffer.
            DepthBufferBit = GL_DEPTH_BUFFER_BIT,

            // The accumulation buffer.
            AccumBufferBit = GL_ACCUM_BUFFER_BIT,

            // The stencil buffer.
            StencilBufferBit = GL_STENCIL_BUFFER_BIT,

            // The buffers currently enabled for color writing.
            ColorBufferBit = GL_COLOR_BUFFER_BIT,
        };
    };
}

#endif // !_GL_CLEAR_HPP_
