#ifndef		ACH2_H
#define		ACH2_H

#include	"vehicle-api.h"

#include    "battery.h"
#include    "fuel-tank.h"
#include    "electric-fuel-pump.h"
#include    "electric-oil-pump.h"
#include    "driver-controller.h"
#include    "relay.h"
#include    "block-disel-stop.h"

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

    /// Топливный насос
    ElectricFuelPump *fuel_pump;

    /// Маслопрокачивающий насос
    ElectricOilPump *oil_pump;

    /// Контактор топливного насоса
    Relay   *fuel_pump_K11;

    /// Блок остановки дизеля А13
    BlockDiselStop  *disel_stop_A13;

    /// АЗВ "Управление"
    Trigger azv_control_F11;

    /// АЗВ "Топливный насос"
    Trigger azv_fuel_pump_F12;

    /// Кнопка "Топливный насос"
    Trigger button_fuel_pump_S18;

    /// Инициализация цепей управления
    void initControlCircuit();

    /// Инициализация топливной системы
    void initFuelSystem();

    /// Инициализация дизеля и обеспечивающего его работу оборудования
    void initDisel();

    /// Инициализация озвучки
    void initSounds();

    void initialization() override;

    void stepControlCircuit(double t, double dt);

    void stepFuelSystem(double t, double dt);

    /// Работа дизеля и связанного с ним обрудования
    void stepDisel(double t, double dt);

    void stepSignalsOutput(double t, double dt);

    void step(double t, double dt) override;

    void keyProcess() override;

    void loadConfig(QString cfg_path) override;
};

#endif // ACH2
