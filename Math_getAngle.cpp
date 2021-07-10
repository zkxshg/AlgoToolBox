#define _USE_MATH_DEFINES
#include <cmath>

double get_angle(double x1, double y1, double x2, double y2, double x3, double y3) {
    double theta = atan2(x1 - x3, y1 - y3) - atan2(x2 - x3, y2 - y3);

    if (theta > M_PI) theta -= 2 * M_PI;

    if (theta < -M_PI) theta += 2 * M_PI;

    theta = abs(theta * 180.0 / M_PI);
    return theta;
}