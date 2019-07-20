#include <framework.h>

using namespace OpenGL;
using namespace OpenGL::Helper;

void Display();

int WINAPI wWinMain([[maybe_unused]] _In_ HINSTANCE hInstance, [[maybe_unused]] _In_opt_ HINSTANCE hPrevInstance, [[maybe_unused]] _In_ LPWSTR lpszCmdLine, [[maybe_unused]] _In_ INT32 nCmdShow)
{
    Glut::InitDisplayMode(Glut::DisplayMode::Single | Glut::DisplayMode::Rgba);

    const auto desktop_size = DesktopSize();
    constexpr int window_width = 1'000, window_height = 500;
    const auto [x, y] = CenteredCoordinates(desktop_size, window_width, window_height);

    Glut::InitWindowPosition(x, y);
    Glut::InitWindowSize(window_width, window_height);

    Glut::GlutCreateWindow("OpenGL Lines");

    // Maximize window using Window API
    // HWND hwnd = FindWindowA(nullptr, "OpenGL Lines");
    // SetWindowLongPtr(hwnd, GWL_STYLE, GetWindowLongPtr(hwnd, GWL_STYLE) | WS_MAXIMIZE);
    // ShowWindowAsync(hwnd, SW_SHOWMAXIMIZED);

    Glut::DisplayFunc(Display);
    Glut::MainLoop();

    return EXIT_SUCCESS;
}

void DrawLines();
void DrawLinesStrip();
void DrawLinesLoop();

void Display()
{
    ClearColor::Black();
    Clear(ClearMask::ColorBufferBit);
    SetMatrixMode(MatrixMode::Projection);
    LoadIdentity();
    Ortho::Left(-100).Right(100).Bottom(-100).Top(100).Near(-100).Far(100).Call();
    SetMatrixMode(MatrixMode::ModelView);

    // DrawLines();
    // DrawLinesStrip();
    DrawLinesLoop();

    Flush();
}

inline void DrawLines()
{
    // https://iubatians.blogspot.com/2015/06/c-opengl-04-draw-lines.html

    Begin(BeginMode::Lines);
    {
        glColor3d(Red(255), Green(255), Blue(0));
        glVertex2d(X(0), Y(90));
        glVertex2d(X(0), Y(0));

        glColor3d(Red(255), Green(0), Blue(0));
        glVertex2d(X(-90), Y(90));
        glVertex2d(X(90), Y(-90));

        glColor3d(Red(0), Green(255), Blue(0));
        glVertex2d(X(-90), Y(90));
        glVertex2d(X(-90), Y(0));

        glColor3d(Red(0), Green(0), Blue(255));
        glVertex2d(X(-90), Y(0));
        glVertex2d(X(0), Y(-90));

        glColor3d(Red(255), Green(255), Blue(255));
        glVertex2d(X(0), Y(-90));
        glVertex2d(X(90), Y(0));

        glColor3d(Red(0), Green(255), Blue(255));
        glVertex2d(X(90), Y(0));
        glVertex2d(X(90), Y(90));

        glColor3d(Red(255), Green(0), Blue(255));
        glVertex2d(X(90), Y(90));
        glVertex2d(X(-90), Y(-90));
    }
    End();
}

inline void DrawLinesStrip()
{
    // https://iubatians.blogspot.com/2015/06/c-opengl-05-draw-lines-strip.html

    Begin(BeginMode::LineStrip);
    {
        glColor3d(Red(255), Green(255), Blue(0));
        glVertex2d(X(0), Y(90));
        glColor3d(Red(240), Green(50), Blue(100));
        glVertex2d(X(0), Y(0));
        glColor3d(Red(255), Green(0), Blue(0));
        glVertex2d(X(90), Y(-90));
        glColor3d(Red(0), Green(0), Blue(255));
        glVertex2d(X(-90), Y(90));
        glColor3d(Red(255), Green(255), Blue(255));
        glVertex2d(X(-90), Y(0));
        glColor3d(Red(0), Green(255), Blue(255));
        glVertex2d(X(0), Y(-90));
        glColor3d(Red(255), Green(0), Blue(255));
        glVertex2d(X(90), Y(0));
        glColor3d(Red(0), Green(255), Blue(0));
        glVertex2d(X(90), Y(90));
        glColor3d(Red(140), Green(255), Blue(180));
        glVertex2d(X(-90), Y(-90));
    }
    End();
}

inline void DrawLinesLoop()
{
    // https://iubatians.blogspot.com/2015/06/c-opengl-06-draw-lines-loop.html

    Begin(BeginMode::LineLoop);
    {
        glColor3d(Red(255), Green(255), Blue(255));
        glVertex2d(X(-90), Y(90));
        glColor3d(Red(255), Green(0), Blue(255));
        glVertex2d(X(-90), Y(0));
        glColor3d(Red(0), Green(255), Blue(255));
        glVertex2d(X(0), Y(-90));
        glColor3d(Red(255), Green(255), Blue(0));
        glVertex2d(X(90), Y(0));
        glColor3d(Red(0), Green(0), Blue(255));
        glVertex2d(X(90), Y(90));
        glColor3d(Red(255), Green(0), Blue(0));
        glVertex2d(X(-90), Y(-90));
        glColor3d(Red(0), Green(255), Blue(0));
        glVertex2d(X(0), Y(0));
        glColor3d(Red(100), Green(10), Blue(255));
        glVertex2d(X(0), Y(90));
        glColor3d(Red(20), Green(150), Blue(10));
        glVertex2d(X(0), Y(0));
        glColor3d(Red(100), Green(100), Blue(100));
        glVertex2d(X(90), Y(-90));
    }
    End();
}
