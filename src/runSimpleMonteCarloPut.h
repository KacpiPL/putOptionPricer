#ifndef RUNSIMPLEMONTECARLOPUT_H
#define RUNSIMPLEMONTECARLOPUT_H

// prototype of the function
double runSimpleMonteCarloPut(double Expiry,
                            double Strike,
                            double Spot,
                            double Vol,
                            double r,
                            double b,
                            unsigned long int NumberOfPaths);

#endif
