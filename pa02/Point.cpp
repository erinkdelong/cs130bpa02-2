#include "Point.hpp"
using namespace std;

Point::Point() {
    this->x = 0.0;
    this->y = 0.0;
    this->index = 0.0;
    this->distance = 9999999.0;
}

Point::Point(double px, double py, double pi) {
    this->x = px;
    this->y = py;
    this->index = pi;
    this->distance = 9999999.0;
}

void Point::operator=(Point &source) {
    this->x = source.x;
    this->y = source.y;
    this->index = source.index;
    this->distance = source.distance;
}

bool Point::operator<(Point &comp) {
    if (this->x <= comp.x) {
        return true;
    }
    else {
        return false;
    }
}

bool Point::operator==(Point &comp) {
    if (this->x == comp.y && this->y == comp.y && this->index == comp.index) {
        return true;
    }
    else {
        return false;
    }
}