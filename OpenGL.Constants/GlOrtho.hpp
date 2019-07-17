#pragma once
#ifndef _GL_ORTHO_HPP_
#define _GL_ORTHO_HPP_

#pragma push_macro("near")
#pragma push_macro("far")

#undef near
#undef far

namespace OpenGL
{
	class Ortho sealed abstract
	{
	private:
		class Cube
		{
		private:
			GLdouble left, right, bottom, top, zNear, zFar;

		public:
			inline constexpr Cube(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar) noexcept
				: left{ left }, right{ right }, bottom{ bottom }, top{ top }, zNear{ zNear }, zFar{ zFar }
			{
			}

			inline constexpr Cube& Left(const GLdouble& left) noexcept
			{
				this->left = left;
				return *this;
			}

			inline constexpr Cube& Right(const GLdouble& right) noexcept
			{
				this->right = right;
				return *this;
			}

			inline constexpr Cube& Bottom(const GLdouble& bottom) noexcept
			{
				this->bottom = bottom;
				return *this;
			}

			inline constexpr Cube& Top(const GLdouble& top) noexcept
			{
				this->top = top;
				return *this;
			}

			inline constexpr Cube& Near(const GLdouble& near) noexcept
			{
				this->zNear = near;
				return *this;
			}

			inline constexpr Cube& Far(const GLdouble& far) noexcept
			{
				this->zFar = far;
				return *this;
			}

			inline void Call()
			{
				::glOrtho(left, right, bottom, top, zNear, zFar);
			}
		};

	public:
		static inline void Black() noexcept
		{
			::glClearColor(0, 0, 0, 0);
		}

		static inline constexpr Cube Left(const GLdouble& left) noexcept
		{
			return { left, 0, 0, 0, 0, 0 };
		}

		static inline constexpr Cube Right(const GLdouble& right) noexcept
		{
			return { 0, right, 0, 0, 0, 0 };
		}

		static inline constexpr Cube Bottom(const GLdouble& bottom) noexcept
		{
			return { 0, 0, bottom, 0, 0, 0 };
		}

		static inline constexpr Cube Top(const GLdouble& top) noexcept
		{
			return { 0, 0, 0, top, 0, 0 };
		}

		static inline constexpr Cube Near(const GLdouble& near) noexcept
		{
			return { 0, 0, 0, 0, near, 0 };
		}

		static inline constexpr Cube Far(const GLdouble& far) noexcept
		{
			return { 0, 0, 0, 0, 0, far };
		}
	};
}

#pragma pop_macro("near")
#pragma pop_macro("far")

#endif // !_GL_ORTHO_HPP_
