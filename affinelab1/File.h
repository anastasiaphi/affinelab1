#pragma once
#include "AffineTransformation.h"
#include <vector>
#include <string>

std::vector<AffineTransform> readTransforms(const std::string& filename);
void readStartPoint(const std::string& filename, int& n, Point& start);
void writePoints(const std::string& filename, const std::vector<Point>& points);