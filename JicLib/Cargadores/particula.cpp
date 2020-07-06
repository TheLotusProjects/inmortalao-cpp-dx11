#include "particula.h"


particula::particula()
{
	frame_counter = 0.0;
	movement = false;
}

void particula::setName(std::string nameParam)
{
	name = nameParam;
}

bool particula::getAliveCounter() 
{

	if (alive_counter!=0)
		return true;

	return false;
}

bool particula::getNeverDie()
{
	return neverDie;
}

bool particula::getMovement()
{
	return movement;
}

void particula::decrementarAliveCounter()
{
	alive_counter = alive_counter - 1.0;
}

std::string particula::getName()
{
	return name;
}
void particula::setNumParticles(short int NumOfParticlesParam)
{
	NumOfParticles = NumOfParticlesParam;
}

short int particula::getNumParticles()
{
	return NumOfParticles;
}

void particula::setNumGrh(int NumGrhsParam)
{
	NumGrhs = NumGrhsParam;
}

int particula::getNumGrh()
{
	return NumGrhs;
}
void particula::setId(int idParam)
{
	id = idParam;
}

int particula::getId()
{
	return id;
}

void particula::setX1(int x1Param)
{
	x1 = x1Param;
}

int particula::getX1()
{
	return x1;
}

void particula::setY1(int y1Param)
{
	y1 = y1Param;
}


int particula::getY1()
{
	return y1;
}

void particula::setX2(int x2Param)
{
	x2 = x2Param;
}

int particula::getX2()
{
	return x2;
}

void particula::setY2(int y2Param)
{
	y2 = y2Param;
}


int particula::getY2()
{
	return y2;
}

void particula::setAngle(int angleParam)
{
	angle = angleParam;
}

double particula::getAngle()
{
	return angle;
}

double particula::getIndividualAngle(int indexParticulaIndividual)
{
	return particulasIndividuales[indexParticulaIndividual]->getAngle();
}

void particula::setVecX1(int vecx1Param)
{
	vecx1 = vecx1Param;
}

int particula::getVecX1()
{
	return vecx1;
}

void particula::setVectX2(int vecx2Param)
{
	vecx2 = vecx2Param;
}


int particula::getVectX2()
{
	return vecx2;
}

void particula::setVecY1(int vecy1Param)
{
	vecy1 = vecy1Param;
}

int particula::getVecY1()
{
	return vecy1;
}

void particula::setVecY2(int vecy2Param)
{
	vecy2 = vecy2Param;
}

int particula::getVecY2()
{
	return vecy2;
}

void particula::setLife1(int life1Param)
{
	life1 = life1Param;
}

int particula::getLife1()
{
	return life1;
}

void particula::setLife2(int life2Param)
{
	life2 = life2Param;
}

int particula::getLife2()
{
	return life2;
}

void particula::setFriction(int frictionParam)
{
	friction = frictionParam;
}

int particula::getFriction()
{
	return friction;
}

void particula::setSpin(char spinParam)
{
	spin = spinParam;
}


char particula::getSpin()
{
	return spin;
}

void particula::setSpinSpeedL(short int spin_speedLParam)
{
	spin_speedL = spin_speedLParam;
}

short int particula::getSpinSpeedL()
{
	return spin_speedL;
}

void particula::setSpinSpeedH(short int spin_speedHParam)
{
	spin_speedH = spin_speedHParam;
}

short int particula::getSpinSpeedH()
{
	return spin_speedH;
}

void particula::setAlphaBlend(char AlphaBlendParam)
{
	AlphaBlend = AlphaBlendParam;
}

char particula::getAlphaBlend()
{
	return AlphaBlend;
}

void particula::setGravity(char gravityParam)
{
	gravity = gravityParam;
}

char particula::getGravity()
{
	return gravity;
}

void particula::setGravStregth(int grav_strengthParam)
{
	grav_strength = grav_strengthParam;
}

