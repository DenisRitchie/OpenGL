#include <framework.h>
#include <array>
#include <vector>
#include <tuple>

namespace DibujandoUnPunto
{
    void DisplayDot()
    {
        glClear(GL_COLOR_BUFFER_BIT);
        OpenGL::Begin(OpenGL::BeginMode::Points);
        glVertex2i(50, 40);
        OpenGL::End();
        glFlush();
    }

    void Init()
    {
        glClearColor(1, 1, 1, 0);
        glColor3f(0, 1, 0);
        glPointSize(10);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0, 100, 0, 100);
    }

    void Main()
    {
        glutInitWindowSize(350, 350);
        glutInitWindowPosition(200, 200);
        glutCreateWindow("Creando un punto");
        Init();
        glutDisplayFunc(DisplayDot);
        glutMainLoop();
    }
}

#define X(value) value
#define Y(value) value
#define Z(value) value
#define Red(value) value
#define Blue(value) value
#define Green(value) value
#define Alpha(value) value
#define Left(value) value
#define Right(value) value
#define Bottom(value) value
#define Top(value) value
#define ZNear(value) value
#define ZFar(value) value

namespace PrimitivaBásica
{
    inline void DibujoDePuntos()
    {
        OpenGL::Begin(OpenGL::BeginMode::Points);
        glColor3f(Red(1), Green(0), Blue(0));
        glVertex3f(X(-95), Y(-95), Z(0)); // Left  - Bottom
        glVertex3f(X( 95), Y( 95), Z(0)); // Right - Top
        glVertex2f(X(-95), Y( 95));       // Left  - Top
        glVertex2f(X( 95), Y(-95));       // Right - Bottom

        glColor3f(Red(0.96), Green(0.74), Blue(0.03)); // Amarillo
        for (GLint I = -90; I <= 90; I += 5)
        {
            glVertex2i(X(  I), Y( 95));		  // Linea Superior
            glVertex2i(X(  I), Y(-95));		  // Linea Inferior
            glVertex3i(X(-95), Y(  I), Z(0)); // Linea Izquierda
            glVertex3i(X( 95), Y(  I), Z(0)); // Línea Derecha
        }
        OpenGL::End();
    }

    inline void DibujoDeLíneas()
    {
        static constexpr GLdouble Limit = 94.9;

        OpenGL::Begin(OpenGL::BeginMode::Lines);
        glColor3f(Red(0.61), Green(0.93), Blue(0.03));

        for (GLdouble x1 = -Limit, x2 = -Limit, y1 = Limit, y2 = Limit; y1 > -Limit; y1 -= 5, x2 += 5)
        {
            glVertex3d(X(x1), Y(y1), Z(0));
            glVertex3d(X(x2), Y(y2), Z(0));
        }

        // Diagonal Principal
        glColor3f(Red(0.90), Green(0.16), Blue(0.93)); // Purpura
        glVertex2d(X(-95), Y(95));
        glVertex2d(X(95), Y(-95));
        OpenGL::End();

        // Zip-Zap
        OpenGL::Begin(OpenGL::BeginMode::LineStrip);
            // Diágonal secundaria
        glColor3f(Red(0), Green(0), Blue(1));
        glVertex2d(-95, -95);

        for (GLdouble x = -90; x <= 95; x += 5)
            !fmod(x, 10) ? glVertex2d(x, x + 5) : glVertex2d(x, x - 5);

        // Diágonal principal
        glColor3f(Red(1), Green(0), Blue(0));
        glVertex2d(-95, 95);

        for (GLdouble x = -90, y = abs(x); x <= 95; x += 5, y -= 5)
            !fmod(x, 10) ? glVertex2d(x, y + 5) : glVertex2d(x, y - 5);

        glVertex2d(-95, -95);
        OpenGL::End();

        OpenGL::Begin(OpenGL::BeginMode::LineLoop);
        glColor3d(1, 1, 1);
        glVertex3d(X(95), Y(0), Z(0));
        glVertex3d(X(70), Y(50), Z(0));
        glVertex3d(X(45), Y(0), Z(0));
        glVertex3d(X(85), Y(0), Z(0));
        glVertex3d(X(60), Y(40), Z(0));
        glVertex3d(X(35), Y(-10), Z(0));
        glVertex3d(X(95), Y(-10), Z(0));
        OpenGL::End();
    }

