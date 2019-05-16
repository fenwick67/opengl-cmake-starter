
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>


//screen aspect ratio
float aspect = 1.0;
static GLfloat spin = 0.0;

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(spin,     1.0, 0.0, 0.0);
    glRotatef(spin*2.0, 0.0, 1.0, 0.0);
    glRotatef(spin*3.0, 0.0, 0.0, 1.0);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    
    // draw CUBE    

    glBegin(GL_POLYGON);// front (yel)
        glColor3f(1.0, 1.0, 0.0);        
        glVertex3f(-0.5, -0.5, -0.5);
        glVertex3f(-0.5, 0.5, -0.5);
        glVertex3f(0.5, 0.5, -0.5);
        glVertex3f(0.5, -0.5, -0.5);
    glEnd();
    glBegin(GL_POLYGON);// back (blu)
        glColor3f(0.0, 0.0, 1.0);
        glVertex3f(0.5, -0.5, 0.5);
        glVertex3f(0.5, 0.5, 0.5);
        glVertex3f(-0.5, 0.5, 0.5);
        glVertex3f(-0.5, -0.5, 0.5);
    glEnd();
    glBegin(GL_POLYGON);// right (grn)
        glColor3f(0.0, 1.0, 0.0);
        glVertex3f(0.5, -0.5, -0.5);
        glVertex3f(0.5, 0.5, -0.5);
        glVertex3f(0.5, 0.5, 0.5);
        glVertex3f(0.5, -0.5, 0.5);
    glEnd();
    glBegin(GL_POLYGON);// left (red)
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(-0.5, -0.5, 0.5);
        glVertex3f(-0.5, 0.5, 0.5);
        glVertex3f(-0.5, 0.5, -0.5);
        glVertex3f(-0.5, -0.5, -0.5);
    glEnd();
    glBegin(GL_POLYGON);// top (cyan)
        glColor3f(0.0, 1.0, 1.0);
        glVertex3f(0.5, 0.5, 0.5);
        glVertex3f(0.5, 0.5, -0.5);
        glVertex3f(-0.5, 0.5, -0.5);
        glVertex3f(-0.5, 0.5, 0.5);
    glEnd();
    glBegin(GL_POLYGON);// bottom (magenta)
        glColor3f(1.0, 0.0, 1.0);
        glVertex3f(0.5, -0.5, -0.5);
        glVertex3f(0.5, -0.5, 0.5);
        glVertex3f(-0.5, -0.5, 0.5);
        glVertex3f(-0.5, -0.5, -0.5);
    glEnd();
    
   

    glPopMatrix();


    // draw overlay
    glDepthMask(GL_FALSE);
    glDisable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();

    glOrtho(-1.0*aspect, 1.0*aspect, -1.0, 1.0, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    glRotatef(spin, 0.0, 0.0, 1.0);

    glColor4f(1.0, 1.0, 1.0, 0.5);
    glRectf(-0.25,-0.25,0.25,0.25);


    // undo what we did
    glMatrixMode(GL_MODELVIEW); //redundant but clearer
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glDepthMask(GL_TRUE);
    glEnable(GL_DEPTH_TEST);

    glutSwapBuffers();

}

void spinDisplay(void){
    spin = spin + 0.01;
    if (spin > 360.0){
        spin = spin - 360.0;
    }
    glutPostRedisplay();
}

void init(void){
    // clear background color
    glClearColor(0.0,0.0,0.0,0.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_CULL_FACE);
    glFrontFace(GL_CCW);
}

void reshape(int w, int h){
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    // move the model away
    glTranslatef(0.0,0.0,-2.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    aspect = ((float) w / (float) h);
    gluPerspective(90.0, aspect, 1.0, 10.0);
    // glOrtho(-5.0, 5.0, -5.0, 5.0, -5.0, 5.0);
    // glFrustum(-5.0,5.0,-5.0,5.0,1.0,10.0);
}

void mouse(int button, int state, int x, int y){

    switch(button){
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_DOWN)
                glutIdleFunc(spinDisplay);
            break;
        case GLUT_MIDDLE_BUTTON:
            if (state == GLUT_DOWN)
                glutIdleFunc(NULL);
            break;
        default:
            break;
    }
}

int main(int argc, char** argv){
    // fprintf(stdout, "howdy");
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(250,250);
    glutInitWindowPosition(100,100);
    glutCreateWindow("hello");
    init ();
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}
