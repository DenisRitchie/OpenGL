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
	OpengGL::LoadIdentity();

	// Proyección ortográfica dentro del cubo señalado
	OpenGL::Ortho::Left(-1).Right(1).Bottom(-1).Top(1).Near(-1).Far(1).Call();

	// Modo de modelado
	glMatrixMode(GL_MODELVIEW);

	// Dibujar un triángulo
	OpenGL::Begin(OpenGL::BeginMode::Triangles);

		// Color del primer vertice es rojo
		glColor3d(1.0, 0.0, 0.0);
		glVertex3d(0.0, 0.8, 0.0);

		// Color del segundo vertice es verde
		glColor3d(0.0, 1.0, 0.0);
		glVertex3d(-0.6, -0.2, 0.0);

		// Color del tercer vertice es azúl
		glColor3d(0.0, 0.0, 1.0);
		glVertex3d(0.6, -0.2, 0.0);

	// Terminar de dibujar
	OpenGL::End();

	// Forzar el dibujado
	OpenGL::Flush();
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
