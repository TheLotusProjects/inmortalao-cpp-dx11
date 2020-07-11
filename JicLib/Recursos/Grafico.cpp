/*
Author: Jose Ignacio Castelli
Email: joseignaciocastelli@gmail.com
Github: https://github.com/JicLotus
Medium Page: https://medium.com/@joseignaciocastelli92
Date: 01/01/2017
*/

#include "Grafico.h"


Grafico::Grafico(Recursos* recursosParam, ID3D11Device* renderParam, ID3D11DeviceContext* deviceContextParam,float blendParam)
{
	blend = blendParam;
	recursos = recursosParam;
	render = renderParam;
	deviceContext= deviceContextParam;
	
	m_position = D3DXVECTOR4(0, 0, 0, 0);
	m_velocity = D3DXVECTOR4(0, 0, 0, 0);
	
	m_sprite = NULL;
}

void Grafico::definirTextura(int indexGrafico)
{
	getDimensionesGrafico(indexGrafico);
	graficoTextura = cargarImagen(indexGrafico);
}

void Grafico::setEmpezado(bool empezado)
{
	((AnimatedSprite*)m_sprite)->setEmpezado(empezado);
}

Textura* Grafico::cargarImagen(int indexGrafico)
{
	std::string strNumeroGrafico;
	numeroGrafico = recursos->GetGrafico(indexGrafico);


	std::stringstream stream; stream << numeroGrafico;
	strNumeroGrafico = stream.str();

	return cargarGrafico(numeroGrafico, strNumeroGrafico);
}

void Grafico::getDimensionesGrafico(int indexGrafico)
{
	Sx = recursos->GetXGrafico(indexGrafico);
	Sy = recursos->GetYGrafico(indexGrafico);
	W = recursos->GetWGrafico(indexGrafico);
	H = recursos->GetHGrafico(indexGrafico);
}

Textura* Grafico::getTextura()
{
	return graficoTextura;
}

Textura* Grafico::cargarGrafico(int numeroGrafico, std::string strNumeroGrafico)
{
	return recursos->cargarGrafico(numeroGrafico, strNumeroGrafico);
}


void Grafico::InitializeSprite()
{
	m_sprite = new Sprite(recursos,Sx,Sy);
	m_sprite->Initialize(render, deviceContext, recursos->getShader(), numeroGrafico, W, H,true);
}

void Grafico::InitializeAnimatedSprite( int indexGrafico, float animationSpeed, bool isLooping)
{
	int indexFrame = recursos->getIndexFrame(indexGrafico,0);
	int speed = 1;//recursos->GetSpeedGrh(indexFrame);
	this->setNumFrames(indexGrafico);
	cargarImagen(indexFrame);

	W = recursos->GetWGrafico(indexGrafico);
	H = recursos->GetHGrafico(indexGrafico);
	std::map<int, int>* sX = new std::map<int, int>();
	std::map<int, int>* sY = new std::map<int, int>();
	std::map<int, int>* we = new std::map<int, int>();
	std::map<int, int>* he = new std::map<int, int>();

	int sx, sy, w, h;

	for (int i=0; i<numFrames; i++)
	{
		indexFrame = recursos->getIndexFrame(indexGrafico, i);
		sx = recursos->GetXGrafico(indexFrame);
		sy = recursos->GetYGrafico(indexFrame);
		w = recursos->GetWGrafico(indexFrame);
		h = recursos->GetHGrafico(indexFrame);
		(*sX)[i] = sx;
		(*sY)[i] = sy;
		(*we)[i] = w;
		(*he)[i] = h;
	}

	m_sprite = new AnimatedSprite(recursos,Sx,Sy,speed);
	((AnimatedSprite*)m_sprite)->setDimensiones(W,H,sX,sY);
	((AnimatedSprite*)m_sprite)->Initialize(render, deviceContext, recursos->getShader(), numeroGrafico,numFrames);
}

void Grafico::setFramesPerSecond(int framesPerSecond)
{
	((AnimatedSprite*)m_sprite)->setFramePerSecond(framesPerSecond);
}

void Grafico::Update(D3DXMATRIX worldMatrix)
{
	//float dt = Timer::GetDeltaTime();

	/*m_position += m_velocity * 0.025;
	m_velocity *= 0.96f;*/

	if (m_sprite)
	{
		m_sprite->Update();
	}
	m_worldMatrix = worldMatrix;
	D3DXMatrixTranslation(&m_worldMatrix, m_position.x, m_position.y, m_position.z);
}

void Grafico::ajustarImagen(){
	m_sprite->UpdateASD();
}


void Grafico::setColor(unsigned char* color1Param, unsigned char* color2Param, unsigned char* color3Param, unsigned char* color4Param)
{
	m_sprite->setColor(color1Param, color2Param, color3Param, color4Param);
}

void Grafico::girar(float angulo, D3DXMATRIX worldMatrix)
{
	D3DXMATRIX rotation;
	D3DXMATRIX translation;
	

	D3DXMatrixRotationZ(&rotation, angulo* -10 * (3.141592653589793238462643383279 / 180.0f));
	D3DXMatrixTranslation(&translation, m_position.x, m_position.y, m_position.z);

	D3DXMatrixMultiply(&m_worldMatrix,&rotation,&translation);
	//D3DXMatrixTranslation(&m_worldMatrix, m_position.x, m_position.y, m_position.z);
}


void Grafico::dibujar(ID3D11DeviceContext* deviceContext, D3DXMATRIX viewMatrix, D3DXMATRIX projectionMatrix,float blendAmount)
{
	if (m_sprite)
	{
		m_sprite->Render(deviceContext, m_worldMatrix, viewMatrix, projectionMatrix,blendAmount);
	}
}

void Grafico::setDimensionPantalla(int anchoPantallaParam, int altoPantallaParam)
{
	altoPantalla = altoPantallaParam;
	anchoPantalla = anchoPantallaParam;
}

void Grafico::SetPosition(float x, float y)
{

	float left = (float)(anchoPantalla / 2 * -1) + (float)x + W/2;
	float top = (float)(altoPantalla / 2) - (float)y - H / 2;
	//float right = left + (float)W;
	//float bottom = top - (float)H;

	/*
	float radius;
	float left_point;
	float x_center;
	float y_center;

	if (angulo > 0){
		//Center coordinates on screen of the square
		x_center = left + (right - left) / 2;
		y_center = top + (bottom - top) / 2;

		//Calculate radius
		radius = sqrt((right - x_center) * (right - x_center) + (bottom - y_center) *(bottom - y_center));

		//Calculate left and right points
		float temp = (right - x_center) / radius;
		float right_point = atan(temp / sqrt(-temp * temp + 1));
		left_point = 3.141592653589793238462643383279 - right_point;
	}

	float x_Cor, y_Cor;

	//Calculate screen coordinates of sprite, and only rotate if necessary
	if (angulo == 0){
		x_Cor = left;
		y_Cor = bottom;
	}
	else{
		x_Cor = x_center + cos(-left_point - angulo) * radius;
		y_Cor = y_center - sin(-left_point - angulo) * radius;
	}
	*/
	m_position.x = left;
	m_position.y = top;
	m_position.z = 0;
	m_position.w = 1.0;	
}

void Grafico::SetVelocity(float x, float y)
{
	m_position.x = x;
	m_position.y = y;
	m_position.z = 0;
	m_position.w = 1.0;
}

void Grafico::setNumFrames(int indexGrafico)
{
	numFrames = recursos->GetFrameCount(indexGrafico);
}

Grafico::~Grafico()
{
	if (m_sprite != NULL)
	{
		delete m_sprite;
		m_sprite = NULL;
	}
}

