#include "BallMonitor.h"
#include <string>


static const int NUM_MONITORS = 9;

// names of different sensors (for variance monitoring)
const std::string sensorNames[NUM_MONITORS] = {
    "ballX", "ballY", "ballDist", "relX", "relY",
    "relVelX", "relVelY","relAccX","relAccY"
};


BallMonitor::BallMonitor()
    : monitor(NUM_MONITORS,"BallMonitor", sensorNames)
{

}

void BallMonitor::Reset()
{
    monitor.Reset();
}

void BallMonitor::LogOutput()
{
    monitor.LogOutput();
}

void BallMonitor::update(float x, float y, float dist)
{
    int i = 0;
    monitor.update(i, x);
    monitor.update(++i, y);
    monitor.update(++i, dist);
}

void BallMonitor::update(float relX, float relY,
                         float relVelX, float relVelY,
                         float relAccX, float relAccY)
{
    int i = 3; // see above
    monitor.update(i, relX);
    monitor.update(++i, relY);
    monitor.update(++i, relVelX);
    monitor.update(++i, relVelY);
    monitor.update(++i, relAccX);
    monitor.update(++i, relAccY);

}

