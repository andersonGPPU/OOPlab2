#include "rtg.h"
#include <iostream>

Rt::Rt(float a, float b) {
	lgth = a; wdth = b; s_Pont();
}
Rt::~Rt() {

}

float Rt::g_Lgth() { return lgth; }

float Rt::g_Wdth() { return wdth; }

void Rt::g_Coord() {
	for (int i = 0; i < 4; pts[i].eCoord(), i++);
}
void Rt::s_Lgth() {
	float l{};
	std::cout << "Qual o comprimento 'L' do quadrado: ";
	do {
		std::cin >> l;
	} while (checkL(l));
	lgth = l;
}
void Rt::s_Wdth() {
	float w{};
	std::cout << "Qual a largura 'W' do quadrado: ";
	do {
		std::cin >> w;
	} while (checkL(w));
	wdth = w;
}
void Rt::s_Pont() {
	for (int l = 0; l < 2; l++){
		for (int w = 0; w < 2; pts[2 * l + w].sCoord(l * lgth, w * wdth), w++);
	}
}
bool Rt::checkL(float x) {
	if ((x < 0) || (x > m_lgth)) {
		std::cout << "Comprimento 'L' deve estar entre '0' (zero) e '20' (vinte)." << std::endl;
		std::cout << "Entre novamente com um novo comprimento 'L': ";
		return true;
	}
	else return false;
}
bool Rt::checkW(float y) {
	if ((y < 0) || (y > m_lgth)) {
		std::cout << "Largura 'W' deve estar entre '0' (zero) e '20' (vinte)." << std::endl;
		std::cout << "Entre novamente com um novo Largura 'W': ";
		return true;
	}
	else return false;
}