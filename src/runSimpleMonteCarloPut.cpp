#include "runSimpleMonteCarloPut.h"
#include "getOneGaussianByBoxMueller.h"
#include <cmath>

// definition of the function
double runSimpleMonteCarloPut(double Expiry,
                            double Strike,
                            double Spot,
                            double Vol,
                            double r,
                            double b,
                            unsigned long int NumberOfPaths){

  double variance = Vol * Vol * Expiry;
  double rootVariance = sqrt(variance);
  double itoCorrection = -0.5 * variance;

  double movedSpot = Spot * exp(r * Expiry + itoCorrection);
  double thisSpot;
  double runningSum = 0;

  for (unsigned long i = 0; i < NumberOfPaths; i++) {

    bool barrierBreached = false;
    double thisGaussian = getOneGaussianByBoxMueller();

    thisSpot = movedSpot * exp(rootVariance * thisGaussian);

    // check if price of the asset falls below the barrier level
    if (thisSpot < b){
      barrierBreached = true;
    }

    // calculate the payoff only if the price does not fall below b
    if (!barrierBreached) {
      double thisPayoff = Strike - thisSpot;
      if (thisPayoff > 0) runningSum += thisPayoff;
    }
  }

  double mean = runningSum / NumberOfPaths;
  // mean *= exp(-r * Expiry);
  mean = mean * exp(-r * Expiry);
  return mean;
}
