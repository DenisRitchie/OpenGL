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

            // The red value that glClear uses to clear the color buffers. The default value is zero.
            inline constexpr Color& Red(const GLuint& red) noexcept
            {
                this->red = static_cast<GLclampf>(Helper::Red(red));
                return *this;
            }

            // The green value that glClear uses to clear the color buffers. The default value is zero.
            inline constexpr Color& Green(const GLclampf& green) noexcept
            {
                this->green = green;
                return *this;
            }

            // The green value that glClear uses to clear the color buffers. The default value is zero.
            inline constexpr Color& Green(const GLuint& green) noexcept
            {
                this->green = static_cast<GLclampf>(Helper::Green(green));
                return *this;
            }

            // The blue value that glClear uses to clear the color buffers. The default value is zero.
            inline constexpr Color& Blue(const GLclampf& blue) noexcept
            {
                this->blue = blue;
                return *this;
            }

            // The blue value that glClear uses to clear the color buffers. The default value is zero.
            inline constexpr Color& Blue(const GLuint& blue) noexcept
            {
                this->blue = static_cast<GLclampf>(Helper::Blue(blue));
                return *this;
            }

            // The alpha value that glClear uses to clear the color buffers. The default value is zero.
            inline constexpr Color& Alpha(const GLclampf& alpha) noexcept
            {
                this->alpha = alpha;
                return *this;
            }

            // The alpha value that glClear uses to clear the color buffers. The default value is zero.
            inline constexpr Color& Alpha(const GLuint& alpha) noexcept
            {
                this->alpha = static_cast<GLclampf>(Helper::Alpha(alpha));
                return *this;
            }

            // Invokes glClearColor
            inline void Call()
            {
                ::glClearColor(red, green, blue, alpha);
            }
        };

    public:
        // The rgb value that glClear uses to clear the color buffers. The default value is zero.
        static inline void Rgb(const COLORREF &color) noexcept
        {
            using Helper::Rgb, Helper::GlRgb;
            const auto &[red, green, blue] = GlRgb<GLclampf>(Rgb(color));
            ::glClearColor(red, green, blue, 1);
        }

        // The argb value that glClear uses to clear the color buffers. The default value is zero.
        static inline void Argb(const COLORREF &color) noexcept
        {
            using Helper::Argb, Helper::GlArgb;
            const auto &[alpha, red, green, blue] = GlArgb<GLclampf>(Argb(color));
            ::glClearColor(red, green, blue, alpha);
        }

        // The black value that glClear uses to clear the color buffers. The default value is zero.
        static inline void Black() noexcept
        {
            ::glClearColor(0, 0, 0, 1);
        }

        // The white value that glClear uses to clear the color buffers. The default value is zero.
        static inline void White() noexcept
        {
            ::glClearColor(1, 1, 1, 1);
        }

        // The red value that glClear uses to clear the color buffers. The default value is zero.
        static inline constexpr Color Red(const GLclampf& red) noexcept
        {
            return { red, 0, 0, 0 };
        }

        // The red value that glClear uses to clear the color buffers. The default value is zero.
        static inline constexpr Color Red(const GLuint& red) noexcept
        {
            return Red(static_cast<GLclampf>(Helper::Red(red)));
        }

        // The green value that glClear uses to clear the color buffers. The default value is zero.
        static inline constexpr Color Green(const GLclampf& green) noexcept
        {
            return { 0, green, 0, 0 };
        }

        // The green value that glClear uses to clear the color buffers. The default value is zero.
        static inline constexpr Color Green(const GLuint& green) noexcept
        {
            return Green(static_cast<GLclampf>(Helper::Green(green)));
        }

        // The blue value that glClear uses to clear the color buffers. The default value is zero.
        static inline constexpr Color Blue(const GLclampf& blue) noexcept
        {
            return { 0, 0, blue, 0 };
        }

        // The blue value that glClear uses to clear the color buffers. The default value is zero.
        static inline constexpr Color Blue(const GLuint& blue) noexcept
        {
            return Blue(static_cast<GLclampf>(Helper::Blue(blue)));
        }

        // The alpha value that glClear uses to clear the color buffers. The default value is zero.
        static inline constexpr Color Alpha(const GLclampf& alpha) noexcept
        {
            return { 0, 0, 0, alpha };
        }

        // The alpha value that glClear uses to clear the color buffers. The default value is zero.
        static inline constexpr Color Alpha(const GLuint& alpha) noexcept
        {
            return Alpha(static_cast<GLclampf>(Helper::Alpha(alpha)));
        }
    };
}

#endif // !_GL_CLEAR_COLOR_HPP_

