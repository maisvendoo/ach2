#include    "ach2.h"

#include    "ach2-signals.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void ACH2::stepSignalsOutput(double t, double dt)
{
    Q_UNUSED(t)
    Q_UNUSED(dt)

    analogSignal[BUTTON_FUEL_PUMP] = static_cast<float>(button_fuel_pump_S18.getState());

    //analogSignal[SIGLIGHT_FUEL_PRESS_1ACH2] = static_cast<float>(hs_n(fuel_pump->getFuelPressure() - 0.14));

    analogSignal[STRELKA_BAT_CURRENT] = static_cast<float>(battery->getCargeCurrent() / 100.0);

    analogSignal[TUMBLER_COMMON_CONTROL] = static_cast<float>(azv_control_F11.getState());

    analogSignal[WHEEL_1] = static_cast<float>(dir * wheel_rotation_angle[0] / 2.0 / Physics::PI);
    analogSignal[WHEEL_2] = static_cast<float>(dir * wheel_rotation_angle[1] / 2.0 / Physics::PI);
    analogSignal[WHEEL_3] = static_cast<float>(dir * wheel_rotation_angle[2] / 2.0 / Physics::PI);
    analogSignal[WHEEL_4] = static_cast<float>(dir * wheel_rotation_angle[3] / 2.0 / Physics::PI);
}
