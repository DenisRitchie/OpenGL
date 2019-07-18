#pragma once
#ifndef _GLUT_DISPLAY_MODE_HPP_
#define _GLUT_DISPLAY_MODE_HPP_

// https://www.opengl.org/resources/libraries/glut/spec3/node12.html

namespace Glut
{
    // The initial display mode is used when creating top-level windows, subwindows, and overlays to determine the OpenGL display mode for the to-be-created window or overlay.
    // Note that GLUT_RGBA selects the RGBA color model, but it does not request any bits of alpha (sometimes called an alpha buffer or destination alpha) be allocated. 
    // To request alpha, specify GLUT_ALPHA. 
    // The same applies to GLUT_LUMINANCE.
    class DisplayMode
    {
    private:
        uint32_t value;

    public:
        inline constexpr DisplayMode(const uint32_t &value = Rgba) noexcept : value{ value } { }
        inline constexpr operator const uint32_t&() const noexcept { return value; }
        using Type = uint32_t;

        enum : uint32_t
        {
            // An alias for GLUT_RGBA.
            Rgb = GLUT_RGB,

            // Bit mask to select an RGBA mode window. 
            // This is the default if neither GLUT_RGBA nor GLUT_INDEX are specified.
            Rgba = GLUT_RGBA,

            // Bit mask to select a color index mode window. 
            // This overrides GLUT_RGBA if it is also specified.
            Index = GLUT_INDEX,

            // Bit mask to select a single buffered window. 
            // This is the default if neither GLUT_DOUBLE or GLUT_SINGLE are specified.
            Single = GLUT_SINGLE,

            // Bit mask to select a double buffered window. 
            // This overrides GLUT_SINGLE if it is also specified.
            Double = GLUT_DOUBLE,

            // Bit mask to select a window with an accumulation buffer.
            Accum = GLUT_ACCUM,

            // Bit mask to select a window with an alpha component to the color buffer(s).
            Alpha = GLUT_ALPHA,

            // Bit mask to select a window with a depth buffer.
            Depth = GLUT_DEPTH,

            // Bit mask to select a window with a stencil buffer.
            Stencil = GLUT_STENCIL,

            // Bit mask to select a window with multisampling support. 
            // If multisampling is not available, a non-multisampling window will automatically be chosen. 
            // Note: both the OpenGL client-side and server-side implementations must support the GLX_SAMPLE_SGIS extension for multisampling to be available.
            MultiSample = GLUT_MULTISAMPLE,

            // Bit mask to select a stereo window.
            Stereo = GLUT_STEREO,

            // Bit mask to select a window with a ``luminance'' color model. 
            // This model provides the functionality of OpenGL's RGBA color model, but the green and blue components are not maintained in the frame buffer. 
            // Instead each pixel's red component is converted to an index between zero and glutGet(GLUT_WINDOW_COLORMAP_SIZE)-1 and looked up in a per-window color map to determine the color of pixels within the window. 
            // The initial colormap of GLUT_LUMINANCE windows is initialized to be a linear gray ramp, but can be modified with GLUT's colormap routines.
            // GLUT_LUMINANCE Implementation Notes:
            // GLUT_LUMINANCE is not supported on most OpenGL platforms.
            Luminance = GLUT_LUMINANCE,
        };
    };
}

#endif // !_GLUT_DISPLAY_MODE_HPP_
