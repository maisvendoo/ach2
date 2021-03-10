#ifndef     DRIVER_CONTROLLER_H
#define     DRIVER_CONTROLLER_H

#include    "device.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
enum
{
    NUMBER_CONTACTS = 10,
    NUMBER_MAIN_POS = 9,
    NUMBER_REVERS_POS = 5
};

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
enum
{
    JK_1 = 0,
    JK_2 = 1,
    JK_3 = 2,
    JK_4 = 3,
    JK_5 = 4,
    JK_6 = 5,
    JK_7 = 6,
    JK_8 = 7,
    JK_9 = 8,
    JK_10 = 9
};

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
enum
{
    JR_1 = 0,
    JR_2 = 1,
    JR_3 = 2,
    JR_4 = 3,
    JR_5 = 4,
    JR_6 = 5,
    JR_7 = 6,
    JR_8 = 7,
    JR_9 = 8,
    JR_10 = 9
};

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
enum
{
    POS_0 = 0,
    POS_1 = 1,
    POS_2 = 2,
    POS_3 = 3,
    POS_4 = 4,
    POS_5 = 5,
    POS_6 = 6,
    POS_7 = 7,
    POS_8 = 8
};

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
enum
{
    REV_POS_FWD = 0,
    REV_POS_FRT = 1,
    REV_POS_ZER = 2,
    REV_POS_BRT = 3,
    REV_POS_BWD = 4
};

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
using contacts_t = std::array<bool, NUMBER_CONTACTS>;

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
class DriverController : public Device
{
public:

    DriverController(QObject *parent = Q_NULLPTR);

    ~DriverController() override;

    bool getJKstate(size_t contact_index) const;

    bool getJRstate(size_t contact_index) const;

private:

    int main_pos;

    int revers_pos;

    /// Контакты, замыкаемые главным валом
    std::array<contacts_t, NUMBER_MAIN_POS> JK_contacts;

    /// Контакты, замыкаемые реверсивным валом
    std::array<contacts_t, NUMBER_REVERS_POS> JR_contacts;

    void ode_system(const state_vector_t &Y,
                    state_vector_t &dYdt,
                    double t) override;
};

#endif // DRIVER_CONTROLLER_H
