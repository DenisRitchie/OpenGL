#include <framework.h>

using namespace OpenGL;
using namespace OpenGL::Helper;
using namespace Glut;

void Display();

int WINAPI wWinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPWSTR, _In_ INT32)
{
    InitDisplayMode(DisplayMode::Single | DisplayMode::Rgba);

    constexpr int width = 500, height = 500;
    const auto &desktop_size = GlutDesktopSize();
    const auto &[x, y] = CenteredCoordinates(desktop_size, width, height);

    InitWindowSize(width, height);
    InitWindowPosition(x, y);
    GlutCreateWindow("OpenGL Quads");

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    DisplayFunc(Display);
    MainLoop();
    return EXIT_SUCCESS;
}

void DrawQuads();
void DrawQuadsStrip();

inline void Display()
{
    ClearColor::Rgb(0x830037);
    Clear(ClearMask::ColorBufferBit);
    SetMatrixMode(MatrixMode::Projection);
    LoadIdentity();
    Ortho::Left(-100).Right(100).Bottom(-100).Top(100).Near(-100).Far(100).Call();
    SetMatrixMode(MatrixMode::ModelView);
    DrawQuads();
    DrawQuadsStrip();
    Flush();
}

inline void DrawQuads()
{
    // https://iubatians.blogspot.com/2015/06/c-opengl-08-draw-quads.html

    /*Begin(BeginMode::Quads);
    {
        RgbColor(0x5C38FE);

        const GLdouble coords[][2] =
        {
            { -90,  90 },
            {  90,  90 },
            {  90, -90 },
            { -90, -90 },
        };

        for (const GLdouble(&coord)[2] : coords)
        {
            glVertex2dv(coord);
        }
    }
    End();*/

    RgbColor(0x5C38FE);

    const GLdouble coords[] =
    {
        -90,  90,
         90,  90,
         90, -90,
        -90, -90,
    };

    // http://docs.gl/es2/glDrawArrays
    // https://docs.microsoft.com/en-us/windows/win32/opengl/gldrawarrays
    // https://docs.microsoft.com/en-us/windows/win32/opengl/glvertexpointer
    // http://www.songho.ca/opengl/gl_vertexarray.html
    // http://math.hws.edu/graphicsbook/c3/s4.html

    // glEnableClientState(/*array type*/ GL_VERTEX_ARRAY);
    // glVertexPointer(
    //     /*coord by vertex: 2, 3, 4*/ 2 /*glVertex2d*/,
    //     /*vertex data type*/ GL_DOUBLE,
    //     /*desplazamiento consecutivo*/ 0,
    //     /*primer vertice del array*/ coords);
    // glDrawArrays(
    //     /*BeginMode*/ GL_QUADS,
    //     /*first data*/ 0,
    //     /*n-vertices*/ 4);
    // glDisableClientState(/*array type*/ GL_VERTEX_ARRAY);

    EnableClientState(ClientState::VertexArray);
    VertexPointer(VertexSize::Two, VertexDataType::Double, coords);
    DrawArrays(BeginMode::Quads, FirstVertex(0), NumberOfVertices(4));
    DisableClientState(ClientState::VertexArray);
}

inline void DrawQuadsStrip()
{
    // https://iubatians.blogspot.com/2015/06/c-opengl-09-draw-quads-strip.html
    // Los vertices se ubican en zio-zap en horario comenzando de abajo hacia arriba
    // Este es igual como cuando se dibuja con BeginMode::TriangleStrip

    /*Begin(BeginMode::QuadStrip);
    {
        const GLdouble coords[][2] =
        {
            { -60, -60 },
            { -60,  60 },
            { -10, -60 },
            { -10,  60 },

            {  30, -40 },
            {  30,  40 },

            {  60, -50 },
            {  60,  50 },
        };

        RgbColor(0x00311C);
        glVertex2dv(coords[0]);
        glVertex2dv(coords[1]);
        glVertex2dv(coords[2]);
        glVertex2dv(coords[3]);

        RgbColor(0xB78000);
        glVertex2dv(coords[4]);
        glVertex2dv(coords[5]);

        RgbColor(0x0038DC);
        glVertex2dv(coords[6]);
        glVertex2dv(coords[7]);
    }
    End();*/

    const GLdouble coords[][2] =
    {
        { -60, -60 },
        { -60,  60 },
        { -10, -60 },
        { -10,  60 },

        {  30, -40 },
        {  30,  40 },

        {  60, -50 },
        {  60,  50 },
    };

    RgbColor(0x00311C);
    
    // glEnableClientState(GL_VERTEX_ARRAY);
    // glVertexPointer(/*glVertex2d*/ 2, GL_DOUBLE, /*step*/ 0, coords);
    // glDrawArrays(GL_QUAD_STRIP, 0, /*vertices*/ 8);
    // glDisableClientState(GL_VERTEX_ARRAY);
    
    EnableClientState(ClientState::VertexArray);
    VertexPointer(VertexSize::Two, VertexDataType::Double, coords);
    DrawArrays(BeginMode::QuadStrip, FirstVertex(0), NumberOfVertices(8));
    DisableClientState(ClientState::VertexArray);
}

