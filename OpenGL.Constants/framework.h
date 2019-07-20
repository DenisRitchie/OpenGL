#pragma once

// Excluir material rara vez utilizado de encabezados de Windows
#define WIN32_LEAN_AND_MEAN             

#include <Windows.h>
#include <tchar.h>
#include <Glut.h>

#include <stdint.h>
#include <math.h>

#include <tuple>
#include <array>
#include <string_view>
#include <memory>
#include <vector>
#include <functional>
#include <utility>

#include "Helper.hpp"
#include "GlFunctions.hpp"
#include "GlBegin.hpp"
#include "GlGetError.hpp"
#include "GlClearColor.hpp"
#include "GlClear.hpp"
#include "GlMatrixMode.hpp"
#include "GlOrtho.hpp"
#include "Glut.hpp"