int particula::getGravStregth()
{
	return grav_strength;
}

void particula::setBounceStrength(int bounce_strengthParam)
{
	bounce_strength = bounce_strengthParam;
}

int particula::getBounceStrength()
{
	return bounce_strength;
}

void particula::setXMove(int XMoveParam)
{
	XMove = XMoveParam;
}

int particula::getXMove()
{
	return XMove;
}

void particula::setYMove(int YMoveParam)
{
	YMove = YMoveParam;
}

int particula::getYMove()
{
	return YMove;
}

void particula::setMoveX1(int move_x1Param)
{
	move_x1 = move_x1Param;
}

int particula::getMoveX1()
{
	return move_x1;
}

void particula::setMoveX2(int move_x2Param)
{
	move_x2 = move_x2Param;
}

int particula::getMoveX2()
{
	return move_x2;
}

void particula::setMoveY1(int move_y1Param)
{
	move_y1 = move_y1Param;
}

int particula::getMoveY1()
{
	return move_y1;
}

void particula::setMoveY2(int move_y2Param)
{
	move_y2 = move_y2Param;
}

int particula::getMoveY2()
{
	return move_y2;
}

void particula::setGrhList(int* grh_listParam)
{
	grh_list = grh_listParam;
}

int* particula::getGrhLista()
{
	return grh_list;
}

void particula::setColorInt(unsigned char** colortintParam)
{
	colortint = colortintParam;
}

unsigned char** particula::getColorInt()
{
	return colortint;
}

void particula::setSpeed(double speedParam)
{
	speed = speedParam;
}

double particula::getSpeed()
{
	return speed;
}

float particula::getFrameCounter()
{
	return frame_counter;
}

void particula::setFrameCounter(float frameCounterParam)
{
	frame_counter = frame_counter+ frameCounterParam;
}

void particula::setLifeCounter(double life_counterParam)
{
	life_counter = life_counterParam;
	alive_counter = life_counter;

	if (life_counter == -1.0)
		neverDie = true;
	else
		neverDie = false;

}

double particula::getLifeCounter()
{
	return life_counter;
}

void particula::setGrhResize(bool grh_resizeParam)
{
	grh_resize = grh_resizeParam;
}

bool particula::getGrhResize()
{
	return grh_resize;
}

void particula::setGrhResizeX(short int grh_resizexParam)
{
	grh_resizex = grh_resizexParam;
}

short int particula::getGrhResizeX()
{
	return grh_resizex;
}

void particula::setGrhResizeY(short int grh_resizeyParam)
{
	grh_resizey = grh_resizeyParam;
}

short int particula::getGrhResizeY()
{
	return grh_resizey;
}

void particula::setParticulasIndividuales()
{
	particulasIndividuales = new particulaIndividual*[NumOfParticles];

	for (int i = 0; i < NumOfParticles; i++){
		particulasIndividuales[i] = new particulaIndividual(x1,x2,y1,y2,vecx1,vecx2,vecy1,vecy2,angle,life1,life2,friction,gravity,spin,grav_strength,bounce_strength,spin_speedL,spin_speedH,XMove,YMove,move_x1,move_x2,move_y1,move_y2,grh_list,NumGrhs);
	}

}

void particula::dibujar(int indexParticulaIndividual)
{
	if (!movement)particulasIndividuales[indexParticulaIndividual]->dibujar();
}

int particula::getParticleGrhIndex(int indexParticulaIndividual)
{
	return particulasIndividuales[indexParticulaIndividual]->getGrhIndex();
}

int particula::getParticleX(int indexParticulaIndividual)
{
	return particulasIndividuales[indexParticulaIndividual]->getX();
}

int particula::getParticleY(int indexParticulaIndividual)
{
	return particulasIndividuales[indexParticulaIndividual]->getY();
}

void particula::setMovement(bool movementParam)
{
	movement = movementParam;
}


particula::~particula()
{
}
