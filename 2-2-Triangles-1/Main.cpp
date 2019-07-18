#include <framework.h>

using namespace Glut;
using namespace OpenGL;
using namespace OpenGL::Helper;

void Display();

int WINAPI wWinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPWSTR, _In_ INT32)
{
    constexpr int32_t width = 800, height = 500;
    const auto desktop_size = GlutDesktopSize();
    const auto [x, y] = CenteredCoordinates(desktop_size, width, height);

    InitDisplayMode(DisplayMode::Single | DisplayMode::Rgba);
    InitWindowSize(width, height);
    InitWindowPosition(x, y);
    GlutCreateWindow("Triangles");
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    DisplayFunc(Display);
    MainLoop();

    return EXIT_SUCCESS;
}

void DrawTriangles();

void Display()
{
    ClearColor::White();
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
        // ArgbColor(0xFF'EF'B8'10);
        RgbColor(0xEFB810);

        // Triangulo 1
        glVertex2d(X(-99), Y(-99));
        glVertex2d(X(0), Y(-99));
        glVertex2d(X(-49.5), Y(0));

        // Triangulo 2
        glVertex2d(X(0), Y(-99));
        glVertex2d(X(99), Y(-99));
        glVertex2d(X(49.5), Y(0));

        // Triangulo 3
        glVertex2d(X(-49.5), Y(0));
        glVertex2d(X(49.5), Y(0));
        glVertex2d(X(0), Y(99));
    }
    End();
}
