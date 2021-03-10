#ifndef     BLOCK_DISEL_STOP_H
#define     BLOCK_DISEL_STOP_H

#include    "device.h"
#include    "relay.h"
#include    "time-relay.h"

enum
{
    NUMBER_CONTACTS_A13 = 5,
    A13_1 = 0,
    A13_2 = 1,
    A13_3 = 2,
    A13_4 = 3,
    A13_5 = 5
};

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
class BlockDiselStop : public Device
{
public:

    BlockDiselStop(QObject *parent = Q_NULLPTR);

    ~BlockDiselStop() override;

    void step(double t, double dt) override;

    bool getContactState(size_t index) const;

    void setVoltage(double U);

private:

    Relay       *stop_relay;

    TimeRelay   *stop_time_relay;

    double      U;

    void ode_system(const state_vector_t &Y,
                    state_vector_t &dYdt,
                    double t) override;
};

#endif // BLOCK_DISEL_STOP_H
