#ifndef		ACH2_H
#define		ACH2_H

#include	"vehicle-api.h"

#include    "battery.h"
#include    "fuel-tank.h"

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

    /// Напряжение цепей управления
    double Ucc;

    /// Ток, потребляемый цепями управления
    double Icc;

    /// Топливный бак
    FuelTank    *fuel_tank;

    /// АЗВ "Управление"
    Trigger azv_control;

    /// Инициализация цепей управления
    void initControlCircuit();

    /// Инициализация озвучки
    void initSounds();

    void initialization() override;

    void stepControlCircuit(double t, double dt);

    void stepSignalsOutput(double t, double dt);

    void step(double t, double dt) override;

    void keyProcess() override;

    void loadConfig(QString cfg_path) override;
};

#endif // ACH2
