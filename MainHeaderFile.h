// creating the main structure 
// 08-Nov 2021 Kannav Created the main structure
// 10-Nov 2021 Kannav Added the 4 protoypes of the functions that are to be used in calculatng the total
// 11-Nov 2021 Kannav added extra functions
#define NUM_PROPERTY 5
#include "AssignmentSubStruct.h"

struct RealEstate{
char name[34];
char address[64];
struct appartment appartments[NUM_PROPERTY];
struct townhouse townhouses[NUM_PROPERTY];
struct semi_detached houses[NUM_PROPERTY];
};


// function to calculate a single MonthlyEarning for a property
double MonthlyEarnings(double MonthlyRent,double MonthlyUtilities ,double MonthlyPropertyTax);

// function to calculate a single ROI for a property
double ReturnOnInvestment(double MonthlyEarnings,double Pprice);

// function to calculate the current value of a property
double CurrentValue(double MonthlyEarnings);

// function to calculate the capitalgains for a property 
double CapitalGains(double CurrentValue, double Pprice);

// function to calculate the net monthly earnings from appartment
double TotalMonthlyEarningsAppart(struct RealEstate *property);

// function to calculate the total current value of appartments
double TotalCvalueAppart(struct RealEstate *property);

// function to  calculate the total capital gains from appartments
double TotalCapitalGainsAppart(struct RealEstate *property);

// function to calculate the net monthly earnings from Townhouses
double TotalMonthlyEarningsTownH(struct RealEstate *property);

// function to calculate the total vale of townhouses
double TotalCvalueTownH(struct RealEstate *property);

// function to calculate the total capital gains of townhouses
double CapitalGainsTownH(struct RealEstate *property);

// function to calculate the net monthly earnings from Semi detached houses
double TotalMonthlyEarningsSemiH(struct RealEstate *property);

// function to calculate the total current value of semi detached houses
double TotalCvalueSemiH(struct RealEstate *property);

// function to calculate the total capital gains from semi detaches houses
double CapitalGainsSemiH(struct RealEstate *property);