#pragma once
#ifndef _HELPER_HPP_
#define _HELPER_HPP_

// GetSystemMetrics function
// https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getsystemmetrics

// GetInputState function
// https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getinputstate

namespace OpenGL::Helper
{
    inline std::tuple<int32_t, int32_t> DesktopSize() noexcept
    {
        return std::make_tuple(::GetSystemMetrics(SM_CXSCREEN), ::GetSystemMetrics(SM_CYSCREEN));
    }

    inline constexpr std::tuple<int32_t, int32_t> CenteredCoordinates(const int32_t width, const int32_t height, const int32_t x, const int32_t y) noexcept
    {
        return std::make_tuple((width >> 1) - (x >> 1), (height >> 1) - (y >> 1));
    }

    inline constexpr std::tuple<int32_t, int32_t> CenteredCoordinates(const std::tuple<int32_t, int32_t> &size, const int32_t x, const int32_t y) noexcept
    {
        const auto &[width, height] = size;
        return CenteredCoordinates(width, height, x, y);
    }

    inline constexpr std::tuple<int32_t, int32_t> CenteredCoordinates(const std::tuple<int32_t, int32_t> &size, const std::tuple<int32_t, int32_t> &coord) noexcept
    {
        const auto &[x, y] = coord;
        const auto &[width, height] = size;
        return CenteredCoordinates(width, height, x, y);
    }

    inline constexpr GLdouble Red(const GLdouble &red) noexcept
    {
        return red / 255.0;
    }

    inline constexpr GLdouble Green(const GLdouble &green) noexcept
    {
        return green / 255.0;
    }

    inline constexpr GLdouble Blue(const GLdouble &blue) noexcept
    {
        return blue / 255.0;
    }

    inline constexpr GLdouble Alpha(const GLdouble &alpha) noexcept
    {
        return alpha / 255.0;
    }

    inline constexpr GLdouble X(const GLdouble &x) noexcept
    {
        return x;
    }

    inline constexpr GLdouble Y(const GLdouble &y) noexcept
    {
        return y;
    }

    inline constexpr GLdouble Z(const GLdouble &z) noexcept
    {
        return z;
    }

    inline constexpr GLdouble W(const GLdouble &w) noexcept
    {
        return w;
    }
}

#endif // !_HELPER_HPP_

