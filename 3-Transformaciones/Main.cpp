#include "Main.hpp"

GLdouble angulo_cubo_x = 0;
GLdouble angulo_cubo_y = 0;
GLdouble angulo_esfera = 0;

GLint alto = 400;
GLint ancho = 400;

bool haz_perspectiva = false;

void Init();
void Idle();
void Display();
void Reshape(int width, int height);
void Keyboard(unsigned char key, int x, int y);
void DrawCube();

int WINAPI wWinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPWSTR, _In_ INT32)
{
    const auto &[x, y, width, height] = GetBound(1'000, 500);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(x, y);
    glutCreateWindow("Transformaciones");
    Init();
    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    glutIdleFunc(Idle);
    glutKeyboardFunc(Keyboard);
    glutMainLoop();
    return EXIT_SUCCESS;
}

inline void Init()
{
    glClearColor(0, 0, 0, 0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    alto = 400;
    ancho = 400;
}

inline void Idle()
{
    Display();
}

inline void Reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (haz_perspectiva)
    {
        gluPerspective(60, static_cast<GLdouble>(width) / static_cast<GLdouble>(height), 1, 20);
    }
    else
    {
        glOrtho(-4, 4, -4, 4, -10, 10);
    }

    glMatrixMode(GL_MODELVIEW);
    ancho = width;
    alto = height;
}

inline void Display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    glTranslated(0, 0, -5);
    glRotated(angulo_cubo_x, 1, 0, 0);
    glRotated(angulo_cubo_y, 0, 1, 0);

    DrawCube();

    glLoadIdentity();

    glTranslated(0, 0, -5);
    glRotated(angulo_esfera, 0, 1, 0);
    glTranslated(3, 0, 0);

    glColor3d(1, 1, 1);
    glutWireSphere(0.5, 8, 8);

    glFlush();
    glutSwapBuffers();

    angulo_cubo_x += 0.1;
    angulo_cubo_y += 0.1;
    angulo_esfera += 0.2;
}

inline void DrawCube()
{
    // Cara Frontal
    glColor3d(1, 0, 0);
    glBegin(GL_QUADS);
    {
        glVertex3d(-1, -1, 1);
        glVertex3d(1, -1, 1);
        glVertex3d(1, 1, 1);
        glVertex3d(-1, 1, 1);
    }
    glEnd();

    // Cara Trasera
    glColor3d(0, 1, 0);
    glBegin(GL_QUADS);
    {
        glVertex3d(1, -1, -1);
        glVertex3d(-1, -1, -1);
        glVertex3d(-1, 1, -1);
        glVertex3d(1, 1, -1);
    }
    glEnd();

    // Cara Lateral Izquierda
    glColor3d(0, 0, 1);
    glBegin(GL_QUADS);
    {
        glVertex3d(-1, -1, -1);
        glVertex3d(-1, -1, 1);
        glVertex3d(-1, 1, 1);
        glVertex3d(-1, 1, -1);
    }
    glEnd();

    // Cara Lateral Derecha
    glColor3d(1, 1, 0);
    glBegin(GL_QUADS);
    {
        glVertex3f(1, -1, 1);
        glVertex3f(1, -1, -1);
        glVertex3f(1, 1, -1);
        glVertex3f(1, 1, 1);
    }
    glEnd();

    // Cara Arriba
    glColor3f(0, 1, 1);
    glBegin(GL_QUADS);
    {
        glVertex3f(-1, 1, 1);
        glVertex3f(1, 1, 1);
        glVertex3f(1, 1, -1);
        glVertex3f(-1, 1, -1);
    }
    glEnd();

    // Cara Abajo
    glColor3f(1, 0, 1);
    glBegin(GL_QUADS);
    {
        glVertex3f(1, -1, -1);
        glVertex3f(1, -1, 1);
        glVertex3f(-1, -1, 1);
        glVertex3f(-1, -1, -1);
    }
    glEnd();
}

inline void Keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'p': case 'P':
        {
            haz_perspectiva = true;
            Reshape(ancho, alto);
            break;
        }

        case 'o': case 'O':
        {
            haz_perspectiva = false;
            Reshape(ancho, alto);
            break;
        }

        case 27: // Esc
        {
            ExitProcess(0);
            break;
        }
    }
}
