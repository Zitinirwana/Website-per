#include<math.h>	
#include<stdio.h>	
#include<stdlib.h>	
#include<string.h>	
#include<stdarg.h>	
#include<GL/glut.h>	

void tampilan(void){
	glClearColor(1.0,1.0,1.0,0.0);		
	glMatrixMode(GL_PROJECTION);		
	gluOrtho2D(0.0, 160.0, 0.0, 120.0);		
}

void aturPixel(GLint xCoordinate, GLint yCoordinate){
	glBegin(GL_POINTS);		
	glVertex2i(xCoordinate, yCoordinate); 
	glEnd();	
	glFlush();	
}

void garisBresenham(GLint x0, GLint y0, GLint xEnd, GLint yEnd){
	GLint dx = xEnd - x0;
	GLint dy = yEnd - y0;
	GLint p = 2 * dy - dx;
	GLint twoDy = 2 * dy;
	GLint twoDyMinusDx = 2 * (dy-dx);
	GLint x, y;
	
	if (x0 > xEnd){
		x = xEnd;
		y = yEnd;
	}
	else{
		x = x0;
		y = y0;
	}
	
	//
	aturPixel(x,y);
	while (x < xEnd){	
			x++;	
		if (p <  0) 
			p += twoDy;
		else{	
			y++;	
			p += twoDyMinusDx;
		}
		aturPixel(x,y);
	}
}

void gambarGaris(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,1.0);		
	glPointSize(4.0);	
	GLint x0 = 10;		
	GLint y0 = 5;		
	GLint xEnd = 80;	
	GLint yEnd = 75;	

	garisBresenham(x0,y0,xEnd,yEnd);
}

int main (int argc, char** argv){	
	glutInit(&argc,argv);	
	glutInitDisplayMode(GLUT_SINGLE |GLUT_RGB);		
	glutInitWindowSize(400,400);	
	glutInitWindowPosition(0,0);	
	glutCreateWindow("Membuat Garis Algoritma Bresenham");	
	tampilan();		
	glutDisplayFunc(gambarGaris);	
	glutMainLoop();		
	return 0;	
}	