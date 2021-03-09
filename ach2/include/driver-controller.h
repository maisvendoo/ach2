#ifndef     DRIVER_CONTROLLER_H
#define     DRIVER_CONTROLLER_H

#include    "device.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
enum
{
    NUMBER_JK_CONTACTS = 10,
    JK_1 = 0,
    JK_2 = 1,
    JK_3 = 2
};

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
enum
{
    NUMBER_JR_CONTACTS = 10,
    JR_1 = 0,
    JR_2 = 1,
    JR_3 = 2
};

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
class DriverController : public Device
{
public:

    DriverController(QObject *parent = Q_NULLPTR);

    ~DriverController() override;

private:

    int main_pos;

    int revers_pos;

    std::array<bool, NUMBER_JK_CONTACTS>    jk_contact;

    std::array<bool, NUMBER_JR_CONTACTS>    jr_contact;

    void ode_system(const state_vector_t &Y,
                    state_vector_t &dYdt,
                    double t) override;
};

#endif // DRIVER_CONTROLLER_H
