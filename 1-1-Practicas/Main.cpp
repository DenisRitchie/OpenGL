#include <framework.h>
#include <stdlib.h>

using namespace OpenGL;
using namespace OpenGL::Helper;

void Display()
{
    // Color de fondo negro
    ClearColor::Black();

    // Borrar la pantalla con el color de fondo negro
    Clear(ClearMask::ColorBufferBit);

    // Modo de proyección
    SetMatrixMode(MatrixMode::Projection);

    // Cargar la matriz de identidad
    LoadIdentity();

    // Proyección ortográfica dentro del cubo señalado
    Ortho::Left(-1).Right(1).Bottom(-1).Top(1).Near(-1).Far(1).Call();

    // Modo de modelado
    SetMatrixMode(MatrixMode::ModelView);

    // Dibujar un triángulo
    Begin(BeginMode::Triangles);

        // Color del primer vertice es rojo
        glColor3d(Red(1.0), Green(0.0), Blue(0.0));
        glVertex3d(X(0.0), Y(0.8), Z(0.0));

        // Color del segundo vertice es verde
        glColor3d(Red(0.0), Green(1.0), Blue(0.0));
        glVertex3d(X(-0.6), Y(-0.2), Z(0.0));

        // Color del tercer vertice es azúl
        glColor3d(Red(0.0), Green(0.0), Blue(1.0));
        glVertex3d(X(0.6), Y(-0.2), Z(0.0));

    // Terminar de dibujar
    End();

    // Forzar el dibujado
    Flush();
}

int WINAPI wWinMain([[maybe_unused]] _In_ HINSTANCE hInstance, [[maybe_unused]] _In_opt_ HINSTANCE hPrevInstance, [[maybe_unused]] _In_ LPWSTR lpszCmdLine, [[maybe_unused]] _In_ INT32 nCmdShow)
{
    Glut::InitDisplayMode(Glut::DisplayMode::Single | Glut::DisplayMode::Rgba);

    auto desktop_size = DesktopSize();
    constexpr int window_width = 500, window_height = 500;
    const auto [x, y] = CenteredCoordinates(desktop_size, window_width, window_height);

    Glut::InitWindowPosition(x, y);
    Glut::InitWindowSize(window_width, window_height);
    Glut::GlutCreateWindow("OpenGL");
    Glut::DisplayFunc(Display);
    Glut::MainLoop();

    return EXIT_SUCCESS;
}
