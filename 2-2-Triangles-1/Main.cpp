#include <framework.h>

using namespace Glut;
using namespace OpenGL;
using namespace OpenGL::Helper;

void Display();

int WINAPI wWinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPWSTR, _In_ INT32)
{
    constexpr int32_t width = 500, height = 500;
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
void DrawTrianglesStrip();
void DrawTrianglesFan();
void DrawTrianglesFan2();
void DrawTrianglesFan3();

void Display()
{
    ClearColor::Rgb(0x393276);
    Clear(ClearMask::ColorBufferBit);
    SetMatrixMode(MatrixMode::Projection);
    LoadIdentity();
    glOrtho(Left(-100), Right(100), Bottom(-100), Top(100), Near(-100), Far(100));
    SetMatrixMode(MatrixMode::ModelView);
    // DrawTriangles();
    // DrawTrianglesStrip();
    // DrawTrianglesFan();
    // DrawTrianglesFan2();
    DrawTrianglesFan3();
    Flush();
}

inline void DrawTriangles()
{
    // https://iubatians.blogspot.com/2015/06/c-opengl-10-draw-triangle.html
    // Vertices anti-horario manualmente

    Begin(BeginMode::Triangles);
    {
        RgbColor(0xB40500);

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

inline void DrawTrianglesStrip()
{
    // https://iubatians.blogspot.com/2015/06/c-opengl-11-draw-triangle-strip.html
    // Vertices anti-horario automáticamene

    Begin(BeginMode::TriangleStrip);
    {
        RgbColor(0xFF0000);
        glVertex2d(X(0), Y(0));
        glVertex2d(X(-99), Y(33));
        glVertex2d(X(-99), Y(-33));
        RgbColor(0x00FF00);
        glVertex2d(X(0), Y(0));
        glVertex2d(X(-33), Y(-99));
        RgbColor(0x0000FF);
        glVertex2d(X(33), Y(-99));
        glVertex2d(X(0), Y(0));
        RgbColor(0xF0F0F0F);
        glVertex2d(X(99), Y(-33));
        RgbColor(0xFFFFFF);
        glVertex2d(X(99), Y(33));
        glVertex2d(X(0), Y(0));
        RgbColor(0xFFFF00);
        glVertex2d(X(33), Y(99));
        RgbColor(0x00FFFF);
        glVertex2d(X(-33), Y(99));
        RgbColor(0x0F0F0F);
        glVertex2d(X(0), Y(0));
        glVertex2d(X(-99), Y(33));
    }
    End();
}

inline void DrawTrianglesFan()
{
    Begin(BeginMode::TriangleFan);
    {
        RgbColor(0xEF1097);
        glVertex2d(0, 0);
        glVertex2d(-50, 50);
        glVertex2d(-50, -50);
        glVertex2d(50, -50);
        glVertex2d(50, 50);
    }
    End();

    Begin(BeginMode::TriangleFan);
    {
        RgbColor(0xFFF00C);
        glVertex2d(0, 10);
        glVertex2d(-40, 50);
        glVertex2d(40, 50);
    }
    End();
}

inline void DrawTrianglesFan2()
{
    // Dibujando TriangleFan
    // https://stackoverflow.com/questions/8043923/gl-triangle-fan-explanation
    // https://iubatians.blogspot.com/2015/06/c-opengl-12-draw-triangle-fan.html

    // Sector circular
    // https://www.matesfacil.com/ESO/geometria_plana/circular/sector/sector-circular-circunferencia-radio-area-perimetro-problemas-resueltos.html

    // Vertices horario automáticamene
    Begin(BeginMode::TriangleFan);
    {
        RgbColor(0xCFE01F);
        glVertex3d(X(0.0), Y(0.0), Z(75.0));

        // Si el ángulo es α = 2π radianes(ó 360 grados), el sector circular es un círculo completo.
        for (GLdouble angle = 0.0; angle < (2.0 * PI); angle += 0.5)
        {
            GLdouble x = /*Radio*/50.0 * sin(angle);
            GLdouble y = /*Radio*/50.0 * cos(angle);
            glVertex2d(x, y);
        }
    }
    End();
}

inline void DrawTrianglesFan3()
{
    Begin(BeginMode::TriangleFan);
    {
        RgbColor(0xFF0000);
    }
    End();

    Begin(BeginMode::TriangleFan);
    {
        RgbColor(0x000000);
    }
    End();
}