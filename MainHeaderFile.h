// creating the main structure 
// 08-Nov 2021 Kannav Created the main structure
// 10-Nov 2021 Kannav Added the 4 protoypes of the functions that are to be used in calculatng the total


#include "AssignmentSubStruct.h"

struct main{
char name[34];
char address[64];
struct appartment appartments[5];
struct townhouse townhouses[5];
struct semi_detached houses[5];
}


double MonthlyEarnings(double MonthlyRent,double MonthlyUtilities ,double MonthlyPropertyTax);

double ReturnOnInvestment(double MonthlyEarnings,double Pprice);

double CurrentValue(double MonthlyEarnings);

double CapitalGains(double CurrentValue, double Pprice);

double TotalMonthlyEarnings(struct RealEstate *property);

double TotalROI(struct RealEstate *property);

double TotalCvalue(struct RealEstate *property);

double TotalCapitalGains(struct RealEstate *property);