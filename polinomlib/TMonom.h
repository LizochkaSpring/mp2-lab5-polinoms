#pragma once
#include<functional>
using namespace std;
struct TMonom
{
	double coef; // коэффициент монома
	int index; // индекс (свертка степеней)

	TMonom(){
		coef = 0;
		index = 0;
	}

	TMonom(double coef_arg, int degX, int degY, int degZ) : coef(coef_arg){
		if (degX < 0 || degY < 0 || degZ < 0) throw invalid_argument("Степени должны быть неотрицательными");
		if (coef_arg == 0) throw invalid_argument("Коэффициент не может быть равен нулю");
		index = degX + degY * 10 + degZ * 100;
	}

	void SetCoef(int cval) { 
		this->coef = cval; 
	}
	int GetCoef(void) { 
		return this->coef; 
	}

	void SetIndex(int ival) { 
		this->index = ival; 
	}
	int GetIndex(void) { 
		return this->index; 
	}


	bool operator==(const TMonom& other) {
		return (this->coef == other.coef) && (this->index == other.index);
	}
	
	bool operator>(const TMonom& other) { 
		return (this->index > other.index) || ((this->index == other.index) && (this->coef > other.coef));
	}

	bool operator<(const TMonom& other) {
		return (this->index < other.index) || ((this->index == other.index) && (this->coef < other.coef));
	}
};