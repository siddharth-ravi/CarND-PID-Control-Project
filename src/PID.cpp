#include "PID.h"

using namespace std;
#include <iostream>

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd, double throttle) {
	
	this -> Kp = Kp;
	this -> Ki = Ki;
	this -> Kd = Kd;
	this->throttle = throttle;
	p_error = 0;
	i_error = 0;
	d_error = 0;
}

void PID::UpdateError(double cte) {
	
	double cte_old = p_error;
	p_error = cte;
	d_error = cte - cte_old;
	i_error += cte;
	
}

double PID::TotalError() {
	
	double totalerror;
	totalerror = Kp * p_error + Kd * d_error + Ki * i_error;
	return totalerror;
}
