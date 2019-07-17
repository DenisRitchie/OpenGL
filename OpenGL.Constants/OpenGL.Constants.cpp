// OpenGL.Constants.cpp : Define las funciones de la biblioteca estática.
//

#include "pch.h"
#include "framework.h"

using namespace OpenGL;

void Test_GlBegin()
{
    constexpr BeginMode begin_mode = BeginMode::Lines;
    constexpr GLenum const_value = begin_mode;
}

void Test_GlGetError()
{
    constexpr ErrorCode error_code = ErrorCode::OutOfMemory;
    constexpr GLenum const_value = error_code;
}

