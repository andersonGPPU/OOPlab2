#ifndef RTG_H
#define RTG_H

#include "pointc.h"

class Rt {
public:
	Rt(float = 1.0, float = 1.0);
	~Rt();

	float g_Lgth();
	float g_Wdth();
	void g_Coord();

	void s_Lgth();
	void s_Wdth();
	void s_Pont();

private:
	float lgth, wdth;
	const float m_lgth{20}, m_wdth{20};

	bool checkL(float);
	bool checkW(float);

	Dot pts[4];
};

#endif
