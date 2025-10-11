#pragma once

struct Point {
    double x, y;
};

class AffineTransform {
private:
    double a11, a12, a21, a22;
    double b1, b2;

public:
    AffineTransform(double _a11, double _a12, double _a21, double _a22, double _b1, double _b2);

    Point operator()(const Point& p) const;
};