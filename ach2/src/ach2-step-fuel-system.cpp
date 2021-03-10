#include    "ach2.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void ACH2::stepFuelSystem(double t, double dt)
{
    // Цепь контактора топливного насоса
    bool is_K11_on = azv_control_F11.getState() &&
                    (button_fuel_pump_S18.getState() || fuel_pump_K11->getContactState(2));

    fuel_pump_K11->setVoltage(Ucc * static_cast<double>(is_K11_on));
    fuel_pump_K11->step(t, dt);

    // Цепь топливного насоса
    bool is_Fuel_Pump_On = azv_fuel_pump_F12.getState() && fuel_pump_K11->getContactState(1);

    fuel_pump->setVoltage(Ucc * static_cast<double>(is_Fuel_Pump_On));
    fuel_pump->setFuelLevel(fuel_tank->getFuelLevel());
    fuel_pump->step(t, dt);

    // Топливный бак
    fuel_tank->setFuelConsumption(0.0);
    fuel_tank->step(t, dt);

    // Пересчет полной массы мотрисы
    full_mass = empty_mass + payload_mass * payload_coeff + fuel_tank->getFuelMass();
}
