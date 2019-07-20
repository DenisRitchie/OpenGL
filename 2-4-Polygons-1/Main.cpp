#include <framework.h>

using namespace OpenGL;
using namespace OpenGL::Helper;
using namespace Glut;

void Display();

std::tuple<int, int, int, int> GetBound(const int &width, const int &height)
{
    const auto &desktop_size = DesktopSize();
    const auto &window_coord = CenteredCoordinates(desktop_size, width, height);
    return std::tuple_cat(window_coord, std::make_tuple(width, height));
}

int WINAPI wWinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPWSTR, _In_ INT32)
{
    const auto &[x, y, width, height] = GetBound(500, 500);
    InitDisplayMode(DisplayMode::Single | DisplayMode::Rgba);
    InitWindowSize(width, height);
    InitWindowPosition(x, y);
    GlutCreateWindow("OpenGL Polygon");
    DisplayFunc(Display);
    MainLoop();
    return EXIT_SUCCESS;
}

void DrawPolygons();

inline void Display()
{
    ClearColor::Rgb(0x0070E6);
    Clear(ClearMask::ColorBufferBit);
    SetMatrixMode(MatrixMode::Projection);
    LoadIdentity();
    glOrtho(Left(-100), Right(100), Bottom(-100), Top(100), Near(-100), Far(100));
    SetMatrixMode(MatrixMode::ModelView);
    DrawPolygons();
    Flush();
}

inline void DrawPolygons()
{
    // Todos los polígonos son en sentido horario
    // https://iubatians.blogspot.com/2015/06/c-opengl-07-draw-polygon.html
    // Los aristas no pueden cortarse entre sí
    // https://www.portaleducativo.net/segundo-basico/50/Identificacion-de-caras-aristas-vertices-en-cuerpos-geometricos
    // Un polígono debe ser convexo
    // https://matematicasmodernas.com/figuras-convexas/
    // https://figurasgeometricas.org/poligonos-concavos-y-convexos/

    const GLdouble vertices[] =
    {
        -60,  50, 0,
          0, 100, 0,
         60,  50, 0,
         40, -20, 0,
        -40, -20, 0,

        -40,  -20, 0,
         40,  -20, 0,
         70,  -50, 0,
          0, -100, 0,
        -70,  -50, 0,
    };

    RgbColor(0x00F292);
    EnableClientState(ClientState::VertexArray);
    VertexPointer(VertexSize::Three, VertexDataType::Double, vertices);
    DrawArrays(BeginMode::Polygon, FirstVertex(0), NumberOfVertices(5));
    DisableClientState(ClientState::VertexArray);

    RgbColor(0xBD0AFF);
    EnableClientState(ClientState::VertexArray);
    VertexPointer(VertexSize::Three, VertexDataType::Double, vertices + (VertexSize::Three * 5));
    DrawArrays(BeginMode::Polygon, FirstVertex(0), NumberOfVertices(5));
    DisableClientState(ClientState::VertexArray);
}

