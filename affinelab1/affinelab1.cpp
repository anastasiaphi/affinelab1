#include <iostream>
#include <vector>
#include <random>
#include "AffineTransformation.h"
#include "File.h"
using namespace std;

int main() {
    try {
        const string inputFile = "input.txt";
        const string outputFile = "output.txt";

        int n;
        Point start;
        readStartPoint(inputFile, n, start);

        auto transforms = readTransforms(inputFile);

        vector<Point> points;
        points.push_back(start);

        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<size_t> dist(0, transforms.size() - 1);

        for (int i = 1; i < n; ++i) {
            points.push_back(transforms[dist(gen)](points.back()));
        }

        writePoints(outputFile, points);
        cout << "result in the file  " << outputFile << "\n";
    }
    catch (const exception& e) {
        cerr << "error " << e.what() << "\n";
        return 1;
    }

    return 0;
}

