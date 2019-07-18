#pragma once
#ifndef _HELPER_HPP_
#define _HELPER_HPP_

// GetSystemMetrics function
// https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getsystemmetrics

// GetInputState function
// https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getinputstate

namespace OpenGL::Helper
{
    template<typename TColor, typename TParam>
    constexpr TColor NormalizeColor(const TParam &color);

    namespace Std
    {
        namespace Detail
        {
            template <class TObject, class TTuple, class TFunc, std::size_t... Ix>
            inline constexpr TObject MakeFromTupleWithInvokeImpl(TTuple&& Tpl, TFunc &&Func, std::index_sequence<Ix...>)
            {
                return TObject(Func(std::get<Ix>(std::forward<TTuple>(Tpl)))...);
            }
        }

        template <class TObject, class TTuple, class TFunc>
        [[nodiscard]] inline constexpr TObject MakeFromTupleWithInvoke(TTuple&& Tpl, TFunc &&Func)
        {
            return Detail::MakeFromTupleWithInvokeImpl<TObject>(
                std::forward<TTuple>(Tpl), Func,
                std::make_index_sequence<std::tuple_size_v<std::remove_reference_t<TTuple>>>{});
        }
    }
}

namespace OpenGL::Helper
{
    inline std::tuple<int32_t, int32_t> DesktopSize() noexcept
    {
        return std::make_tuple(::GetSystemMetrics(SM_CXSCREEN), ::GetSystemMetrics(SM_CYSCREEN));
    }

    inline std::tuple<int32_t, int32_t> GlutDesktopSize() noexcept
    {
        return std::make_tuple(::glutGet(GLUT_SCREEN_WIDTH), ::glutGet(GLUT_SCREEN_HEIGHT));
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

    // Get RGB color
    inline constexpr std::tuple<GLuint, GLuint, GLuint> Rgb(const COLORREF &color) noexcept
    {
        GLuint red   = (color >> 16) & 0xff;
        GLuint green = (color >>  8) & 0xff;
        GLuint blue  = (color      ) & 0xff;
        return std::make_tuple(red, green, blue);
    }

    template<typename TColor>
    inline constexpr std::tuple<TColor, TColor, TColor> GlRgb(const std::tuple<GLuint, GLuint, GLuint> &rgb)
    {
        return Std::MakeFromTupleWithInvoke<std::tuple<TColor, TColor, TColor>>(rgb, [](const GLuint &value)
        {
            return NormalizeColor<TColor>(value);
        });
    }

    // Get ARGB color
    inline constexpr std::tuple<GLuint, GLuint, GLuint, GLuint> Argb(const COLORREF &color) noexcept
    {
        GLuint alpha = (color >> 24) & 0xff;
        GLuint red   = (color >> 16) & 0xff;
        GLuint green = (color >>  8) & 0xff;
        GLuint blue  = (color      ) & 0xff;
        return std::make_tuple(alpha, red, green, blue);
    }

    template<typename TColor>
    inline constexpr std::tuple<TColor, TColor, TColor, TColor> GlArgb(const std::tuple<GLuint, GLuint, GLuint, GLuint> &argb)
    {
        return Std::MakeFromTupleWithInvoke<std::tuple<TColor, TColor, TColor, TColor>>(argb, [](const GLuint &value)
        {
            return NormalizeColor<TColor>(value);
        });
    }

    template<typename TColor, typename TParam>
    inline constexpr TColor NormalizeColor(const TParam &color) { return color / static_cast<TColor>(255); }

    inline constexpr GLdouble Red(const GLdouble &red) noexcept { return NormalizeColor<GLdouble>(red); }

    inline constexpr GLdouble Green(const GLdouble &green) noexcept { return NormalizeColor<GLdouble>(green); }

    inline constexpr GLdouble Blue(const GLdouble &blue) noexcept { return NormalizeColor<GLdouble>(blue); }

    inline constexpr GLdouble Alpha(const GLdouble &alpha) noexcept { return NormalizeColor<GLdouble>(alpha); }

    inline constexpr GLdouble X(const GLdouble &x) noexcept { return x; }

    inline constexpr GLdouble Y(const GLdouble &y) noexcept { return y; }

    inline constexpr GLdouble Z(const GLdouble &z) noexcept { return z; }

    inline constexpr GLdouble W(const GLdouble &w) noexcept { return w; }

    inline constexpr GLdouble Left(const GLdouble &left) noexcept { return left; }

    inline constexpr GLdouble Right(const GLdouble &right) noexcept { return right; }

    inline constexpr GLdouble Bottom(const GLdouble &bottom) noexcept { return bottom; }

    inline constexpr GLdouble Top(const GLdouble &top) noexcept { return top; }

    inline constexpr GLdouble Near(const GLdouble &zNear) noexcept { return zNear; }

    inline constexpr GLdouble Far(const GLdouble &zFar) noexcept { return zFar; }

    // https://www.juegosdelogica.com/index.php/numero-pi
    inline constexpr GLdouble PI = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132823066470938446095505822317253594081284811174502841027019385211055596446229489549303819644288109756659334461284756482337867831652712019091456485669234603486104543266482133936072602491412737245870066063155881748815209209628292540917153643678925903600113305305488204665213841469519415116094330572703657595919530921861173819326117931051185480744623799627495673518857527248912279381830119491298336733624406566430860213949463952247371907021798609437027705392171762931767523846748184676694051320005681271452635608277857713427577896091736371787214684409012249534301465495853710507922796892589235420199561121290219608640344181598136297747713099605187072113499999983729780499510597317328160963185950244594553469083026425223082533446850352619311881710100031378387528865875332083814206171776691473035982534904287554687311595628638823537875937519577818577805321712268066130019278766111959092164201989;
}

#endif // !_HELPER_HPP_

