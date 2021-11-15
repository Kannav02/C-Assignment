#include "MainHeaderFile.h"
#define InterestRate 0.05
// 10-Nov 2021 Kannav Created this file
// 11-Nov 2021 Kannav Added the extra functions
// 13-Nov 2021 Kannav Finalised the File
// calculate the monthly earning for a single property 



double MonthlyEarningsHouses(double MonthlyRent,double MonthlyUtilities ,double MonthlyPropertyTax){
    double monthlyEarnings;
    monthlyEarnings = MonthlyRent-MonthlyUtilities-MonthlyPropertyTax;
    return monthlyEarnings;

}
double MonthlyEarningsTownHouses(double MonthlyRent,double MonthlyUtilities ,double MonthlyPropertyTax,double MonthlyCondoFees){
    double monthlyEarnings;
    monthlyEarnings = MonthlyRent-MonthlyUtilities-MonthlyPropertyTax-MonthlyCondoFees;
    return monthlyEarnings;

}
double MonthlyEarningsAppartment(double MonthlyRent,double MonthlyCondoFees){
    double monthlyEarnings;
    monthlyEarnings = MonthlyRent-MonthlyCondoFees;
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
double TotalMonthlyEarningsAppart(struct RealEstate *property,int n){
    double SumM=0;
    if(n==1){
        for(int i =0;i<NUM_PROPERTY;i++){
        SumM=SumM+property->appartments[i].MonthlyEarnings;

    }
    }
    else if(n==2){
        for(int i =0;i<NUM_PROPERTY;i++){
        SumM=SumM+property->townhouses[i].MonthlyEarnings;

    }
    }
    
    else{
        for(int i =0;i<NUM_PROPERTY;i++){
        SumM=SumM+property->houses[i].MonthlyEarnings;

    }
    
    }
    return SumM;
    
}

double TotalCvalueAppart(struct RealEstate *property,int n){
    double SumM=0;
    if(n==1){
        for(int i =0;i<NUM_PROPERTY;i++){
        SumM=SumM+property->appartments[i].CurrentV;

    }
    }
    else if(n==2){
        for(int i =0;i<NUM_PROPERTY;i++){
        SumM=SumM+property->townhouses[i].CurrentV;

    }
    }
    
    else{
        for(int i =0;i<NUM_PROPERTY;i++){
        SumM=SumM+property->houses[i].CurrentV;

    }
    
    }
    return SumM;
}

double CapitalGainsAppart(struct RealEstate *property,int n){
    double SumM=0;
    if(n==1){
        for(int i =0;i<NUM_PROPERTY;i++){
        SumM=SumM+property->appartments[i].CapitalG;

    }
    }
    else if(n==2){
        for(int i =0;i<NUM_PROPERTY;i++){
        SumM=SumM+property->townhouses[i].CapitalG;

    }
    }
    
    else{
        for(int i =0;i<NUM_PROPERTY;i++){
        SumM=SumM+property->houses[i].CapitalG;

    }
    
    }
    return SumM;
}




