#include    "ach2.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void ACH2::initSounds()
{
    azv_control.setOnSoundName("AZV_On");
    azv_control.setOffSoundName("AZV_Off");
    connect(&azv_control, &Trigger::soundPlay, this, &ACH2::soundPlay);
}
