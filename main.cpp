#include<cmath>
#include<windows.h>
#include<GL/freeglut.h>
#include<stdlib.h>


float x = 90.0, y = 0.0, z = 0.0;
double shiftXaxis = 0.0;
double shiftZaxis = 0.0;
float angle=1.0;
float ROX=0,ROY=1;
double shiftCubeX = 0.0;
double shiftCubeZ = 0.0;

double Speed = 0.01;
double queen = 0;
int delay = 1000 / 60;
float eyeX = 0;
float eyeY = -0.2;
float eyeZ = -0.5;
float upX = 0;
float upY = 1;
float upZ = 0;

float shiftworldX = 0;
float shiftworldY = 0;
float shiftworldZ = 0;




void color(float R, float G, float B) {
    glColor3f(1.0f*R/255.0, 1.0f*G/255.0, 1.0f*B/255.0);
}

void reshapeFunc(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glTranslatef(0, -1, -1);
    glRotatef(-30, 1, 0, 0);
    gluPerspective(60.0, 2, 1, 50.0);
    glMatrixMode(GL_MODELVIEW);
}
void theme(void) {

    const GLfloat light_ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    const GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

    const GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f };
    const GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
    const GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    const GLfloat high_shininess[] = { 100.0f };

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
}

void MyInit(){
    glClearColor(0,153,50,204);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //Perspective Projection
    glFrustum(-1 , 1 , -1 , 1 , 2 , 10);
    glMatrixMode(GL_MODELVIEW);
    glColor3f(1,0,0);
}

void square() {
    glPushMatrix();
    glBegin(GL_QUADS);
    //front
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(-1.0, 1.0, 1.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(1.0, 1.0, 1.0);
    //back
    glColor3f(0.0, 1.0, 1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(-1.0, 1.0, -1.0);
    //right
    glColor3f(0.0, 0.36, 1.6);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(1.0, 1.0, -1.0);
    //left
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(-1.0, 1.0, -1.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(-1.0, 1.0, 1.0);
    //top
    glColor3f(0.0, 1.0, 1.0);
    glVertex3f(-1.0, 1.0, -1.0);
    glVertex3f(-1.0, 1.0, 1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, 1.0, -1.0);
    //bottom
    glColor3f(1.0, 0.0, 1.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(1.0, -1.0, -1.0);
    glEnd();
    glPopMatrix();
}
void tiangle(){

glPushMatrix();
glBegin(GL_TRIANGLES);
 glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);

    glVertex3f(-1.0f, -1.0f, 1.0f);

    glVertex3f(1.0f, -1.0f, 1.0f);
    // down face
    glColor3f(1.0f, 0.0f, 0.0f); //red
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f); //blue
    glVertex3f(1.0f, -1.0f, 1.0f);
    glColor3f(0.0f, 1.0f, 0.0f); //green
    glVertex3f(1.0f, -1.0f, -1.0f);
    //back
    glColor3f(1.0f, 0.0f, 0.0f); //red
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f); //green
    glVertex3f(1.0f, -1.0f, -1.0f);
    glColor3f(0.0f, 0.0f, 1.0f); //blue
    glVertex3f(-1.0f, -1.0f, -1.0f);
    //left
    glColor3f(1.0f, 0.0f, 0.0f); //reed
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f); //blue
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glColor3f(0.0f, 1.0f, 0.0f); //green
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glEnd();
glPopMatrix();


}
void queenanimated(){

//lower body
    glPushMatrix();
         glColor3f(1,0,1);
    glTranslated(0+ queen, 0.7, -10);

    glutSolidCube(1);
    glPopMatrix();
//chest

    glPushMatrix();
     glColor3f(1,0,0);
    glTranslated(0 + queen, 1.7, -10 );
    glutSolidCube(1);
    glPopMatrix();
//head//
    glPushMatrix();
     glColor3f(0,0,1);
    glTranslated(0 + queen, 2.5, -10 );
    glutSolidCube(0.6);
    glPopMatrix();
//right eye
    glPushMatrix();
    color(0, 0, 0);
    glTranslated(0.2+ queen, 2.5, -9.7);
   glutSolidSphere(0.08, 20, 20);
    glPopMatrix();
//left eye
    glPushMatrix();
    glTranslated(-0.2 +queen, 2.5, -9.7 );
    glutSolidSphere(0.08, 20, 20);
    glPopMatrix();
//nose
    glPushMatrix();
    glTranslated(0.01 + queen, 2.4, -9.6 );
    color(245, 127, 59);
    glutSolidCone(0.08,0.2,10,10);
    glPopMatrix();
//right hand
    glPushMatrix();
    glTranslated(0.5 + queen, 1.8, -10 );
    color(0, 0, 0);
     glRotatef(300, 1, 0, 0);

    glPopMatrix();
//left hand
    glPushMatrix();
    glTranslated(-0.5 + queen, 1.8, 10 );
    color(0, 0, 0);
    glRotatef(270, 1, 1, 0);

    glPopMatrix();
}


