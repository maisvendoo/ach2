#include    "ach2.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void ACH2::stepControlCircuit(double t, double dt)
{
    battery->setLoadCurrent(Icc);
    battery->setChargeVoltage(0.0);
    battery->step(t, dt);

    Ucc = max(battery->getVoltage(), 0.0);
}
