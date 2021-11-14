// 11-Nov 2021 Kannav Created this 
// 12-Nov 2021 Kannav Modified the files and added the functions


#define _CRT_SECURE_NO_WARNINGS
#define InterestRate 0.05
#include <stdio.h>
#include <string.h>
#include "MainHeaderFile.h"

int main(void) {
    //Read the data for all companies from a file
	char address[255];
	int rooms;
	int bathrooms;
	double purchasePrice;
	double monthlyRent;
	double monthlyUtilities;
	double monthlyCondoFees;
	double monthlyPropertyTax;
    struct RealEstate property;
    struct RealEstate *p=&property;
    

	//Retrieve data for apartments
	FILE* fp = fopen("Apartments.txt", "r");
	for (int i = 0; i < NUM_PROPERTY; ++i) {
		fscanf(fp, "%[^\n]s", address);
		fscanf(fp, "%d", &rooms);
		fscanf(fp, "%d", &bathrooms);
		fscanf(fp, "%lf", &purchasePrice);
		fscanf(fp, "%lf", &monthlyRent);
		fscanf(fp, "%lf", &monthlyCondoFees);
        strcpy(p->appartments[i].address,address);
        p->appartments[i].Nrooms=rooms;
        p->appartments[i].Nbathrooms=bathrooms;
        p->appartments[i].PurchasePrice=purchasePrice;
        p->appartments[i].MonthlyRent=monthlyRent;
        p->appartments[i].MonthlyCFees=monthlyCondoFees;
        p->appartments[i].MonthlyEarnings=0;
        p->appartments[i].CurrentV=CurrentValue(p->appartments[i].MonthlyEarnings);
        p->appartments[i].CapitalG=CapitalGains(p->appartments[i].CurrentV,p->appartments[i].PurchasePrice);

        
		while (fgetc(fp) != '\n');//clear the file buffer before the next fscanf()
	}
	fclose(fp);

	//Retrieve data for townhouses
	fp = fopen("Townhouses.txt", "r");
	for (int i = 0; i < NUM_PROPERTY; ++i) {
		fscanf(fp, "%[^\n]s", address);
		fscanf(fp, "%d", &rooms);
		fscanf(fp, "%d", &bathrooms);
		fscanf(fp, "%lf", &purchasePrice);
		fscanf(fp, "%lf", &monthlyRent);
		fscanf(fp, "%lf", &monthlyUtilities);
		fscanf(fp, "%lf", &monthlyCondoFees);
		fscanf(fp, "%lf", &monthlyPropertyTax);
        strcpy(p->townhouses[i].address,address);
        p->townhouses[i].Nrooms=rooms;
        p->townhouses[i].Nbathrooms=bathrooms;
        p->townhouses[i].Pprice=purchasePrice;
        p->townhouses[i].MonthlyRent=monthlyRent;
        p->townhouses[i].MonthlyCFees=monthlyCondoFees;
        p->townhouses[i].MonthlyUtilities=monthlyUtilities;
        p->townhouses[i].MonthlyPropertyTax=monthlyPropertyTax;
        p->townhouses[i].MonthlyEarnings=0;
        p->townhouses[i].CurrentV=0;
        p->townhouses[i].CapitalG=0;

		while (fgetc(fp) != '\n');//clear the file buffer before the next fscanf()
	}
	fclose(fp);

	//Retrieve data for semi-detached houses
	fp = fopen("SemiDetachedHouses.txt", "r");
	for (int i = 0; i < NUM_PROPERTY; ++i) {
		fscanf(fp, "%[^\n]s", address);
		fscanf(fp, "%d", &rooms);
		fscanf(fp, "%d", &bathrooms);
		fscanf(fp, "%lf", &purchasePrice);
		fscanf(fp, "%lf", &monthlyRent);
		fscanf(fp, "%lf", &monthlyUtilities);
		fscanf(fp, "%lf", &monthlyPropertyTax);
        strcpy(p->houses[i].address,address);
        p->houses[i].Nrooms=rooms;
        p->houses[i].Nbathrooms=bathrooms;
        p->houses[i].Pprice=purchasePrice;
        p->houses[i].MonthlyRent=monthlyRent;
        p->houses[i].MonthlyUtilities=monthlyUtilities;
        p->houses[i].MonthlyPropertyTax=monthlyPropertyTax;
        p->houses[i].MonthlyEarnings=0;
        p->houses[i].CurrentV=0;
        p->houses[i].CapitalG=0;
        
		while (fgetc(fp) != '\n');//clear the file buffer before the next fscanf()
	}
	fclose(fp);

	return 0;
}






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