/*void teapot(){
gglMatrixMode(GL_MODELVIEW);
glRotatef(angle,ROX,ROY,0); //Rotate Around Y-axis
glutWireCube(30);
glColor3f(1,0,1);
glutWireTeapot(0.6);
glFlush();
glutSwapBuffers();
}
void specFunc(int key,int x,int y){
switch (key){
case GLUT_KEY_UP: angle++;break;
case GLUT_KEY_DOWN:if (angle>0) angle--;break;
case GLUT_KEY_RIGHT:ROX=0;ROY=1;break;
case GLUT_KEY_LEFT:ROY=0;ROX=1;break;


}*/
void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    glTranslatef(shiftworldX, shiftworldY, shiftworldZ);
    glPushMatrix();

    glTranslatef(0.0, -1, 0.0);
    color(111, 240, 72);
    glScalef(20, 1, 40);
    glutSolidCube(0.6);

    glPopMatrix();

    glPushMatrix();
    glTranslated(0+ shiftXaxis, 0.8, -10+ shiftZaxis);
    color(219, 218, 230);
    glutSolidCube(1);
    glPopMatrix();


    glPushMatrix();
    glTranslated(0 + shiftXaxis, 2, -10 + shiftZaxis);
    glutSolidCube(0.8);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0 + shiftXaxis, 3, -10 + shiftZaxis);
    glutSolidCube(0.4);
    glPopMatrix();

    glPushMatrix();
    color(0, 0, 0);
    glTranslated(0.2+ shiftXaxis, 3, -9.7+ shiftZaxis);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.2 + shiftXaxis, 3, -9.7 + shiftZaxis);
    glutSolidSphere(0.08, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.01 + shiftXaxis, 2.9, -9.6 + shiftZaxis);
    color(245, 127, 59);
    glutSolidCone(0.08,0.2,10,10);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.45 + shiftXaxis, 2.5, -10 + shiftZaxis);
    color(0, 0, 0);
    glRotatef(90,1,1,0);
    glutSolidCylinder(0.08,1.7,10,10);
    glPopMatrix();



    queenanimated();
    tiangle();
    square();
    //teapot();
    glutSwapBuffers();

}

void idleFunc(void)
{
    z += 1;
    glutPostRedisplay();
}

void timer(int value) {
    glutPostRedisplay();
    glutTimerFunc(delay, timer, 0);


    queen += Speed;
    if (queen > 5 || queen < -5) {
        Speed = -Speed;
    }

}
void world(unsigned char key, int x, int y) {
    switch (key) {
    case 'w':
       shiftworldZ  ++;
        break;
    case 's':
        shiftworldZ --;
        break;
    case 'd':
        shiftworldX--;
        break;
    case 'a':
        shiftworldX++;
        break;
    case 'q':
        shiftworldY--;
        break;
    case 'e':
        shiftworldY++;
        break;
    }
}
void queento(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_LEFT:
        shiftXaxis --;
        break;
    case GLUT_KEY_RIGHT:
        shiftXaxis ++;
        break;
    case GLUT_KEY_UP:
        shiftZaxis--;
        break;

    case GLUT_KEY_DOWN:
        shiftZaxis++;
        break;
    }

}
//void glutSolidCone(GLdouble base, GLdouble height,
                //   GLint slices, GLint stacks);
int main(int argc, char** argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(800, 700);
    glutInitWindowPosition(700, 200);
    glutCreateWindow("zeyad Ramadan20102876");
    glClearColor(1.0, 1.0, 1.0, 0.0);

    MyInit();
    glutDisplayFunc(display);
    glutReshapeFunc(reshapeFunc);
    glutKeyboardFunc(world);
    glutSpecialFunc(queento);
    glutIdleFunc(idleFunc);
    glutTimerFunc(0, timer, 0);

    glClearColor(221.0/255.0, 36.0/255.0, 227.0/255.0,1);
    theme();
   //PlaySound(TEXT(C:\Users\Zeyad Ramadan\Desktop\22go2od\MASTER\Action.wav), NULL, SND_FILENAME | SND_ASYNC);
    PlaySound("C:\\Users\\Zeyad Ramadan\\Desktop\\22go2od\\zeyadramadan20102876\\1.wav",SND_ASYNC);

    glutMainLoop();
    return 0;
}
