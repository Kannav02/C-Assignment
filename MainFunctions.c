#include "MainHeaderFile.h"
#define InterestRate 0.05
// 10-Nov 2021 Kannav Created this file
// 11-Nov 2021 Kannav Added the extra functions

// calculate the monthly earning for a single property 
double MonthlyEarnings(double MonthlyRent,double MonthlyUtilities ,double MonthlyPropertyTax){
    double monthlyEarnings;
    monthlyEarnings = MonthlyRent-MonthlyUtilities-MonthlyPropertyTax;
    return monthlyEarnings;

}
// calculate the Return on investment for a single property
double ReturnOnInvestment(double MonthlyEarnings,double Pprice){
    double rinvestment;
    rinvestment=100*12*MonthlyEarnings/Pprice;
    return rinvestment;
    
    
}
// calculate the current value of a single property
double CurrentValue(double MonthlyEarnings){
    double cValue;
    cValue=12*MonthlyEarnings/InterestRate;
    return cValue;

}
// calculate the capitalgains for a single property
double CapitalGains(double CurrentValue, double Pprice){
    double CapitalG;
    CapitalG=CurrentValue-Pprice;
    return CapitalG;
}
// calculate the total monthly earnings for a specific property
double TotalMonthlyEarningsAppart(struct RealEstate *property){
    double SumM=0;
    for(int i =0;i<NUM_PROPERTY;i++){
        SumM=SumM+property->appartments[i].MonthlyEarnings;

    }
    return SumM;
}

double TotalCvalueAppart(struct RealEstate *property){
    double SumM=0;
    for(int i =0;i<NUM_PROPERTY;i++){
        SumM=SumM+property->appartments[i].CurrentV;

    }
    return SumM;
}

double CapitalGainsAppart(struct RealEstate *property){
    double SumM=0;
    for(int i =0;i<NUM_PROPERTY;i++){
        SumM=SumM+property->appartments[i].CapitalG;

    }
    return SumM;
}



double TotalMonthlyEarningsTownH(struct RealEstate *property){
    double SumM=0;
    for(int i =0;i<NUM_PROPERTY;i++){
        SumM=SumM+property->townhouses[i].MonthlyEarnings;

    }
    return SumM;
}

double TotalCvalueTownH(struct RealEstate *property){
    double SumM=0;
    for(int i =0;i<NUM_PROPERTY;i++){
        SumM=SumM+property->townhouses[i].CurrentV;

    }
    return SumM;
}

double CapitalGainsTownH(struct RealEstate *property){
    double SumM=0;
    for(int i =0;i<NUM_PROPERTY;i++){
        SumM=SumM+property->townhouses[i].CapitalG;

    }
    return SumM;
}

double TotalMonthlyEarningsSemiH(struct RealEstate *property){
    double SumM=0;
    for(int i =0;i<NUM_PROPERTY;i++){
        SumM=SumM+property->houses[i].MonthlyEarnings;

    }
    return SumM;
}

double TotalCvalueSemiH(struct RealEstate *property){
    double SumM=0;
    for(int i =0;i<NUM_PROPERTY;i++){
        SumM=SumM+property->houses[i].CurrentV;

    }
    return SumM;
}

double CapitalGainsSemiH(struct RealEstate *property){
    double SumM=0;
    for(int i =0;i<NUM_PROPERTY;i++){
        SumM=SumM+property->houses[i].CapitalG;

    }
    return SumM;
}


