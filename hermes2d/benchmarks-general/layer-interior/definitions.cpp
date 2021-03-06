#include "definitions.h"

double CustomExactSolution::value (double x, double y) const 
{
  return atan(slope * (sqrt(sqr(x-1.25) + sqr(y+0.25)) - M_PI/3));
}

void CustomExactSolution::derivatives (double x, double y, scalar& dx, scalar& dy) const 
{
  double t = sqrt(sqr(x - 1.25) + sqr(y + 0.25));
  double u = t * (sqr(slope) * sqr(t - M_PI/3) + 1);
  dx = slope * (x-1.25) / u;
  dy = slope * (y+0.25) / u;
}

Ord CustomExactSolution::ord(Ord x, Ord y) const 
{
  return Ord(20);
}


double CustomFunction::value(double x, double y) const 
{
  double t2 = sqr(y + 0.25) + sqr(x - 1.25);
  double t = sqrt(t2);
  double u = (sqr(M_PI - 3.0*t)*sqr(slope) + 9.0);

  return (   27.0/2.0 * sqr(2.0*y + 0.5) * (M_PI - 3.0*t) * pow(slope, 3.0) / (sqr(u) * t2) 
           + 27.0/2.0 * sqr(2.0*x - 2.5) * (M_PI - 3.0*t) * pow(slope, 3.0) / (sqr(u) * t2) 
           - 9.0/4.0 * sqr(2.0*y + 0.5) * slope / (u * pow(t,3.0)) 
           - 9.0/4.0 * sqr(2.0*x - 2.5) * slope / (u * pow(t,3.0)) + 18.0 * slope / (u * t)
		);
}

Ord CustomFunction::value(Ord x, Ord y) const 
{
  return Ord(20);
}
