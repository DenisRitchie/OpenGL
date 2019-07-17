#include <framework.h>
#include <stdlib.h>

using namespace OpenGL::Helper;

void Display()
{
	// Color de fondo negro
	OpenGL::ClearColor::Black();

	// Borrar la pantalla con el color de fondo negro
	glClear(GL_COLOR_BUFFER_BIT);

	// Modo de proyección
	glMatrixMode(GL_PROJECTION);

	// Cargar la matriz de identidad
	glLoadIdentity();

	// Proyección ortográfica dentro del cubo señalado
	glOrtho(-1, 1, -1, 1, -1, 1);

	// Modo de modelado
	glMatrixMode(GL_MODELVIEW);

	// Dibujar un triángulo
	OpenGL::Begin(OpenGL::BeginMode::Triangles);

	// Terminar de dibujar
	OpenGL::End();

	// Forzar el dibujado
	glFlush();
}

int WINAPI wWinMain([[maybe_unused]] _In_ HINSTANCE hInstance, [[maybe_unused]] _In_opt_ HINSTANCE hPrevInstance, [[maybe_unused]] _In_ LPWSTR lpszCmdLine, [[maybe_unused]] _In_ INT32 nCmdShow)
{
	Glut::InitDisplayMode(Glut::DisplayMode::Single | Glut::DisplayMode::Rgba);

	auto desktop_size = DesktopSize();
	constexpr int window_width = 500, window_height = 500;
	auto [x, y] = CenteredCoordinates(desktop_size, window_width, window_height);

	Glut::InitWindowPosition(x, y);
	Glut::InitWindowSize(window_width, window_height);
	Glut::GlutCreateWindow("OpenGL");
	Glut::DisplayFunc(Display);
	Glut::MainLoop();

	return EXIT_SUCCESS;
}
