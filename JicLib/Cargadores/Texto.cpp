#include "Texto.h"


Texto::Texto()
{
	fuentes = new std::map<int, int>();
	fuentesSombra = new std::map<int, int>();
}

int Texto::getIndexLetra(int ascii)
{
	return (*fuentes)[ascii];
}

int Texto::getIndexSombreLetra(int ascii)
{
	return (*fuentesSombra)[ascii];
}

void Texto::cargar()
{	

	//Textos faltantes, le pongo cualquier indexacion
	(*fuentes)[96] = 21452;
	(*fuentes)[126] = 21452;
	(*fuentes)[-31] = 21452;
	(*fuentes)[-23] = 21452;
	(*fuentes)[-19] = 21452;
	(*fuentes)[-13] = 21452;
	(*fuentes)[-6] = 21452;
	//

	(*fuentes)[48] = 21452;
	(*fuentes)[49] = 21453;
	(*fuentes)[50] = 21454;
	(*fuentes)[51] = 21455;
	(*fuentes)[52] = 21456;
	(*fuentes)[53] = 21457;
	(*fuentes)[54] = 21458;
	(*fuentes)[55] = 21459;
	(*fuentes)[56] = 21460;
	(*fuentes)[57] = 21461;
	for (int a = 0; a<26; a++) (*fuentes)[a + 97] = 21400 + a;
	for (int a = 0; a<26; a++) (*fuentes)[a + 65] = 21426 + a;
	(*fuentes)[33] = 21462;
	(*fuentes)[161] = 21463;
	(*fuentes)[34] = 21464;
	(*fuentes)[36] = 21465;
	(*fuentes)[191] = 21466;
	(*fuentes)[35] = 21467;
	(*fuentes)[36] = 21468;
	(*fuentes)[37] = 21469;
	(*fuentes)[38] = 21470;
	(*fuentes)[47] = 21471;
	(*fuentes)[92] = 21472;
	(*fuentes)[40] = 21473;
	(*fuentes)[41] = 21474;
	(*fuentes)[61] = 21475;
	(*fuentes)[39] = 21476;
	(*fuentes)[123] = 21477;
	(*fuentes)[125] = 21478;
	(*fuentes)[95] = 21479;
	(*fuentes)[45] = 21480;
	(*fuentes)[63] = 21465;
	(*fuentes)[64] = 21481;
	(*fuentes)[94] = 21482;
	(*fuentes)[91] = 21483;
	(*fuentes)[93] = 21484;
	(*fuentes)[60] = 21485;
	(*fuentes)[62] = 21486;
	(*fuentes)[42] = 21487;
	(*fuentes)[43] = 21488;
	(*fuentes)[46] = 21489;
	(*fuentes)[44] = 21490;
	(*fuentes)[58] = 21491;
	(*fuentes)[59] = 21492;
	(*fuentes)[124] = 21493;
	(*fuentes)[252] = 21800;
	(*fuentes)[220] = 21801;
	(*fuentes)[225] = 21802;
	(*fuentes)[233] = 21803;
	(*fuentes)[237] = 21804;
	(*fuentes)[243] = 21805;
	(*fuentes)[250] = 21806;
	(*fuentes)[253] = 21807;
	(*fuentes)[193] = 21808;
	(*fuentes)[201] = 21809;
	(*fuentes)[205] = 21810;
	(*fuentes)[211] = 21811;
	(*fuentes)[218] = 21812;
	(*fuentes)[221] = 21813;
	(*fuentes)[224] = 21814;
	(*fuentes)[232] = 21815;
	(*fuentes)[236] = 21816;
	(*fuentes)[242] = 21817;
	(*fuentes)[249] = 21818;
	(*fuentes)[192] = 21819;
	(*fuentes)[200] = 21820;
	(*fuentes)[204] = 21821;
	(*fuentes)[210] = 21822;
	(*fuentes)[217] = 21823;
	(*fuentes)[241] = 21824;
	(*fuentes)[209] = 21825;
	(*fuentes)[196] = 25238;
	(*fuentes)[194] = 25239;
	(*fuentes)[203] = 25240;
	(*fuentes)[207] = 25241;
	(*fuentes)[214] = 25242;
	(*fuentes)[212] = 25243;
	(*fuentes)[172] = 26193;
	/*
	(*fuentes)[48]= 21452;
	(*fuentes)[49] = 21453;
	(*fuentes)[50] = 21454;
	(*fuentes)[51] = 21455;
	(*fuentes)[52] = 21456;
	(*fuentes)[53] = 21457;
	(*fuentes)[54] = 21458;
	(*fuentes)[55] = 21459;
	(*fuentes)[56] = 21460;
	(*fuentes)[57] = 21461;

	for (int i = 0; i <= 25; i++)
		(*fuentes)[i + 97] = 21400 + i;

	for (int i = 0; i <= 25; i++)
		(*fuentes)[i + 65] = 21426 + i;

	(*fuentes)[33] = 21462;
	(*fuentes)[161] = 21463;
	(*fuentes)[34] = 21464;
	(*fuentes)[36] = 21465;
	(*fuentes)[191] = 21466;
	(*fuentes)[35] = 21467;
	(*fuentes)[36] = 21468;
	(*fuentes)[37] = 21469;
	(*fuentes)[38] = 21470;
	(*fuentes)[47] = 21471;
	(*fuentes)[92] = 21472;
	(*fuentes)[40] = 21473;
	(*fuentes)[41] = 21474;
	(*fuentes)[61] = 21475;
	(*fuentes)[39] = 21476;
	(*fuentes)[123] = 21477;
	(*fuentes)[125] = 21478;
	(*fuentes)[95] = 21479;
	(*fuentes)[45] = 21480;
	(*fuentes)[63] = 21465;
	(*fuentes)[64] = 21481;
	(*fuentes)[94] = 21482;
	(*fuentes)[91] = 21483;
	(*fuentes)[93] = 21484;
	(*fuentes)[60] = 21485;
	(*fuentes)[62] = 21486;
	(*fuentes)[42] = 21487;
	(*fuentes)[43] = 21488;
	(*fuentes)[46] = 21489;
	(*fuentes)[44] = 21490;
	(*fuentes)[58] = 21491;
	(*fuentes)[59] = 21492;
	(*fuentes)[124] = 21493;
	(*fuentes)[252] = 21800;
	(*fuentes)[220] = 21801;
	(*fuentes)[225] = 21802;
	(*fuentes)[233] = 21803;
	(*fuentes)[237] = 21804;
	(*fuentes)[243] = 21805;
	(*fuentes)[250] = 21806;
	(*fuentes)[253] = 21807;
	(*fuentes)[193] = 21808;
	(*fuentes)[201] = 21809;
	(*fuentes)[205] = 21810;
	(*fuentes)[211] = 21811;
	(*fuentes)[218] = 21812;
	(*fuentes)[221] = 21813;
	(*fuentes)[224] = 21814;
	(*fuentes)[232] = 21815;
	(*fuentes)[236] = 21816;
	(*fuentes)[242] = 21817;
	(*fuentes)[249] = 21818;
	(*fuentes)[192] = 21819;
	(*fuentes)[200] = 21820;
	(*fuentes)[204] = 21821;
	(*fuentes)[210] = 21822;
	(*fuentes)[217] = 21823;
	(*fuentes)[241] = 21824;
	(*fuentes)[209] = 21825;
	(*fuentes)[196] = 25238;
	(*fuentes)[194] = 25239;
	(*fuentes)[203] = 25240;
	(*fuentes)[207] = 25241;
	(*fuentes)[214] = 25242;
	(*fuentes)[212] = 25243;
	
	
	(*fuentesSombra)[97] = 21936;
	(*fuentesSombra)[108] = 21937;
	(*fuentesSombra)[115] = 21938;
	(*fuentesSombra)[70] = 21939;
	(*fuentesSombra)[48] = 21940;
	(*fuentesSombra)[49] = 21941;
	(*fuentesSombra)[50] = 21942;
	(*fuentesSombra)[51] = 21943;
	(*fuentesSombra)[52] = 21944;
	(*fuentesSombra)[53] = 21945;
	(*fuentesSombra)[54] = 21946;
	(*fuentesSombra)[55] = 21947;
	(*fuentesSombra)[56] = 21948;
	(*fuentesSombra)[57] = 21949;
	(*fuentesSombra)[33] = 21950;
	(*fuentesSombra)[161] = 21951;
	(*fuentesSombra)[42] = 21952;
	*/
}

Texto::~Texto()
{
	delete fuentes;
	delete fuentesSombra;
}
