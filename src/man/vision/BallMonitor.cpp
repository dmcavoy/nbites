#include "BallMonitor.h"
#include <string>


static const int NUM_MONITORS = 9;
static const int NUM_DATA_VALUES = 6;

// names of different sensors (for variance monitoring)
const std::string sensorNames[NUM_MONITORS] = {
    "varBallX", "varBallY", "varBallDist", "varRelX", "varRelY",
    "varRelVelX", "varRelVelY","varRelAccX","varRelAccY"
};

const std::string dataNames[NUM_DATA_VALUES] = {
    "relX", "relY", "relVelX", "relVelY",
    "relAccX", "relAccY"


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

    int j = 0;
    ballData[++j][colNum] = relX;
    ballData[++j][colNum] = relY;
    ballData[++j][colNum] = relVelX;
    ballData[++j][colNum] = relVelY;
    ballData[++j][colNum] = relAccX;
    ballData[++j][colNum] = relAccY;
    colNum++;
}

void BallMonitor::LogBallValues(float relX, float relY,
                                float relVelX, float relVelY,
                                float relAccX, float relAccY){
    using namespace std;
    const int width = 12;

    stringstream filename;
    ofstream outFile;
    filename << "/home/nao/naoqi/log/BALLEKFVALUES.monitor.cvs";
    outFile.open(filename.str().c_str(), ifstream::out);

    // header line with sensor names
    outFile << setw(width) << "bin";
    for (int i = 0; i < numberMonitors; ++i) {
        outFile << setw(width) << dataNames[i];
    }
    outFile << endl;

    // histogram loop (data, line by line)
    for (int bin = 0; bin < DATA_AMOUNT; ++bin) {
        for (int i = 0; i < NUM_DATA_VALUES; ++i) {
            outFile << setw(width) << setprecision(4) << ballData[bin][i];
	}
        outFile << endl;
    }
    outFile.close();
}
