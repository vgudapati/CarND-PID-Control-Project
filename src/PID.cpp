#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    // Using the values provided to initialize the coefficients
    
    PID::Kp = Kp;
    PID::Ki = Ki;
    PID::Kd = Kd;
    
    // Assuming zero errors to being with...
    
    //p_error = 0;
    //i_error = 0;
    //d_error = 0;
    
    // Initializing other variables
    
    prev_cte = 0;
    int_cte = 0;
    
    
    
}

void PID::UpdateError(double cte) {
    int_cte += cte;
    diff_cte = cte - prev_cte;
    
    
    p_error = -Kp * cte;
    i_error = -Ki * int_cte;
    d_error = -Kd * diff_cte;
    
    prev_cte = cte;    
}

double PID::TotalError() {
    return p_error + i_error + d_error;
}

