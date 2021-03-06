#ifndef		ACH2_H
#define		ACH2_H

#include	"vehicle-api.h"

#include    "battery.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
class ACH2 : public Vehicle
{
public:

    ACH2(QObject *parent = Q_NULLPTR);

    ~ACH2() override;

private:

    /// Аккумуляторная батарея
    Battery *battery;

    /// Инициализация цепей управления
    void initControlCircuit();

    void initialization() override;

    void stepControlCircuit(double t, double dt);

    void stepSignalsOutput(double t, double dt);

    void step(double t, double dt) override;
};

#endif // ACH2
