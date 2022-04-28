#include "Edge.hpp"
#include <cmath>
using namespace std;

Edge::Edge() {
    Point p1;
    Point p2;
    this->v1 = p1;
    this->v2 = p2;
    this->weight = 0.0;
}

Edge::Edge(Point ev1, Point ev2) {
    this->v1 = ev1;
    this->v2 = ev2;
    this->weight = findWeight(ev1, ev2);
}

double Edge::findWeight(Point ev1, Point ev2) {
    // sqrt((x-x1)^2 + (y - y1)^2)
    double x = ev1.x;
    double x1 = ev2.x;
    double y = ev1.y;
    double y1 = ev2.y;

    double xint = x - x1;
    double intx2 = pow(xint, 2);

    double inty = y - y1;
    double inty2 = pow(inty, 2);

    double interior = intx2 + inty2;

    double weight = sqrt(interior);

    return weight;

}