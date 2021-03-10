#include    "ach2.h"

#include    <QDir>

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void ACH2::initFuelSystem()
{
    fuel_pump = new ElectricFuelPump();

    fuel_pump_K11 = new Relay(3);
    fuel_pump_K11->read_custom_config(config_dir + QDir::separator() + "kontactor");
    fuel_pump_K11->setInitContactState(0, false);
    fuel_pump_K11->setInitContactState(1, false);
    fuel_pump_K11->setInitContactState(2, false);
}
