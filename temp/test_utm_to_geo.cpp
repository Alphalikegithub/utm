// Sample code: test_utm_to_geo.cpp
// Compile: g++ -o test_utm_to_geo test_utm_to_geo.cpp datum.cpp utm.cpp

#include<iostream>
#include<iomanip>
#include<cmath>
#include"datum.h"
#include"utm.h"

int main(int argc, char** argv)
{
  double N = 2167055.962;
  double E = 492749.0228;
  GridZone zone = UTM_ZONE_49;
  Hemisphere hemi = HEMI_NORTH;
  double lat;
  double lon;
  const Ellipse* e = standard_ellipse(ELLIPSE_WGS84);
  grid_to_geographic(e->a, e->e2, zone, hemi, N, E, &lat, &lon);
  std::cout << std::fixed << std::setprecision(6)
            << lat/M_PI*180.0 << ' ' << lon/M_PI*180.0 << ' ' << std::endl;
}
