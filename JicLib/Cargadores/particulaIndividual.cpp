/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#include "particulaIndividual.h"


particulaIndividual::particulaIndividual(int x1Param, int x2Param, int y1Param, int y2Param, int vecx1Param, int vecx2Param, int vecy1Param, int vecy2Param, int angleParam, int life1Param, int life2Param, int frictionParam, char gravityParam, char	spinParam, int	grav_strengthParam, int	bounce_strengthParam, short int	spin_speedLParam, short int spin_speedHParam, int	XMoveParam, int	YMoveParam, int	move_x1Param, int	move_x2Param, int	move_y1Param, int	move_y2Param, int* listGrhParam, int numeroGraficosParam)
{
	x1=x1Param;
	x2=x2Param;
	y1=y1Param;
	y2=y2Param;
	vecx1=vecx1Param;
	vecx2=vecx2Param;
	vecy1=vecy1Param;
	vecy2=vecy2Param;
	angle=angleParam;
	life1=life1Param;
	life2=life2Param;
	friction=frictionParam;

	gravity = gravityParam;
	spin = spinParam;
	grav_strength = gravityParam;
	bounce_strength = bounce_strengthParam;
	spin_speedL = spin_speedLParam;
	spin_speedH = spin_speedHParam;
	XMove = XMoveParam;
	YMove = YMoveParam;
	move_x1 = move_x1Param;
	move_x2 = move_x2Param;
	move_y1 = move_y1Param;
	move_y2 = move_y2Param;

	listGrh = listGrhParam;
	numeroGraficos = numeroGraficosParam;
	
	alive_counter = 0;
}

double particulaIndividual::fRand(double fMin, double fMax)
{
	double f = (double)rand() / (RAND_MAX);
	
	return fMin + f * (fMax - fMin);
}


void particulaIndividual::dibujar()
{
	if (alive_counter == 0){
		X = fRand(x1, x2);
		Y = fRand(y1, y2);

		vector_x = fRand(vecx1, vecx2);
		vector_y = fRand(vecy1, vecy2);
		alive_counter = fRand(life1, life2);
		grh_index = listGrh[rand() % numeroGraficos];
	}
	else
	{
		if (gravity == 1)
		{
			vector_y = vector_y + grav_strength;
			if (Y > 0)vector_y = bounce_strength;
		}

		if (spin == 1) {
			double rand = fRand(spin_speedL, spin_speedH);
			angle = angle + (rand / (double)100);
		}

		if (angle >= 360){
			angle = 0;
		}

		if (XMove == 1) vector_x = fRand(move_x1, move_x2);
		if (YMove == 1) vector_y = fRand(move_y1, move_y2);
	}

	X = X + (vector_x / friction);
	Y = Y + (vector_y / friction);


	alive_counter = alive_counter - 1;
}

int particulaIndividual::getGrhIndex()
{
	return grh_index;
}

double particulaIndividual::getX()
{
	return X;
}

double particulaIndividual::getY()
{
	return Y;
}

double particulaIndividual::getAngle()
{
	return angle;
}

particulaIndividual::~particulaIndividual()
{
}
