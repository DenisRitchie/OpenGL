#include <Windows.h>
#include <glut.h>

void Display()
{
    glClearColor(0, 0, 0, 0);     // Color de fondo negro
    glClear(GL_COLOR_BUFFER_BIT); // Borramos la pantalla
    glMatrixMode(GL_PROJECTION);  // Modo de projection 
    glLoadIdentity();             // Cargamos la matriz de identidad
    glOrtho(-1, 1, -1, 1, -1, 1); // Proyecci�n ortogr�fica, dentro del cubo se�alado
    glMatrixMode(GL_MODELVIEW);   // Modo de modelado
    glBegin(GL_TRIANGLES);        // Dibujamos un triangulo
    glColor3f(1, 0, 0);           // Color del primer v�rtice: rojo
    glVertex3f(0, 0.8, 0);        // Coordenadas del primer v�rtice
    glColor3f(0, 1, 0);           // Color del segundo v�rtice: verde
    glVertex3f(-0.6, -0.2, 0);    // Coordenadas del segundo vertie 
    glColor3f(0, 0, 1);           // Color del tercer v�tice: azul
    glVertex3f(0.6, -0.2, 0);     // Coordenadas del tercer v�rtice
    glEnd();                      // Terminamos de dibujar

    // Triangulo del ejercicio
    glBegin(GL_TRIANGLES);
    glColor3f(0, 0, 1); // Azul
    glVertex3f(-0.6, -0.5, 0);
    glColor3f(1, 0, 0); // Rojo
    glVertex3f(-0.9, -0.9, 0);
    glColor3f(0, 1, 0); // Verde
    glVertex3f(-0.3, -0.9, 0);
    glEnd();

    // Triangulo del ejercicio
    glBegin(GL_TRIANGLES);
    glColor3f(0, 1, 0); // Verde
    glVertex3f(0.2, -0.5, 0);
    glColor3f(0, 0, 1); // Azul
    glVertex3f(-0.1, -0.9, 0);
    glColor3f(1, 0, 0); // Rojo
    glVertex3f(0.5, -0.9, 0);
    glEnd();

    glFlush(); // Forzamos el dibujado
}

int WINAPI wWinMain([[maybe_unused]] _In_ HINSTANCE hInstance, [[maybe_unused]] _In_opt_ HINSTANCE hPrevInstance, [[maybe_unused]] _In_ LPWSTR lpCmdLine, [[maybe_unused]] _In_ int nShowCmd)
{
    int ScreenX = GetSystemMetrics(SM_CXSCREEN);
    int ScreenY = GetSystemMetrics(SM_CYSCREEN);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowPosition((ScreenX / 2) - 250, (ScreenY / 2) - 250);
    glutInitWindowSize(500, 500);
    glutCreateWindow("OpenGL");
    glutDisplayFunc(Display);
    glutMainLoop();

    return 0;
}