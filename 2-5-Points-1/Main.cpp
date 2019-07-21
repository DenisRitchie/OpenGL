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
    const auto &[x, y, width, height] = GetBound(1'000, 500);
    InitDisplayMode(DisplayMode::Single | DisplayMode::Rgba);
    InitWindowSize(width, height);
    InitWindowPosition(x, y);
    GlutCreateWindow("OpenGL Points");
    DisplayFunc(Display);
    // AllocConsole();
    MainLoop();
    // FreeConsole();
    return EXIT_SUCCESS;
}

void DrawCircle();
void DrawTheSpiralOfArchimedes();
void DrawFermatsSpiral();

inline void Display()
{
    ClearColor::Rgb(0x4A0066);
    Clear(ClearMask::ColorBufferBit);
    SetMatrixMode(MatrixMode::Projection);
    LoadIdentity();
    glOrtho(Left(-100), Right(100), Bottom(-100), Top(100), Near(-100), Far(100));
    SetMatrixMode(MatrixMode::ModelView);
    // DrawCircle();
    // DrawTheSpiralOfArchimedes();
    DrawFermatsSpiral();
    Flush();
}

inline void DrawCircle()
{
    // Dibujando un punto en el plano
    // https://iubatians.blogspot.com/2015/06/c-opengl-03-draw-points.html

    // Aumentar tamaño a un punto
    // http://docs.gl/gl2/glPointSize
    // https://docs.microsoft.com/en-us/windows/win32/opengl/glpointsize

    // Coordenadas polares en el plano
    // https://matematicasmodernas.com/conversion-de-coordenadas-en-el-plano/

    // Círculo trigonométrico y funciones trigonométricas
    // https://matematicasmodernas.com/circulo-trigonometrico-y-funciones-trigonometricas/

    // Signos de las funciones trigonométricas
    // https://matematicasmodernas.com/signos-de-las-funciones-trigonometricas/

    glPointSize(5);
    Begin(BeginMode::Points);
    {
        // PI   = 180°
        // PI*2 = 360°

        constexpr GLdouble _360_grados = PI * 2.0;
        constexpr GLdouble coordenada_radial = 90;

        // Fórmulas matemáticas de coordenadas polares
        // https://es.wikipedia.org/wiki/Coordenadas_polares

        // https://es.wikipedia.org/wiki/Coordenadas_cil%C3%ADndricas
        // Las coordenadas cilíndricas pueden convertirse en coordenadas cartesianas de la siguiente manera:
        // X = r cos θ
        // Y = r sen θ
        // Z = h (altura)

        RgbColor(0x2CFFA7);

        for (GLdouble coordenada_angular = 0.0; coordenada_angular < _360_grados; coordenada_angular += 0.1)
        {
            // Dibujar en sentido anti-horario
            GLdouble eje_x = coordenada_radial * cos(coordenada_angular);
            GLdouble eje_y = coordenada_radial * sin(coordenada_angular);

            // Dibujar en sentido horario
            // GLdouble eje_x = coordenada_radial * sin(coordenada_angular);
            // GLdouble eje_y = coordenada_radial * cos(coordenada_angular);

            glVertex2d(eje_x, eje_y);
        }
    }
    End();
}

inline void DrawTheSpiralOfArchimedes()
{
    glPointSize(1);
    Begin(BeginMode::Points);
    {
        // https://es.switch-case.com/50875182
        // Espiral de Arquímedes
        // La espiral de Arquímedes es una famosa espiral descubierta por Arquímedes, la cual puede expresarse también como una ecuación polar simple.
        // Se representa con la ecuación:
        // r = a + bθ
        // x = r cos θ
        // y = r sen θ
        // Siendo a y b números reales. 
        // Cuando el parámetro a cambia, la espiral se desplaza en el eje X, 
        // mientras que b controla la distancia entre giros sucesivos.

        RgbColor(0xFFFFFF);

        // Espacios entre el espiral
        constexpr GLdouble a = 1, b = 1;

        for (GLdouble point = 0; point < 1'700; ++point)
        {
            // Fórmula: r = a + bθ
            const GLdouble angle = 2 * point;
            const GLdouble x = (a + b * angle) * cos(angle);
            const GLdouble y = (a + b * angle) * sin(angle);
            glVertex2d(x, y);
        }
    }
    End();
}

inline void DrawFermatsSpiral()
{
    // TODO: Analizar ecuación matemática y su respectiva implementación en OpenGL

    glPointSize(3);

    // https://es.wikipedia.org/wiki/Espiral_de_Fermat
    // Espiral de Fermat
    // La espiral de Fermat, denominada así en honor de Pierre de Fermat y también conocida como espiral parabólica, 
    // es una curva que responde a la siguiente ecuación:
    // r = ±θ^½
    // x = r cos θ
    // y = r sen θ

    SetMatrixMode(MatrixMode::Projection);
    LoadIdentity();
    glOrtho(-4, 4, -4, 4, -4, 4);
    SetMatrixMode(MatrixMode::ModelView);

    Begin(BeginMode::Points);
    {
        RgbColor(0xFFFFFF);

        GLdouble angulo_inicial = 0.1, angulo_final = 16.0, muestras = 400;
        GLdouble angulo_distancia = (angulo_final - angulo_inicial) / muestras;

        for (GLdouble punto = 0; punto <= muestras; ++punto)
        {
            // r = ±θ^½ -> ±sqrt(θ)
            // x =  r cos θ, y =  r sen θ
            // x = -r cos θ, y = -r sen θ

            // Archimedean Spiral
            GLdouble angulo = angulo_inicial + (punto * angulo_distancia);

            // Specific to made a Fermat Spiral.
            GLdouble radio = sqrt(angulo);

            // Polar to cartesian
            GLdouble eje_x = radio * cos(angulo);
            GLdouble eje_y = radio * sin(angulo);

            // Square root means two solutions, one positive and other negative. 
            // 2 points to be drawn.
            glVertex2d(eje_x, eje_y);

            eje_x = -radio * cos(angulo);
            eje_y = -radio * sin(angulo);

            glVertex2d(eje_x, eje_y);
        }
    }
    End();
}

