#ifndef _InputTeclas_H_
#define _InputTeclas_H_



class InputTeclas
{
public:
	InputTeclas();
	InputTeclas(const InputTeclas&);
	~InputTeclas();

	void Initialize();

	void KeyDown(unsigned int);
	void KeyUp(unsigned int);

	bool IsKeyDown(unsigned int);

private:
	bool m_keys[256];
};

#endif