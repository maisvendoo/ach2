#include    "driver-controller.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
DriverController::DriverController(QObject *parent) : Device (parent)
  , main_pos(0)
  , revers_pos(0)
{
    // Коммутационная программа главного вала контроллера машиниста
    // контакт             1  2  3  4  5  6  7  8  9  10
    JK_contacts[POS_0] = { 0, 0, 1, 0, 0, 1, 0, 0, 0, 0 };
    JK_contacts[POS_1] = { 0, 0, 1, 0, 0, 0, 0, 1, 0, 0 };
    JK_contacts[POS_2] = { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 };
    JK_contacts[POS_3] = { 1, 1, 0, 1, 0, 0, 1, 0, 0, 0 };
    JK_contacts[POS_4] = { 1, 1, 0, 1, 0, 0, 0, 0, 0, 0 };
    JK_contacts[POS_5] = { 1, 1, 0, 0, 1, 0, 0, 0, 0, 0 };
    JK_contacts[POS_6] = { 1, 1, 0, 0, 1, 0, 0, 0, 0, 0 };
    JK_contacts[POS_7] = { 1, 1, 0, 1, 1, 0, 0, 0, 0, 0 };
    JK_contacts[POS_8] = { 1, 1, 0, 1, 1, 0, 0, 0, 0, 0 };

    // Коммутационная программа реверсивного вала контроллера машиниста
    // контакт                  1  2  3  4  5  6  7  8  9  10
    JR_contacts[REV_POS_FWD] = {0, 0, 1, 0, 0, 1, 0, 0, 0, 0};
    JR_contacts[REV_POS_FRT] = {1, 1, 1, 0, 0, 0, 0, 0, 0, 0};
    JR_contacts[REV_POS_ZER] = {0, 0, 0, 0, 1, 0, 0, 0, 0, 0};
    JR_contacts[REV_POS_BRT] = {1, 1, 0, 1, 0, 0, 0, 0, 0, 0};
    JR_contacts[REV_POS_BWD] = {0, 0, 0, 1, 0, 1, 0, 0, 0, 0};
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
DriverController::~DriverController()
{

}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
bool DriverController::getJKstate(size_t contact_index) const
{
    if (contact_index < NUMBER_CONTACTS)
    {
        return static_cast<bool>(JK_contacts[static_cast<size_t>(main_pos)][contact_index]);
    }

    return false;
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
bool DriverController::getJRstate(size_t contact_index) const
{
    if (contact_index < NUMBER_CONTACTS)
    {
        return static_cast<bool>(JR_contacts[static_cast<size_t>(revers_pos)][contact_index]);
    }

    return false;
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void DriverController::ode_system(const state_vector_t &Y,
                                  state_vector_t &dYdt,
                                  double t)
{
    Q_UNUSED(Y)
    Q_UNUSED(dYdt)
    Q_UNUSED(t)
}
