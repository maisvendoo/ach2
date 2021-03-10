#ifndef     TIME_RELAY_H
#define     TIME_RELAY_H

#include    "relay.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
class TimeRelay : public Relay
{
public:

    TimeRelay(size_t num_contacts = 1, QObject *parent = Q_NULLPTR);

    ~TimeRelay();

    /// Задать интервал срабатывания, с
    void setTimeout(double timeout);

    /// Задать напряжение питания
    void setControlVoltage(double Uc);

    /// Получить потребляемый ток
    double getCurrent() const override;

    void step(double t, double dt) override;

private:

    Timer       *timer;

    /// Управляющее напряжение
    double      Uc;

    /// Номинальное напряжение
    double      U_nom;

    /// Внутреннее сопротивление управляющих цепей
    double      Rc;

    /// Порог срабатывания
    double      start_level;

    /// Флаг срабатывания
    bool        is_started;

    void setVoltage(double U) override;

    void preStep(state_vector_t &Y, double t) override;

    void ode_system(const state_vector_t &Y, state_vector_t &dYdt, double t) override;

    void load_config(CfgReader &cfg) override;

private slots:

    void slotTimeoutProcess();
};

#endif // TIME_RELAY_H
