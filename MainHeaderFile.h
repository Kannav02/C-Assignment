// creating the main structure 
// 08-Nov 2021 Kannav Created the main structure
// 10-Nov 2021 Kannav Added the 4 protoypes of the functions that are to be used in calculatng the total
// 11-Nov 2021 Kannav added extra functions
// 15-Nov 2021 Kannav and bhavjot tested and documented the main header file
// 16-Nov 2021 Samay Reworked on the code

#define NUM_PROPERTY 5 // Total number of properties 
#include "AssignmentSubStruct.h"

// Creating the main structure for the real estate 

struct RealEstate{
char name[34];
char address[64];
struct appartment appartments[NUM_PROPERTY];
struct townhouse townhouses[NUM_PROPERTY];
struct semi_detached houses[NUM_PROPERTY];
};


// function to calculate a single MonthlyEarning for a single semi detached house
double MonthlyEarningsHouses(double MonthlyRent,double MonthlyUtilities ,double MonthlyPropertyTax);

// function to calculate a single MonthlyEarning for a single townhouse
double MonthlyEarningsTownHouses(double MonthlyRent,double MonthlyUtilities ,double MonthlyPropertyTax,double MonthlyCondoFees);

// function to calculate a single ROI for a property
double ReturnOnInvestment(double MonthlyEarnings,double Pprice);

// function to calculate a single MonthlyEarning for a single appartment
double MonthlyEarningsAppartment(double MonthlyRent,double MonthlyCondoFees);

// function to calculate the current value of a property
double CurrentValue(double MonthlyEarnings);

// function to calculate the capitalgains for a property 
double CapitalGains(double CurrentValue, double Pprice);

// function to calculate the net monthly earnings from appartment
double TotalMonthlyEarningsAppart(struct RealEstate *property,int n);

// function to calculate the total current value of appartments
double TotalCvalueAppart(struct RealEstate *property, int n);

// function to  calculate the total capital gains from appartments
double TotalCapitalGainsAppart(struct RealEstate *property, int n);
