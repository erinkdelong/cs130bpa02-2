#include <iostream>
#include <set>
#include <vector>
#include "Edge.hpp"
using namespace std;

vector<vector<Point> > Dijkstra(vector<Point> pointVect, vector<Edge> edgeVect) {
    // pointVect is ordered by index
    set<Point> unvisited;
    for (int i = 0; i < pointVect.size(); i++) {
        unvisited.insert(pointVect[i]);
    }

    // make distance from 0th point to itself 0
    pointVect[0].distance = 0.0;

    // checking for a direct connection from vertex 0
    // if there is a direct connection, the distance from vertex 0 is updated to be that weight
    double minDist = 99999999;
    Point closest;
    double zeroToClosest = 0.0;
    for (int i = 0; i < edgeVect.size(); i++) {
        if (edgeVect[i].v1.index == 0) {
            edgeVect[i].v2.distance = edgeVect[i].weight;
            if (edgeVect[i].v2.distance < minDist) {
                minDist = edgeVect[i].v2.distance;
                closest = edgeVect[i].v2;
            }
        }
        else if (edgeVect[i].v2.index == 0) {
            edgeVect[i].v1.distance = edgeVect[i].weight;
            if (edgeVect[i].v1.distance < minDist) {
                minDist = edgeVect[i].v1.distance;
                closest = edgeVect[i].v1;
            }
        }
    }

    zeroToClosest = closest.distance; // aka minPoint.weight in this case
    // check minPoint's connections
    for (int i = 0; i < edgeVect.size(); i++) {
        if (edgeVect[i].v1.index == closest) {
            // if it is connected to B
            // edgeVect[i].v2.distance = edgeVect[i].weight;
            if (edgeVect[i].v2.distance < (edgeVect[i].weight + zeroToClosest)) {

                closest = edgeVect[i].v2;
            }
        }
        else if (edgeVect[i].v2.index == closest) {
            edgeVect[i].v1.distance = edgeVect[i].weight;
            if (edgeVect[i].v1.distance < minDist) {
                minDist = edgeVect[i].v1.distance;
                closest = edgeVect[i].v1;
            }
        }
    }
}

// if closest distance + c to that vertex is less that the vertex's current distance- update closest + c
// we will change from closest + c to closest + c + next vertex
// can make it all one for loop- closest/ closest + c/ closest + c + d can update something called 