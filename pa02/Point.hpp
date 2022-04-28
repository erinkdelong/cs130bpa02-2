using namespace std;

class Point {
    public:
        Point();
        Point(double px, double py, double pi);
        void operator=(Point &source);
        bool operator<(Point &comp);
        bool operator==(Point &comp);

        double x;
        double y;
        int index;
        double distance;
};
