#pragma once
#ifndef _GL_FUNCTIONS_HPP_
#define _GL_FUNCTIONS_HPP_
#include <Windows.h>
#include <glut.h>

namespace OpengGL
{
	// The glLoadIdentity function replaces the current matrix with the identity matrix.
	inline void __stdcall LoadIdentity()
	{
		::glLoadIdentity();
	}
}

#endif // !_GL_FUNCTIONS_HPP_

