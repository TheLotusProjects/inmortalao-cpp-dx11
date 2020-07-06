#pragma once
#include <math.h>
#include <iostream>

class particulaIndividual
{
private:
	int alive_counter;
	int numeroGraficos;

	int grh_index;
	int* listGrh;
	double X;
	double Y;
	int x1;
	int x2;
	int y1;
	int y2;
	double vector_x;
	int vecx1;
	int vecx2;
	double vector_y;
	int vecy1;
	int vecy2;
	double angle;
	int life1;
	int life2;
	double friction;
	char gravity;
	char spin;
	int grav_strength;
	int bounce_strength;
	short int spin_speedL;
	short int spin_speedH;
	int XMove;
	int YMove;
	int move_x1;
	int move_x2;
	int move_y1;
	int move_y2;
public:
	particulaIndividual(int x1Param, int x2Param, int y1Param, int y2Param, int vecx1Param, int vecx2Param, int vecy1Param, int vecy2Param, int angleParam, int life1Param, int life2Param, int frictionParam, char gravity, char	spinParam, int	grav_strengthParam, int	bounce_strengthParam, short int	spin_speedLParam, short int spin_speedHParam, int	XMoveParam, int	YMoveParam, int	move_x1Param, int	move_x2Param, int	move_y1Param, int	move_y2Param, int* listGrhParam, int numeroGraficosParam);
	void dibujar();
	int getGrhIndex();
	double getAngle();
	double getX();
	double getY();
	double fRand(double fMin, double fMax);
	~particulaIndividual();
};

