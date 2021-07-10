// Given positions of three points, return the circle center
pair<double, double> get_CircleCenter(double x1, double y1, double x2, double y2, double x3, double y3) {
    double a, b, c, d, e, f, x, y;
    a = 2 * (x2 - x1);
    b = 2 * (y2 - y1);
    c = x2 * x2 + y2 * y2 - x1 * x1 - y1 * y1;
    d = 2 * (x3 - x2);
    e = 2 * (y3 - y2);
    f = x3 * x3 + y3 * y3 - x2 * x2 - y2 * y2;
    
    x = (b * f - e * c) / (b * d - e * a);
    y = (d * c - a * f) / (b * d - e * a);
    
    return make_pair(x, y);
}
