#include <cstdio>
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

#define pii pair<int,int>

vector<pii> points;

double round2(double number) {
    number *= 100;
    return round(number)/100.0;
}

double crossProduct(pii a, pii b) {
    return a.first * b.second - b.first*a.second;
}

double signedArea() {
    double area = 0.0;
    int n = points.size();
    for (int i = 0; i <n; ++i) {
        area += crossProduct(points[i], points[(i+1)%n]);
    }
    return 0.5*area;
}

double sigmaX() {
    double sum = 0.0;
    int n = points.size();
    for (int i = 0; i < n; ++i) {
        sum += (points[i].first + points[(i+1)%n].first)*crossProduct(points[i], points[(i+1)%n]);
    }
    return sum;
}

double sigmaY() {
    double sum = 0.0;
    int n = points.size();
    for (int i = 0; i < n; ++i) {
        sum += (points[i].second + points[(i+1)%n].second)*crossProduct(points[i], points[(i+1)%n]);
    }
    return sum;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        int n;
        points.clear();
        scanf("%d",&n);
        int a,b;
        double sumx=0,sumy=0;
        for (int k=0; k < n; ++k) {
            scanf("%d%d",&a,&b);
            points.push_back(make_pair(a,b));
        }
        double area = signedArea();
        double cx = (sigmaX()/6.0)/area;
        double cy = (sigmaY()/6.0)/area;
        printf("%.2f %.2f\n", round2(cx), round2(cy));

    }
    return 0;
}
