#include    "block-disel-stop.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
BlockDiselStop::BlockDiselStop(QObject *parent) : Device(parent)
  , stop_relay(new Relay(NUMBER_CONTACTS_A13))
  , stop_time_relay(new TimeRelay(2))
  , U(0.0)

{
    stop_relay->setInitContactState(A13_1, true);
    stop_relay->setInitContactState(A13_2, false);
    stop_relay->setInitContactState(A13_3, true);
    stop_relay->setInitContactState(A13_4, true);
    stop_relay->setInitContactState(A13_5, true);

    stop_time_relay->setTimeout(6.0);
    stop_time_relay->setInitContactState(0, true);
    stop_time_relay->setInitContactState(1, true);
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
    stop_relay->setVoltage(U * static_cast<double>(stop_time_relay->getContactState(0)));
    stop_relay->step(t, dt);

    stop_time_relay->setControlVoltage(U * static_cast<double>(stop_time_relay->getContactState(1)));
    stop_time_relay->step(t, dt);

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
void BlockDiselStop::setVoltage(double U)
{
    this->U = U;
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
