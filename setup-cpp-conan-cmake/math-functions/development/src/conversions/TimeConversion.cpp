#include "conversions/TimeConversion.h"

std::time_t TimeConversion::GPSToUTC(std::time_t gpsTime) {
    return gpsTime - 18;
}

std::time_t TimeConversion::UTCToGPS(std::time_t utcTime) {
    return utcTime + 18;
}
