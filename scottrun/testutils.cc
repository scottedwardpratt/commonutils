#include "msu_commonutils/log.h"
#include "msu_commonutils/randy.h"
#include "msu_commonutils/decay_nbody.h"
#include "msu_commonutils/commondefs.h"
#include <cstring>
using namespace std;

int main(){
	Crandy *randy=new Crandy(1234);
	CDecay_NBody *decay_nbody=new CDecay_NBody(randy);
	long long unsigned int ntry=1000000,itry;
	double M,m1,m2,m3,m4;
	int ibody,nbodies;
	FourVector p1,p2,p3,p4;
	double pxbar=0.0;
	for(itry=0;itry<ntry;itry++){
		M=1000.0+500.0*randy->ran();
		m1=100.0;
		m2=200.0;
		m3=300.0;
		m4=400.0;
		decay_nbody->SetMasses4(M,m1,m2,m3,m4);
		decay_nbody->GenerateMomenta4(p1,p2,p3,p4);
		pxbar+=p1[1];
	}
	printf("pxbar=%g\n",pxbar/double(ntry));
	ntry*=1000;
	nbodies=8;
	pxbar=0.0;
	vector<FourVector> p(nbodies);
	vector<double> mass(nbodies+1);
	for(itry=0;itry<ntry;itry++){
		for(ibody=1;ibody<=nbodies;ibody++)
			mass[ibody]=100.0;
		mass[0]=1000.0;
		decay_nbody->SetMasses(nbodies,mass);
		decay_nbody->GenerateMomenta(p);
		for(ibody=0;ibody<nbodies;ibody++)
			pxbar+=p[ibody][1];
	}
	printf("pxbar=%g\n",pxbar/double(ntry));
	return 0;
}
