#include <iostream>
#include <cmath>
#include <time.h>
#include <cstdio> 
#include<vector>
using namespace std;


#include<cstdlib>
 




int main()
{
    double x,y;
    FILE *fptr;
    fptr = fopen("randfile.txt","w"); 


    srand((unsigned)time(NULL));

    double step = 0.1;
    for(double i = 0; i < 1000; i ++)
    { 
        x = i * step;
        y = sin(x);
        fprintf(fptr,"%10.3f %10.3f\n",x,y);
    }
    fclose(fptr);

    
}

