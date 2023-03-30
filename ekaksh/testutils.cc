#include "msu_commonutils/log.h"
#include "msu_commonutils/randy.h"
#include "msu_commonutils/decay_nbody.h"
#include "msu_commonutils/commondefs.h"
#include <cstring>
using namespace std;

int main(){
	Crandy *randy=new Crandy(1234);
	double x;
	int i;
	for(i=0;i<20;i++){
		x=randy->ran();
		printf("%g\n",x);
	}
	return 0;
}
