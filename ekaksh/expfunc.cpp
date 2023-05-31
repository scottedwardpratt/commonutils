#include <iostream>
#include <cmath>
#include<cstdlib>
#include <time.h>
#include<vector>
using namespace std;




int main()
{
	int ibin; 
    double delx = 0.1;
    
    vector<double> xcount; 
    int Nbins = 100; 
    xcount.resize(Nbins); 

    for(ibin = 0; ibin< Nbins; ibin++) 
    {
        xcount[ibin]= 0;
    }

    srand((unsigned)time(NULL));

    for (int i = 0; i < 15; i++) 
    {
		double x = (double)(rand()+ 0.5)/RAND_MAX;
        x = -log(x);
        ibin = floorl(x/delx);
        xcount[ibin] += 1;
        
    }




  
    return 0;

	
}

