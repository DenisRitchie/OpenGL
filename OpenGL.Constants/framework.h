#pragma once

#define WIN32_LEAN_AND_MEAN             // Excluir material rara vez utilizado de encabezados de Windows

#include <Windows.h>
#include <Glut.h>

#include <stdint.h>

#include <tuple>
#include <array>
#include <string_view>
#include <memory>
#include <vector>

#include "Helper.hpp"
#include "GlFunctions.hpp"
#include "GlBegin.hpp"
#include "GlGetError.hpp"
#include "GlClearColor.hpp"
#include "GlClear.hpp"
#include "GlMatrixMode.hpp"
#include "GlOrtho.hpp"
#include "Glut.hpp"
