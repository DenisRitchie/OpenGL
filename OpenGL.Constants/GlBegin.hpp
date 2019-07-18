#pragma once
#ifndef _GL_BEGIN_HPP_
#define _GL_BEGIN_HPP_

// https://docs.microsoft.com/en-us/windows/win32/opengl/glbegin
// https://docs.microsoft.com/en-us/windows/win32/opengl/glend
// https://docs.microsoft.com/en-us/windows/win32/opengl/glflush

namespace OpenGL
{
    // The glBegin and glEnd functions delimit the vertices of a primitive or a group of like primitives.
    inline void __stdcall Begin(const GLenum mode)
    {
        ::glBegin(mode);
    }

    // The glBegin and glEnd functions delimit the vertices of a primitive or a group of like primitives.
    inline void __stdcall End()
    {
        ::glEnd();
    }

    // he glFlush function forces execution of OpenGL functions in finite time.
    inline void __stdcall Flush()
    {
        ::glFlush();
    }

    // The primitive or primitives that will be create from vertices presented between glBegin and the
    // subsequent glEnd. The following are accepted symbolic constants and their meanings.
    class BeginMode
    {
    private:
        GLenum value;

    public:
        inline constexpr BeginMode(const GLenum &value = Points) noexcept : value{ value } { }
        inline constexpr operator const GLenum&() const noexcept { return value; }
        using Type = GLenum;

        enum : GLenum
        {
            // Treats each vertex as a single point. 
            // Vertex n defines point n. 
            // N points are drawn.
            Points = GL_POINTS,

            // Treats each pair of vertices as an independent line segment. 
            // Vertices 2n - 1 and 2n define line n. 
            // N/2 lines are drawn.
            Lines = GL_LINES,

            // Draws a connected group of line segments from the first vertex to the last, then back to the first. 
            // Vertices n and n + 1 define line n. 
            // The last line, however, is defined by vertices N and 1. 
            // N lines are drawn.
            LineLoop = GL_LINE_LOOP,

            // Draws a connected group of line segments from the first vertex to the last. 
            // Vertices n and n+1 define line n. 
            // N - 1 lines are drawn.
            LineStrip = GL_LINE_STRIP,

            // Treats each triplet of vertices as an independent triangle. 
            // Vertices 3n - 2, 3n - 1, and 3n define triangle n. 
            // N/3 triangles are drawn.
            Triangles = GL_TRIANGLES,

            // Draws a connected group of triangles. 
            // One triangle is defined for each vertex presented after the first two vertices. 
            // For odd n, vertices n, n + 1, and n + 2 define triangle n. 
            // For even n, vertices n + 1, n, and n + 2 define triangle n. 
            // N - 2 triangles are drawn.
            TriangleStrip = GL_TRIANGLE_STRIP,

            // Draws a connected group of triangles. 
            // One triangle is defined for each vertex presented after the first two vertices. 
            // Vertices 1, n + 1, n + 2 define triangle n. 
            // N - 2 triangles are drawn.
            TriangleFan = GL_TRIANGLE_FAN,

            // Treats each group of four vertices as an independent quadrilateral. 
            // Vertices 4n - 3, 4n - 2, 4n - 1, and 4n define quadrilateral n. 
            // N/4 quadrilaterals are drawn.
            Quads = GL_QUADS,

            // Draws a connected group of quadrilaterals. 
            // One quadrilateral is defined for each pair of vertices presented after the first pair. 
            // Vertices 2n - 1, 2n, 2n + 2, and 2n + 1 define quadrilateral n. 
            // N/2 - 1 quadrilaterals are drawn. 
            // Note that the order in which vertices are used to construct a quadrilateral from strip data is different from that used with independent data.
            QuadStrip = GL_QUAD_STRIP,

            // Draws a single, convex polygon. 
            // Vertices 1 through N define this polygon.
            Polygon = GL_POLYGON,
        };
    };
}

#endif // !_GL_BEGIN_HPP_
