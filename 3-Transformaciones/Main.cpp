#include "Main.hpp"

GLdouble angulo_cubo_x = 0;
GLdouble angulo_cubo_y = 0;
GLdouble angulo_esfera = 0;
GLdouble fovy = 60.0;
GLdouble perspective_z_near = 1.0;
GLdouble perspective_z_far = 20.0;
GLdouble translate_z = -5;

GLint alto = 500;
GLint ancho = 1'000;

bool haz_perspectiva = false;

void Init();
void Idle();
void Display();
void Reshape(int width, int height);
void Keyboard(unsigned char key, int x, int y);
void SpecialKey(int key, int x, int y);
void DrawCube();

int WINAPI wWinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPWSTR, _In_ INT32)
{
    const auto &[x, y, width, height] = GetBound(ancho, alto);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(x, y);
    glutCreateWindow("Transformaciones");
    Init();
    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    glutIdleFunc(Idle);
    glutKeyboardFunc(Keyboard);
    glutSpecialFunc(SpecialKey);
    glutMainLoop();
    return EXIT_SUCCESS;
}

inline void Init()
{
    glClearColor(0, 0, 0, 0);
    glEnable(GL_DEPTH_TEST);
    fovy = 60;
    alto = 400;
    ancho = 400;
    translate_z = -5;
    perspective_z_near = 1.0;
    perspective_z_far = 20.0;
}

inline void Idle()
{
    glutPostRedisplay();
}

inline void Reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (haz_perspectiva)
    {
        // https://docs.microsoft.com/en-us/windows/win32/opengl/gluperspective
        // fovy:   Es la circunferencia que usa el ojo de la cámara, este esta expresado en grados (ángulo).
        //         El ángulo debe tener un valor: 0 < θ < 180°
        // aspect: Esta definido por la división entre en ancho y el alto.
        // zNear:  Establece la profundidad del objecto, es la distancia mas cercana respecto a la cámara. 
        //         Debe ser un valor positivo mayor a cero.
        //         Si el valor z de glTranslated tiene una valor cercano a zNear este estara muy cerca de la cámara haciendo el objeto muy grande a nuestros ojos.
        //         zNear > z > Negativo zFar
        // zFar:   Establece la profundidad del objecto, es la distancia mas lejana respecto a la cámara.
        //         Debe ser un valor positivo mayor a cero.
        //         Si el valor z de glTranslated tiene una valor cercano a zFar en negativo este estara muy lejos de la cámara haciendo el objeto muy pequeño a nuestros ojos.
        //         zNear > z > Negativo zFar
        // El valor negativo en z, es la distancia que hay del viewport o cara frontal del objecto respecto a la cámara.
        // El valor z de glTranslated, es usado para definir que tan cerca o lejos esta el objeto con respecto a la cámara.
        // Nota: La cámara esta ubica en el eje z negativo, por tanto esta detras de las figuras que dibujamos.
        //       Si glTranslated le damos un z negativo estamos alejandonos de la cámara y veremos el gráfico mas pequeño,
        //       y si damos un z positivo estamos acercandonos a la cámara haciendo el gráfico mas grande a nuestros ojos.
        //       zFar - ZNear = Distancia de visualización de los objetos.
        gluPerspective(fovy, (GLdouble)width / (GLdouble)height, perspective_z_near, perspective_z_far);
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

    glTranslated(0, 0, translate_z);
    glRotated(angulo_cubo_x, 1, 0, 0);
    glRotated(angulo_cubo_y, 0, 1, 0);

    DrawCube();

    glLoadIdentity();

    glTranslated(0, 0, translate_z);
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
    const GLint modifier = glutGetModifiers();

    switch (key)
    {
        case 'a': case 'A':
        {
            if (haz_perspectiva)
            {
                ++translate_z;

                // perspective_z_near se disminuye en uno para que la figura no este 
                // tan cerca de la cámara y quedar fuera del campo de visión
                if (translate_z > (perspective_z_near - 1))
                    translate_z = perspective_z_near - 1;

                Reshape(ancho, alto);
            }
            break;
        }

        case 'd': case 'D':
        {
            if (haz_perspectiva)
            {
                --translate_z;

                if (translate_z < -perspective_z_far)
                    translate_z = -perspective_z_far;

                Reshape(ancho, alto);
            }
            break;
        }

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

        case '+':
        {
            ++fovy;

            if (fovy >= 180.0)
                fovy = 179;

            Reshape(ancho, alto);
            break;
        }

        case '-':
        {
            --fovy;

            if (fovy <= 0.0)
                fovy = 1.0;

            Reshape(ancho, alto);
            break;
        }

        case '\xe': // Ctrl + N
        {
            if ((modifier & GLUT_ACTIVE_CTRL) == GLUT_ACTIVE_CTRL)
            {
                ++perspective_z_near;
            }

            Reshape(ancho, alto);
            break;
        }

        case 'n': case 'N':
        {
            --perspective_z_near;

            if (perspective_z_near < 1.0)
                perspective_z_near = 1.0;

            Reshape(ancho, alto);
            break;
        }


        case '\x6': // Ctrl + F
        {
            if ((modifier & GLUT_ACTIVE_CTRL) == GLUT_ACTIVE_CTRL)
            {
                --perspective_z_far;

                if (perspective_z_far < 1.0)
                    perspective_z_far = 1.0;
            }

            Reshape(ancho, alto);
            break;
        }

        case 'f': case 'F':
        {
            ++perspective_z_far;
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

inline void SpecialKey(int key, int x, int y)
{
}