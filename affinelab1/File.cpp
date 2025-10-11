#include "File.h"
#include <fstream>
#include <stdexcept>
using namespace std;
vector<AffineTransform> readTransforms(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) throw runtime_error(" can not open the file");

    int n;
    double x0, y0;
    inFile >> n >> x0 >> y0;

    vector<AffineTransform> transforms;
    double a11, a12, a21, a22, b1, b2;
    while (inFile >> a11 >> a12 >> a21 >> a22 >> b1 >> b2) {
        transforms.emplace_back(a11, a12, a21, a22, b1, b2);
    }

    if (transforms.empty()) throw runtime_error("can`t find any transformation");
    return transforms;
}

void readStartPoint(const string& filename, int& n, Point& start) {
    ifstream inFile(filename);
    if (!inFile) throw runtime_error("can`t open the file");
    inFile >> n >> start.x >> start.y;
}

void writePoints(const string& filename, const vector<Point>& points) {
    ofstream outFile(filename);
    if (!outFile) throw runtime_error("can`t open the file to write the results");

    for (const auto& p : points) {
        outFile << p.x << " " << p.y << "\n";
    }
}