#include "msu_commonutils/log.h"
#include "msu_commonutils/randy.h"
#include "msu_commonutils/decay_nbody.h"
#include "msu_commonutils/commondefs.h"
#include <cstring>
using namespace std;

int main(){
	Crandy *randy=new Crandy(1234);
	CDecay_NBody *decay_nbody=new CDecay_NBody(randy);
	long long unsigned int ntry=10,itry;
	int ibody,nbodies=5;
	vector<double> masses(nbodies+1);
	vector<FourVector> p(nbodies);
	masses[0]=100.0;
	for(ibody=0;ibody<nbodies;ibody++)
		masses[ibody+1]=0.0;
	decay_nbody->SetMasses(nbodies,masses);
	for(itry=0;itry<ntry;itry++){
		decay_nbody->GenerateMomenta(p);
		//decay_nbody->GenerateMomenta2(p[0],p[1]);
		printf("itry=%lld\n",itry);
		for(ibody=0;ibody<nbodies;ibody++){
			printf("(%g,%g,%g,%g)\n",p[ibody][0],p[ibody][1],p[ibody][2],p[ibody][3]);
		}
	}
	return 0;
}
