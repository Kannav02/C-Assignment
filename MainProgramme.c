// 11-Nov 2021 Kannav Created this 
// 12-Nov 2021 Kannav Modified the files and added the functions
// 13-Nov 2021 Kannav finalised the programme
// 15-Nov 2021 Kannav and Bhavjot Tested and documented the code
// 16-Nov 2021 Samay reworked On the code


#define _CRT_SECURE_NO_WARNINGS
#define InterestRate 0.05  //Defining the interest rate
#include <stdio.h>
#include <string.h>
#include "MainHeaderFile.h"// include the main header file 

int main(void) {
    //Creating all the variables required to take input from the file 
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
    double MEarnings=0;
    double ROI=0;
    double Currentv=0;
    double Capitalg=0;
    int n =1;
    int SumP=0;
    
    

	FILE *fp = fopen("Apartments.txt", "r");// Opening the appartments file to read text 
    // assigning the data to the appartments structure 
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
        p->appartments[i].MonthlyEarnings=MonthlyEarningsAppartment(p->appartments[i].MonthlyRent,p->appartments[i].MonthlyCFees);
        p->appartments[i].CurrentV=CurrentValue(p->appartments[i].MonthlyEarnings);
        p->appartments[i].CapitalG=CapitalGains(p->appartments[i].CurrentV,p->appartments[i].PurchasePrice);
        SumP=SumP+p->appartments[i].PurchasePrice;
        
		while (fgetc(fp) != '\n');//clearing the file buffer before the next fscanf()
	}
    // Calculating Everything for the appartment section
    MEarnings=TotalMonthlyEarningsAppart(&property,n);
    ROI=ReturnOnInvestment(MEarnings,SumP);
    Currentv=TotalCvalueAppart(&property,n);
    Capitalg=TotalCapitalGainsAppart(&property,n);


    // priinting out the values for the appartment
    printf("The following are financial stats for Brookfield Asset Management, 11 Yonge Street.\n\n");
    printf("For the apartments, the monthly earnings are $%.2lf, the roi is %.2lf%% the total value is $%.2lf and the capital gains are $%.2lf\n\n",MEarnings,ROI,Currentv,Capitalg);

	fclose(fp);
    SumP=0;
    n=2;

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
        p->townhouses[i].MonthlyEarnings=MonthlyEarningsTownHouses(p->townhouses[i].MonthlyRent,p->townhouses[i].MonthlyPropertyTax,p->townhouses[i].MonthlyUtilities, p->townhouses[i].MonthlyCFees);
        p->townhouses[i].CurrentV=CurrentValue(p->townhouses[i].MonthlyEarnings);
        p->townhouses[i].CapitalG=CapitalGains(p->townhouses[i].CurrentV,p->townhouses[i].Pprice);
        SumP=SumP+p->townhouses[i].Pprice;
		while (fgetc(fp) != '\n');//clear the file buffer before the next fscanf()
	}
    MEarnings=TotalMonthlyEarningsAppart(&property,n);
    ROI=ReturnOnInvestment(MEarnings,SumP);
    Currentv=TotalCvalueAppart(&property,n);
    Capitalg=TotalCapitalGainsAppart(&property,n);
	fclose(fp);
    printf("For the townhouses, the monthly earnings are $%.2lf, the roi is %.2lf%% the total value is $%.2lf and the capital gains are $%.2lf\n\n",MEarnings,ROI,Currentv,Capitalg);
	//Retrieve data for semi-detached houses
    n=3;
    SumP=0;
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
        p->houses[i].MonthlyEarnings=MonthlyEarningsHouses(p->houses[i].MonthlyRent, p->houses[i].MonthlyUtilities,p->houses[i].MonthlyPropertyTax);
        p->houses[i].CurrentV=CurrentValue(p->houses[i].MonthlyEarnings);
        p->houses[i].CapitalG=CapitalGains(p->houses[i].CurrentV,p->houses[i].Pprice);
        SumP=SumP+p->houses[i].Pprice;

        
		while (fgetc(fp) != '\n');//clear the file buffer before the next fscanf()
	}

    MEarnings=TotalMonthlyEarningsAppart(&property,n);
    ROI=ReturnOnInvestment(MEarnings,SumP);
    Currentv=TotalCvalueAppart(&property,n);
    Capitalg=TotalCapitalGainsAppart(&property,n);

    printf("For the semi detached houses, the monthly earnings are $%.2lf, the roi is %.2lf%% the total value is $%.2lf and the capital gains are $%.2lf\n\n",MEarnings,ROI,Currentv,Capitalg);
	fclose(fp);

	return 0;
}






double MonthlyEarningsHouses(double MonthlyRent,double MonthlyUtilities ,double MonthlyPropertyTax){
    double monthlyEarnings;
    monthlyEarnings = MonthlyRent-MonthlyUtilities-MonthlyPropertyTax;
    return monthlyEarnings;

}
// calculate the Return on investment for a single property
double ReturnOnInvestment(double MonthlyEarnings,double Pprice){
    double rinvestment;
    rinvestment=(100*12*MonthlyEarnings)/Pprice;
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

double TotalCapitalGainsAppart(struct RealEstate *property,int n){
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
double MonthlyEarningsTownHouses(double MonthlyRent,double MonthlyUtilities ,double MonthlyPropertyTax,double MonthlyCondoFees){
    double monthlyEarnings;
    monthlyEarnings = MonthlyRent-MonthlyUtilities-MonthlyPropertyTax-MonthlyCondoFees;
    return monthlyEarnings;

}
double MonthlyEarningsAppartment(double MonthlyRent,double MonthlyPropertyTax){
    double monthlyEarnings;
    monthlyEarnings = MonthlyRent-MonthlyPropertyTax;
    return monthlyEarnings;
}

