#include    "apch2.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
APCH2::APCH2(QObject *parent) : Vehicle(parent)
  , main_res_volume(0.3)
  , ctrl_res_volume(0.5)
{

}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
APCH2::~APCH2()
{

}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void APCH2::initialization()
{
    main_res = new Reservoir(main_res_volume);
    main_res->setFlowCoeff(0.0005);
    main_res->setY(0, 0.9);
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void APCH2::step(double t, double dt)
{
    main_res->setAirFlow(0.0);
    main_res->step(t, dt);

    DebugMsg = QString("Давление в ПР: %1").arg(main_res->getPressure(), 4, 'f', 2);
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void APCH2::loadConfig(QString cfg_path)
{
    CfgReader cfg;

    if (cfg.load(cfg_path))
    {
        cfg.getDouble("Vehicle", "MainResVolume", main_res_volume);

        main_res_volume = main_res_volume / 1000.0;

        cfg.getDouble("Vehicle", "CtrlResVolume", ctrl_res_volume);

        ctrl_res_volume = ctrl_res_volume / 1000.0;
    }
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
GET_VEHICLE(APCH2)