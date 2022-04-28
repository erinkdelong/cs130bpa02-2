#include "Point.hpp"
using namespace std;

class Edge {
    public:
        Edge();
        Edge(Point ev1, Point ev2);
        double findWeight(Point ev1, Point ev2);

        Point v1;
        Point v2;
        double weight;

};