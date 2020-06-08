#include <windows.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
float  rulerY = -0.7 , rulerX = 0.2 ,  ballX = 0 , ballY = 0  ;
float BalldeltaX = 0.0003 , BalldeltaY = 0.001 ;
int sq[10] = {1,1,1,1,1,1,1,1,1,1};

void hide (float x ) {
if ( x >= 0.4 && x < 0.6  )
    sq[7] = 0 ;
else if ( x >= -1 && x < -0.8 )
    sq[0] = 0 ;
else if ( x >= -0.8 && x < -0.6 )
    sq[1] = 0 ;
else if ( x >= -0.6 && x < -0.4  )
     sq[2] = 0 ;
else if (  x >= -0.4 && x < -0.2 )
     sq[3] = 0 ;
else if ( x >= -0.2 && x < 0  )
     sq[4] = 0 ;
else if ( x >= 0 && x < 0.2 )
    sq[5] = 0 ;
else if ( x >= 0.2 && x < 0.4 )
    sq[6] = 0 ;
else if ( x >= 0.6 && x < 0.8 )
    sq[8] = 0 ;
else if ( x >= 0.8 )
    sq[9] = 0 ;
}

void display(){
glClearColor(1,1,1,1);
glClear(GL_COLOR_BUFFER_BIT);
glLineWidth(150) ;
glBegin(GL_LINES);
glColor3f(0,0,1);
glVertex2f( rulerX - 0.4 , rulerY);
glVertex2f( rulerX , rulerY);
glEnd();

glPointSize(15);
glEnable(GL_POINT_SMOOTH);
glBegin(GL_POINTS) ;
glColor3f(1 , 0 ,0 );
glVertex2f( ballX , ballY  );
glEnd() ;

int i = 0 ;
for( ; i < 10 ; i++ ){
    if( sq[i] == 0 )
       continue ;
    float s = -1 + i*0.2 ;
    glColor3f( 0 ,1 , 0);
    glBegin(GL_QUAD_STRIP) ;
    glVertex2f( s , 1 ) ;
    glVertex2f( s + 0.2 , 1 );
    glVertex2f ( s , 0.8 ) ;
    glVertex2f ( s + 0.2 , 0.8 ) ;
    glEnd();
}

//ball animation
ballX += BalldeltaX ;
ballY += BalldeltaY ;



if( ballX <= rulerX && ballX >= (rulerX - 0.4) && ballY <= rulerY + 0.015 && ballY >= rulerY - 0.015    ) {
     BalldeltaY *= -1 ;
    // BalldeltaX *= -1 + 2*BalldeltaX ;
}
else if ( ballY >= 0.785 ){
    hide(ballX) ;
    BalldeltaY *= -1 ;

}

if( ballX >= 0.975 || ballX <= -0.975 )
   BalldeltaX *= -1 ;
if(ballY >= 1 || ballY <= -1 )
     BalldeltaY *= -1 ;


glutPostRedisplay();
glFlush();
}

static void keyboard(int key , int x , int y ) {
   float deltaX = 0.05 ;
   if( key == GLUT_KEY_RIGHT && rulerX < 1)
    rulerX += deltaX ;
   else if ( key == GLUT_KEY_LEFT && rulerX > -0.58 )
    rulerX -= deltaX ;
   glutPostRedisplay();
}

int  main (int argc, char *argv[]) {
    glutInit( & argc, argv );

glutInitWindowPosition(50,50);
glutInitWindowSize(600,600);
glutCreateWindow("Game");
glutSpecialFunc(keyboard);
glutDisplayFunc(display);
glutMainLoop();
}
