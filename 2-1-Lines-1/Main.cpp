#include <framework.h>

using namespace OpenGL;
using namespace OpenGL::Helper;

void Display();

int WINAPI wWinMain([[maybe_unused]] _In_ HINSTANCE hInstance, [[maybe_unused]] _In_opt_ HINSTANCE hPrevInstance, [[maybe_unused]] _In_ LPWSTR lpszCmdLine, [[maybe_unused]] _In_ INT32 nCmdShow)
{
	Glut::InitDisplayMode(Glut::DisplayMode::Single | Glut::DisplayMode::Rgba);

	auto desktop_size = DesktopSize();
	constexpr int window_width = 700, window_height = 700;
	auto [x, y] = CenteredCoordinates(desktop_size, window_width, window_height);

	Glut::InitWindowPosition(x, y);
	Glut::InitWindowSize(window_width, window_height);

	Glut::GlutCreateWindow("OpenGL Lines");
	Glut::DisplayFunc(Display);
	Glut::MainLoop();

	return EXIT_SUCCESS;
}

void DrawLines();

void Display()
{
	ClearColor::Black();
	Clear(ClearMask::ColorBufferBit);
	SetMatrixMode(MatrixMode::Projection);
	LoadIdentity();
	Ortho::Left(-100).Right(100).Bottom(-100).Top(100).Near(-100).Far(100).Call();
	SetMatrixMode(MatrixMode::ModelView);
	Begin(BeginMode::Lines);
	{
		DrawLines();
	}
	End();
	Flush();
}

inline void DrawLines()
{
	// Amarrillo brillante
	glColor3d(Red(255), Green(255), Blue(0));
	glVertex3d(X(-90), Y(90), Z(0));
	glVertex3d(X(90), Y(90), Z(0));

	// Azúl bonito
	glColor3d(Red(60), Green(97), Blue(232));
	glVertex3d(X(-90), Y(-90), Z(0));
	glVertex3d(X(90), Y(-90), Z(0));
}

