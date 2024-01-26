#include <Rcpp.h>
#include "runSimpleMonteCarloPut.h"

using namespace Rcpp;
using namespace std;

// [[Rcpp::export]]
double getPutPrice(
    double Expiry = 0.75,
    double Strike = 150,
    double Spot   = 140,
    double Vol    = 0.24,
    double r      = 0.07,
    unsigned long NumberOfPaths = 10000){
  double result = runSimpleMonteCarloPut(Expiry,
                                       Strike,
                                       Spot,
                                       Vol,
                                       r,
                                       NumberOfPaths);

  return result;
}


