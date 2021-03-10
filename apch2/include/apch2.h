#ifndef     APCH2_H
#define     APCH2_H

#include    "vehicle-api.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
class APCH2 : public Vehicle
{
public:

    APCH2(QObject *parent = Q_NULLPTR);

    ~APCH2();

private:

    double main_res_volume;

    double ctrl_res_volume;

    Reservoir *main_res;

    void initialization();

    void step(double t, double dt);

    void loadConfig(QString cfg_path);
};

#endif // APCH2_H
