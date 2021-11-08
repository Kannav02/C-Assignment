// creating the main structure 
// 08-Nov 2021 Kannav Created the main structure


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