#ifndef TIME_CONVERSION_H
#define TIME_CONVERSION_H

#include <ctime>

class TimeConversion {
public:
    static std::time_t GPSToUTC(std::time_t gpsTime);
    static std::time_t UTCToGPS(std::time_t utcTime);
};

#endif // TIME_CONVERSION_H
