#include    "ach2.h"

#include    "ach2-signals.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void ACH2::stepSignalsOutput(double t, double dt)
{
    Q_UNUSED(t)
    Q_UNUSED(dt)

    analogSignal[SIGLIGHT_EPT_O] = 1.0f;
    analogSignal[SIGLIGHT_EPT_P] = 1.0f;
    analogSignal[SIGLIGHT_EPT_T] = 1.0f;

    analogSignal[LS_G] = 1.0f;

    analogSignal[KLUCH_EPK] = 1.0f;

    analogSignal[WHEEL_1] = static_cast<float>(dir * wheel_rotation_angle[0] / 2.0 / Physics::PI);
    analogSignal[WHEEL_2] = static_cast<float>(dir * wheel_rotation_angle[1] / 2.0 / Physics::PI);
    analogSignal[WHEEL_3] = static_cast<float>(dir * wheel_rotation_angle[2] / 2.0 / Physics::PI);
    analogSignal[WHEEL_4] = static_cast<float>(dir * wheel_rotation_angle[3] / 2.0 / Physics::PI);
}
