#include    "ach2.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void ACH2::stepDisel(double t, double dt)
{
    disel_stop_A13->step(t, dt);
}