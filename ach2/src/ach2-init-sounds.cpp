#include    "ach2.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void ACH2::initSounds()
{
    azv_control_F11.setOnSoundName("AZV_On");
    azv_control_F11.setOffSoundName("AZV_Off");
    connect(&azv_control_F11, &Trigger::soundPlay, this, &ACH2::soundPlay);

    azv_fuel_pump_F12.setOnSoundName("AZV_On");
    azv_fuel_pump_F12.setOffSoundName("AZV_Off");
    connect(&azv_fuel_pump_F12, &Trigger::soundPlay, this, &ACH2::soundPlay);

    fuel_pump_K11->setSoundName("Relay");
    connect(fuel_pump_K11, &Relay::soundPlay, this, &ACH2::soundPlay);

    connect(fuel_pump, &ElectricFuelPump::soundPlay, this, &ACH2::soundPlay);
    connect(fuel_pump, &ElectricFuelPump::soundStop, this, &ACH2::soundStop);
    connect(fuel_pump, &ElectricFuelPump::soundSetVolume, this, &ACH2::soundSetVolume);
    connect(fuel_pump, &ElectricFuelPump::soundSetPitch, this, &ACH2::soundSetPitch);
}
