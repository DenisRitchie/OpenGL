#pragma once
#ifndef _GL_ORTHO_HPP_
#define _GL_ORTHO_HPP_

// https://docs.microsoft.com/en-us/windows/win32/opengl/glortho

#pragma push_macro("near")
#pragma push_macro("far")

#undef near
#undef far

namespace OpenGL
{
	// The glOrtho function describes a perspective matrix that produces a parallel projection. 
	// The (left, bottom, near) and (right, top, near) parameters specify the points on the near clipping plane that are mapped to the lower-left and upper-right corners of the window, respectively, assuming that the eye is located at (0, 0, 0). 
	// The far parameter specifies the location of the far clipping plane. 
	// Both zNear and zFar can be either positive or negative. 
	// The corresponding matrix is shown in the following image.
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

			// The coordinates for the left vertical clipping plane.
			inline constexpr Cube& Left(const GLdouble& left) noexcept
			{
				this->left = left;
				return *this;
			}

			// The coordinates for theright vertical clipping plane.
			inline constexpr Cube& Right(const GLdouble& right) noexcept
			{
				this->right = right;
				return *this;
			}

			// The coordinates for the bottom horizontal clipping plane.
			inline constexpr Cube& Bottom(const GLdouble& bottom) noexcept
			{
				this->bottom = bottom;
				return *this;
			}

			// The coordinates for the top horizontal clipping plans.
			inline constexpr Cube& Top(const GLdouble& top) noexcept
			{
				this->top = top;
				return *this;
			}

			// The distances to the nearer depth clipping plane. 
			// This distance is negative if the plane is to be behind the viewer.
			inline constexpr Cube& Near(const GLdouble& near) noexcept
			{
				this->zNear = near;
				return *this;
			}

			// The distances to the farther depth clipping plane. 
			// This distance is negative if the plane is to be behind the viewer.
			inline constexpr Cube& Far(const GLdouble& far) noexcept
			{
				this->zFar = far;
				return *this;
			}

			// Invokes glOrtho
			inline void Call()
			{
				::glOrtho(left, right, bottom, top, zNear, zFar);
			}
		};

	public:
		// The coordinates for the left vertical clipping plane.
		static inline constexpr Cube Left(const GLdouble& left) noexcept
		{
			return { left, 0, 0, 0, 0, 0 };
		}

		// The coordinates for theright vertical clipping plane.
		static inline constexpr Cube Right(const GLdouble& right) noexcept
		{
			return { 0, right, 0, 0, 0, 0 };
		}

		// The coordinates for the bottom horizontal clipping plane.
		static inline constexpr Cube Bottom(const GLdouble& bottom) noexcept
		{
			return { 0, 0, bottom, 0, 0, 0 };
		}

		// The coordinates for the top horizontal clipping plans.
		static inline constexpr Cube Top(const GLdouble& top) noexcept
		{
			return { 0, 0, 0, top, 0, 0 };
		}

		// The distances to the nearer depth clipping plane. 
		// This distance is negative if the plane is to be behind the viewer.
		static inline constexpr Cube Near(const GLdouble& near) noexcept
		{
			return { 0, 0, 0, 0, near, 0 };
		}

		// The distances to the farther depth clipping plane. 
		// This distance is negative if the plane is to be behind the viewer.
		static inline constexpr Cube Far(const GLdouble& far) noexcept
		{
			return { 0, 0, 0, 0, 0, far };
		}
	};
}

#pragma pop_macro("near")
#pragma pop_macro("far")

#endif // !_GL_ORTHO_HPP_
