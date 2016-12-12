/* Given a two-dimensional graph with points on it, find a line which passes the most number of points */
#include <iostream>
#include <utility>  // pair
#include <vector>
#include <math.h>   // fabs()
#include <limits>
#include <map>

typedef std::pair<double, double> POINT;

class Line {
    public:
        double slope;
        double y_intercept;

        static const double epsilon = .00001; // double is delicate, use epsilon to guard minor error

        // basic constructor
        Line(double slope, double y_intercept) {
            this->slope = slope;
            this->y_intercept = y_intercept;
        }

        // construct line with two points
        Line(POINT p1, POINT p2) {
            if (fabs(p1.first - p2.first) < epsilon) {  // regard as same point
                this->slope = std::numeric_limits<double>::max();
                this->y_intercept = 0;
            } else {
                this->slope = (p1.first-p2.first) / (p1.second-p2.second);
                this->y_intercept = ((-1)*p1.first * this->slope) + p1.second;
            }       
        }

        static double floorToNearestEpsilon(double d) {
            int r = (int) (d/epsilon);
            return ((double)r) * epsilon;       // quantize slope to make it hashing key
        }
};

std::vector<POINT> buildTest() {
    std::vector<POINT> ret = std::vector<POINT>();

    for (int i=0; i<5; i++) {
        ret.push_back(POINT(i, i));
    }

    ret.push_back(POINT(0, 5));
    ret.push_back(POINT(0, -5));

    return ret;
}

Line findLineWithMostPoints(std::vector<POINT> & point_set) {
    Line primary_line = Line(0, 0); // keep the best line (initial with dummy line)
    int amt = 0;           // keep the amount of points best line passes through
    std::map<double, std::vector<Line> > hash_map = std::map<double, std::vector<Line> >();

    for (int i=0; i<point_set.size(); i++) {
        for (int j=i+1; j<point_set.size(); j++) {  // j=i+1, no need to look back
            Line line = Line(point_set[i], point_set[j]);

            double hash_slope = Line::floorToNearestEpsilon(line.slope);
            hash_map[hash_slope].push_back(line);
        }
    }   
    
    for (std::map<double, std::vector<Line> >::iterator it = hash_map.begin(); it != hash_map.end(); ++it) {
        if (it->second.size() > amt) {
            primary_line = *(it->second.begin());
            amt = it->second.size();
        }
    }

    // only for testing purpose
    for (std::map<double, std::vector<Line> >::iterator it = hash_map.begin(); it != hash_map.end(); ++it) {
        std::cout << it->first << " ";
    }
    std::cout << "\n";
    for (std::map<double, std::vector<Line> >::iterator it = hash_map.begin(); it != hash_map.end(); ++it) {
        std::cout << it->second.size() << " ";
    }
    std::cout << "\n";
    

    return primary_line;
}

int main() {

    std::vector<POINT> test_set = buildTest();

    Line primary_line = findLineWithMostPoints(test_set);

    std::cout << "slope: " << primary_line.slope << ", intercept: " << primary_line.y_intercept << "\n";
    std::cout << "completed.\n";
    return 0;
}
