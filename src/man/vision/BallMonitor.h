#ifndef BALL_MONITOR_H
#define BALL_MONITOR_H

#include "BulkMonitor.h"

class BallMonitor
{
public:

    BallMonitor();

    void update(float x, float y, float dist);
    void update(float relX, float relY,
                float relVelX, float relVelY,
                float relAccX, float relAccY);

    void Reset();
    void LogOutput();

private:
    BulkMonitor monitor;

};

#endif
