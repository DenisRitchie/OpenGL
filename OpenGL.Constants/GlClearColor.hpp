#pragma once
#ifndef _GL_CLEAR_COLOR_HPP_
#define _GL_CLEAR_COLOR_HPP_

// https://docs.microsoft.com/en-us/windows/win32/opengl/glclearcolor

namespace OpenGL
{
    // The glClearColor function specifies clear values for the color buffers.
    // The glClearColor function specifies the red, green, blue, and alpha values used by glClear to clear the color buffers. Values specified by glClearColor are clamped to the range [0,1].
    // The following functions retrieve information related to the glClearColor function:
    // glGet with argument GL_ACCUM_CLEAR_VALUE
    // glGet with argument GL_COLOR_CLEAR_VALUE
    class ClearColor sealed abstract
    {
    private:
        class Color
        {
        private:
            GLclampf red, green, blue, alpha;

        public:
            inline constexpr Color(const GLclampf red, const GLclampf green, const GLclampf blue, const GLclampf alpha) noexcept
                : red{ red }, green{ green }, blue{ blue }, alpha{ alpha }
            {
            }

            // The red value that glClear uses to clear the color buffers. The default value is zero.
            inline constexpr Color& Red(const GLclampf& red) noexcept
            {
                this->red = red;
                return *this;
            }

            // The green value that glClear uses to clear the color buffers. The default value is zero.
            inline constexpr Color& Green(const GLclampf& green) noexcept
            {
                this->green = green;
                return *this;
            }

            // The blue value that glClear uses to clear the color buffers. The default value is zero.
            inline constexpr Color& Blue(const GLclampf& blue) noexcept
            {
                this->blue = blue;
                return *this;
            }

            // The alpha value that glClear uses to clear the color buffers. The default value is zero.
            inline constexpr Color& Alpha(const GLclampf& alpha) noexcept
            {
                this->alpha = alpha;
                return *this;
            }

            // Invokes glClearColor
            inline void Call()
            {
                ::glClearColor(red, green, blue, alpha);
            }
        };

    public:
        // The black value that glClear uses to clear the color buffers. The default value is zero.
        static inline void Black() noexcept
        {
            ::glClearColor(0, 0, 0, 0);
        }

        // The red value that glClear uses to clear the color buffers. The default value is zero.
        static inline constexpr Color Red(const GLclampf& red) noexcept
        {
            return { red, 0, 0, 0 };
        }

        // The green value that glClear uses to clear the color buffers. The default value is zero.
        static inline constexpr Color Green(const GLclampf& green) noexcept
        {
            return { 0, green, 0, 0 };
        }

        // The blue value that glClear uses to clear the color buffers. The default value is zero.
        static inline constexpr Color Blue(const GLclampf& blue) noexcept
        {
            return { 0, 0, blue, 0 };
        }

        // The alpha value that glClear uses to clear the color buffers. The default value is zero.
        static inline constexpr Color Alpha(const GLclampf& alpha) noexcept
        {
            return { 0, 0, 0, alpha };
        }
    };
}

#endif // !_GL_CLEAR_COLOR_HPP_

