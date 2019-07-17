#include <framework.h>
#include <stdlib.h>

void Display()
{
    OpenGL::ClearColor::Call();
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    OpenGL::Begin(OpenGL::BeginMode::Triangles);

    OpenGL::End();
    glFlush();
}

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpszCmdLine, _In_ INT32 nCmdShow)
{
    int screen_width = GetSystemMetrics(SM_CXSCREEN), screen_height = GetSystemMetrics(SM_CYSCREEN), width = 500, height = 500;
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowPosition(screen_width / 2 - width / 2, screen_height / 2 - height / 2);
    glutInitWindowSize(width, height);
    glutCreateWindow("Prácticas OpenGL");
    glutDisplayFunc(Display);
    glutMainLoop();
    return EXIT_SUCCESS;
}