    inline void PoligonosTriangulos()
    {
        OpenGL::Begin(OpenGL::BeginMode::Triangles);
        glColor3d(Red(1), Green(1), Blue(1));
        glVertex3d(X(  0), Y( 60), Z(0));
        glVertex3d(X(-30), Y(-30), Z(0));
        glVertex3d(X( 30), Y(-30), Z(0));

        glColor3d(Red(1), Green(0), Blue(0));
        glVertex3d(X(  0), Y(-60), Z(0));
        glVertex3d(X( 30), Y( 30), Z(0));
        glVertex3d(X(-30), Y( 30), Z(0));
        OpenGL::End();
    }

    inline void PoligonosTriangulosFan()
    {
        OpenGL::Begin(OpenGL::BeginMode::TriangleFan);
        glVertex2d(X(0), Y(0));
        glColor3d(Red(0), Green(0), Blue(0));
        glVertex2d(X(10), Y(30));
        glVertex2d(X(20), Y(0));
        glColor3d(Red(1), Green(0.95), Blue(0));
        glVertex2d(X(10), Y(-30));
        glColor3d(Red(1), Green(0.5), Blue(0.14));
        glVertex2d(X(-20), Y(0));
        glColor3d(Red(0.73), Green(0.48), Blue(0.34));
        glVertex2d(X(10), Y(30));
        OpenGL::End();
    }

    inline void Poligonos()
    {
        OpenGL::Begin(OpenGL::BeginMode::Polygon);
        glColor3d(Red(0), Green(0), Blue(1));
        glVertex2d(X(-10), Y(30));
        glVertex2d(X(10), Y(30));
        glVertex2d(X(20), Y(0));
        glVertex2d(X(10), Y(-30));
        glVertex2d(X(-10), Y(-30));
        glVertex2d(X(-20), Y(0));
        OpenGL::End();
    }

    inline void DibujoDePoligonos()
    {
        PoligonosTriangulos();
        Poligonos();
        PoligonosTriangulosFan();
    }

    inline void DibujoDeCuadrilátero()
    {
        static constexpr GLdouble(*get_color)(GLdouble) = [](GLdouble value) constexpr { return value / 255.0; };

        OpenGL::Begin(OpenGL::BeginMode::Quads);
        glColor3d(get_color(219), get_color(17), get_color(135));
        glVertex3d(X(65), Y(-35), Z(0));
        glVertex3d(X(90), Y(-35), Z(0));
        glVertex3d(X(90), Y(-15), Z(0));
        glVertex3d(X(65), Y(-15), Z(0));
        OpenGL::End();

        OpenGL::Begin(OpenGL::BeginMode::QuadStrip);
        glColor3d(get_color(52), get_color(224), get_color(236));
        glVertex3d(X(-55), Y(-65), Z(0));
        glVertex3d(X(-55), Y(-80), Z(0));
        glVertex3d(X(  0), Y(-80), Z(0));
        glColor3d(get_color(19), get_color(102), get_color(107));
        glVertex3d(X( 0), Y(-65), Z(0));
        glVertex3d(X(55), Y(-65), Z(0));
        glVertex3d(X(55), Y(-80), Z(0));
        OpenGL::End();
    }
}

void Display()
{
    glClearColor(Red(0), Green(0), Blue(0), Alpha(0));
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(Left(-100), Right(100), Bottom(-100), Top(100), ZNear(-100), ZFar(100));
    glMatrixMode(GL_MODELVIEW);
    PrimitivaBásica::DibujoDePuntos();
    PrimitivaBásica::DibujoDeLíneas();
    PrimitivaBásica::DibujoDePoligonos();
    PrimitivaBásica::DibujoDeCuadrilátero();
    glFlush();
}

int WINAPI wWinMain([[maybe_unused]] _In_ HINSTANCE hInstance, [[maybe_unused]] _In_opt_ HINSTANCE hPrevInstance, [[maybe_unused]] _In_ LPWSTR lpCmdLine, [[maybe_unused]] _In_ int nShowCmd)
{
    const int32_t ScreenX = GetSystemMetrics(SM_CXSCREEN),
                  ScreenY = GetSystemMetrics(SM_CYSCREEN);

    constexpr int32_t Width = 1'000, Height = 500;

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowPosition(ScreenX / 2 - Width / 2, ScreenY / 2 - Height / 2);
    glutInitWindowSize(Width, Height);
    glutCreateWindow("Las Primitivas Básicas");
    glutDisplayFunc(Display);
    glutMainLoop();

    return EXIT_SUCCESS;
}