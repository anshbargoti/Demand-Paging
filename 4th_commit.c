#include <stdio.h>
#include <stdlib.h>
double faultRate();
void input(void);

double servicePageFaultEmptyOrUnmodified;
double servicePageFaultModified;
double memoryAccessTime_nanosec;
float PercentageOfModifiedPages;
double effectiveAccessTime_nanosec;
double data;
double pageFaultEmptyOrUnmodified_nanosec;
double pageFaultModified_nanosec;
double replacedPageModified;
	

int main(){
	int i;
	
	do{
	printf("----------------------------------------------------------------\n");
	printf("Select any option: \n");
	printf("1.Find Maximum Acceptable Page-Fault Rate\n");
	printf("2.Exit\n");
	printf("Choice : ");
	scanf("%d",&i);
	switch(i){
		case 1:input();
		       break;
		case 2:exit(0);
	}
	printf("\n\n");

}
while(i<3);
}
void input(){
	
	
	printf("\nEnter time to service a Page-Fault [Empty Page or Unmodified Replaced Page] [In milliseconds] : ");
	scanf("%lf",&servicePageFaultEmptyOrUnmodified);
	printf("Enter time to Service a Page-Fault [Modified Replaced Page] [In milliseconds] : ");
	scanf("%lf",&servicePageFaultModified);
	printf("Enter Memory Access Time [In nanoseconds] : ");
	scanf("%lf",&memoryAccessTime_nanosec);
	printf("Enter Percentage for the time,the page to be replaced is modified [0-100] : ");
	scanf("%f",&PercentageOfModifiedPages);
	printf("Enter Effective Access time [In nanoseconds] : ");
	scanf("%lf",&effectiveAccessTime_nanosec);

	printf("\n\n\n");
	pageFaultEmptyOrUnmodified_nanosec = (servicePageFaultEmptyOrUnmodified*1000000);  // Converting millisecond to nanosecond
	pageFaultModified_nanosec = (servicePageFaultModified*1000000);                    // Converting millisecond to nanosecond
	replacedPageModified = (PercentageOfModifiedPages/100);                            // Converting percenatge value 
	printf("Data for calculating Page-Fault Rate :- \n\n");
	printf("Time taken to service a Page-Fault for Empty Page or Unmodified Replaced Page [In nanoseconds] = %lf \n",pageFaultEmptyOrUnmodified_nanosec);
	printf("Time taken to service a Page-Fault for Modified Replaced Page [In nanoseconds] = %lf \n",pageFaultModified_nanosec);
	printf("Time taken for Memory Acess [In nanoseconds] = %lf\n",memoryAccessTime_nanosec);
	printf("Value of Page to be replaced = %f\n",replacedPageModified);
	printf("Time taken for Effective Access [In nanoseconds] = %lf\n",effectiveAccessTime_nanosec);
    data = faultRate(pageFaultEmptyOrUnmodified_nanosec,pageFaultModified_nanosec,memoryAccessTime_nanosec,replacedPageModified,effectiveAccessTime_nanosec);
	printf("\nFor Access Time Maximum Acceptable Page-Fault rate = %.2le [In exponential notation]",data);

}

double faultRate(double emptyOrUnmodifiedPageFault,double modifiedPageFault,double memoryAccessTime ,double modifiedTimePages,double effectiveAccessTime){
	double numerator,denominator;
	double pageFault;
	numerator = effectiveAccessTime - memoryAccessTime;
    denominator = (1- modifiedTimePages)*emptyOrUnmodifiedPageFault + modifiedTimePages*modifiedPageFault -memoryAccessTime;

	pageFault = numerator/denominator;
	return pageFault;
}

