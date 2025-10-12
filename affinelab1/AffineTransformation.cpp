#include "AffineTransformation.h"

AffineTransform::AffineTransform(double _a11, double _a12, double _a21, double _a22, double _b1, double _b2)
    : a11(_a11), a12(_a12), a21(_a21), a22(_a22), b1(_b1), b2(_b2) {
}

Point AffineTransform::operator()(const Point& p) const {
    return {
        a11 * p.x + a12 * p.y + b1,
        a21 * p.x + a22 * p.y + b2
    };
}