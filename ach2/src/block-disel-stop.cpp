#include    "block-disel-stop.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
BlockDiselStop::BlockDiselStop(QObject *parent) : Device(parent)
  , stop_relay(new Relay(NUMBER_CONTACTS_A13))
  , stop_delay_relay(new TimeRelay(1))
{
    stop_relay->setInitContactState(A13_1, true);
    stop_relay->setInitContactState(A13_2, false);
    stop_relay->setInitContactState(A13_3, true);
    stop_relay->setInitContactState(A13_4, true);
    stop_relay->setInitContactState(A13_5, true);

    stop_delay_relay->setTimeout(6.0);
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
BlockDiselStop::~BlockDiselStop()
{

}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void BlockDiselStop::step(double t, double dt)
{
    stop_relay->step(t, dt);

    stop_delay_relay->step(t, dt);

    Device::step(t, dt);
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
bool BlockDiselStop::getContactState(size_t index) const
{
    return stop_relay->getContactState(index);
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void BlockDiselStop::ode_system(const state_vector_t &Y,
                                state_vector_t &dYdt,
                                double t)
{
    Q_UNUSED(Y)
    Q_UNUSED(dYdt)
    Q_UNUSED(t)
}
