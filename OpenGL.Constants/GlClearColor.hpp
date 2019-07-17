#pragma once
#ifndef _GL_CLEAR_COLOR_HPP_
#define _GL_CLEAR_COLOR_HPP_

namespace OpenGL
{
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

            inline constexpr Color& Red(const GLclampf& red) noexcept
            {
                this->red = red;
                return *this;
            }

            inline constexpr Color& Green(const GLclampf& green) noexcept
            {
                this->green = green;
                return *this;
            }

            inline constexpr Color& Blue(const GLclampf& blue) noexcept
            {
                this->blue = blue;
                return *this;
            }

            inline constexpr Color& Alpha(const GLclampf& alpha) noexcept
            {
                this->alpha = alpha;
                return *this;
            }

            inline void Call()
            {
                ::glClearColor(red, green, blue, alpha);
            }
        };

    public:
        static inline void Black() noexcept
        {
            ::glClearColor(0, 0, 0, 0);
        }

        static inline constexpr Color Red(const GLclampf& red) noexcept
        {
            return { red, 0, 0, 0 };
        }

        static inline constexpr Color Green(const GLclampf& green) noexcept
        {
            return { 0, green, 0, 0 };
        }

        static inline constexpr Color Blue(const GLclampf& blue) noexcept
        {
            return { 0, 0, blue, 0 };
        }

        static inline constexpr Color Alpha(const GLclampf& alpha) noexcept
        {
            return { 0, 0, 0, alpha };
        }
    };
}

#endif // !_GL_CLEAR_COLOR_HPP_

