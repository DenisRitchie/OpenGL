#include <framework.h>

using namespace Glut;
using namespace OpenGL;
using namespace OpenGL::Helper;

void Display();

int WINAPI wWinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPWSTR, _In_ INT32)
{
    constexpr int32_t width = 1'000, height = 500;
    const auto desktop_size = GlutDesktopSize();
    const auto [x, y] = CenteredCoordinates(desktop_size, width, height);

    InitDisplayMode(DisplayMode::Single | DisplayMode::Rgba);
    InitWindowSize(width, height);
    InitWindowPosition(x, y);
    GlutCreateWindow("Triangles");
    DisplayFunc(Display);
    MainLoop();

    return EXIT_SUCCESS;
}

void DrawTriangles();

void Display()
{
    ClearColor::Black();
    Clear(ClearMask::ColorBufferBit);
    SetMatrixMode(MatrixMode::Projection);
    LoadIdentity();
    glOrtho(Left(-100), Right(100), Bottom(-100), Top(100), Near(-100), Far(100));
    SetMatrixMode(MatrixMode::ModelView);
    DrawTriangles();

    Flush();
}

void DrawTriangles()
{
    Begin(BeginMode::Triangles);
    {
        // glColor3d(0.9373, 0.7216, 0.0627);
        // HexColor3d(0xEF, 0xB8, 0x10);
        HexColor(0xEFB810);

        // Triangulo 1
        glVertex2d(X(-99), Y(-99));
        glVertex2d(X(-33), Y(-99));
        glVertex2d(X(-66), Y(-33));

        // Triangulo 2
        glVertex2d(X(-33), Y(-99));
        glVertex2d(X(33), Y(-99));
        glVertex2d(X(0), Y(-33));

        // Triangulo 3
        glVertex2d(X(-66), Y(-33));
        glVertex2d(X(0), Y(-33));
        glVertex2d(X(-33), Y(33));
    }
    End();
}