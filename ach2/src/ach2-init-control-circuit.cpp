#include    "ach2.h"

#include    <QDir>

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void ACH2::initControlCircuit()
{
    battery = new Battery();
    battery->read_custom_config(config_dir + QDir::separator() + "battery");
}
