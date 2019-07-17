#pragma once
#ifndef _HELPER_HPP_
#define _HELPER_HPP_

// GetSystemMetrics function
// https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getsystemmetrics

// GetInputState function
// https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getinputstate

#include <tuple>

namespace OpenGL::Helper
{
	inline std::tuple<int, int> DesktopSize()
	{
		return std::make_tuple(::GetSystemMetrics(SM_CXSCREEN), ::GetSystemMetrics(SM_CYSCREEN));
	}

	inline std::tuple<int, int> CenteredCoordinates(int width, int height, int x, int y)
	{
		return std::make_tuple((width >> 1) - (x >> 1), (height >> 1) - (y >> 1));
	}

	inline std::tuple<int, int> CenteredCoordinates(std::tuple<int, int> size, int x, int y)
	{
		auto &[width, height] = size;
		return CenteredCoordinates(width, height, x, y);
	}

	inline std::tuple<int, int> CenteredCoordinates(std::tuple<int, int> size, std::tuple<int, int> coord)
	{
		auto &[x, y] = coord;
		auto &[width, height] = size;
		return CenteredCoordinates(width, height, x, y);
	}
}

#endif // !_HELPER_HPP_

