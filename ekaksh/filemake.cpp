#include <iostream>
#include <cmath>
#include <time.h>
#include <cstdio> 
#include<vector>
using namespace std;


#include<cstdlib>
 




int main()
{
    double x=567,y;                       // defining the variables. 
    FILE *fptr;                           // defining the file. 
    fptr = fopen("filemake.txt","w");     // naming the file, the "w" is write, "r" is read ,"a" is append, "r+" is read/update, "w+" is write/update


    fprintf(fptr,"%g\n",x);               // what to print in file, check https://cplusplus.com/reference/cstdio/fprintf/ for more. 
    fclose(fptr);                         // closes the loop 



    fptr=fopen("filemake.txt","r");       // for reading in the file

    fscanf(fptr,"%lf",&y);                // for scanning in the file, https://cplusplus.com/reference/cstdio/fscanf/
    do{
        printf("y=%g\n",y);               //  shows answer in teminal when run 

        fscanf(fptr,"%lf",&y);
    }while(!feof(fptr));                 // Checks whether the end-of-File indicator associated with stream is set, returning a value different from zero if it is. This indicator is generally set by a previous operation on the stream that attempted to read at or past the end-of-file.

    return 0;
}

