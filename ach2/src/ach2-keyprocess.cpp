#include    "ach2.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void ACH2::keyProcess()
{
    // АЗВ "Управление"
    if (getKeyState(KEY_J))
    {
        if (isShift())
            azv_control_F11.set();
        else
            azv_control_F11.reset();
    }

    // АЗВ "Топливный насос"
    if (getKeyState(KEY_P))
    {
        if (isShift())
            azv_fuel_pump_F12.set();
        else
            azv_fuel_pump_F12.reset();
    }

    // Кнопка "Топливный насос"
    if (getKeyState(KEY_O))
        button_fuel_pump_S18.set();
    else
        button_fuel_pump_S18.reset();
}
