#include    "ach2.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void ACH2::stepControlCircuit(double t, double dt)
{
    // Считаем ток, потребляемый цепями управления
    Icc = fuel_pump_K11->getCurrent() +
          fuel_pump->getCurrent();

    battery->setLoadCurrent(Icc);
    battery->setChargeVoltage(0.0);
    battery->step(t, dt);

    Ucc = max(battery->getVoltage(), 0.0);
}
