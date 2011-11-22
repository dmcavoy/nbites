#ifndef BALL_MONITOR_H
#define BALL_MONITOR_H

#include "BulkMonitor.h"

#define DATA_VALUES 6
#define DATA_AMOUNT 100

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

    void LogBallValues(float relX, float relY,
                float relVelX, float relVelY,
                float relAccX, float relAccY);

private:
    BulkMonitor monitor;
    float ballData [DATA_VALUES][DATA_AMOUNT];
    int colNum = 0;

};

#endif
