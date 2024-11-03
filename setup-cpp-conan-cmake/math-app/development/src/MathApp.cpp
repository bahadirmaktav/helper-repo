#include <iostream>
#include "coordinates/ECEF.h"
#include "coordinates/ENU.h"
#include "coordinates/Geodetic.h"
#include "conversions/CoordinateConversion.h"
#include "conversions/TimeConversion.h"
#include "calculations/DistanceCalculator.h"
#include "calculations/AngleCalculator.h"
#include "transformations/CoordinateTransform.h"

int main() {
    // ECEF Koordinatları oluşturma
    ECEF point1(1000.0, 2000.0, 3000.0);
    ECEF point2(1500.0, 2500.0, 3500.0);

    // Koordinatları yazdırma
    std::cout << "Point 1 (ECEF): ";
    point1.printCoordinates();
    std::cout << "Point 2 (ECEF): ";
    point2.printCoordinates();

    // Mesafe hesaplama
    double distance = DistanceCalculator::calculateDistance(point1, point2);
    std::cout << "Distance between Point 1 and Point 2: " << distance << " units" << std::endl;

    // Açı hesaplama
    double azimuth = AngleCalculator::calculateAzimuth(point1, point2);
    std::cout << "Azimuth from Point 1 to Point 2: " << azimuth << " degrees" << std::endl;

    // ENU Koordinatları oluşturma
    ENU enu(500.0, 1000.0, 200.0);
    std::cout << "ENU Coordinates: ";
    enu.printCoordinates();

    // ENU'yu ölçekleme
    ENU scaledENU = CoordinateTransform::scaleENU(enu, 2.0);
    std::cout << "Scaled ENU Coordinates: ";
    scaledENU.printCoordinates();

    // Zaman dönüşümleri
    std::time_t gpsTime = std::time(nullptr);
    std::time_t utcTime = TimeConversion::GPSToUTC(gpsTime);
    std::cout << "GPS Time (UTC): " << utcTime << std::endl;

    // Koordinat dönüşümü
    ECEF rotatedPoint = CoordinateTransform::applyRotation(point1, 0.1, 0.2, 0.3);
    std::cout << "Rotated Point (ECEF): ";
    rotatedPoint.printCoordinates();

    return 0;
}
