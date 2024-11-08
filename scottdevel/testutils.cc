#include "msu_commonutils/log.h"
#include "msu_commonutils/randy.h"
#include "msu_commonutils/decay_nbody.h"
#include "msu_commonutils/commondefs.h"
#include "msu_commonutils/sf.h"
#include "msu_commonutils/qualifier.h"

#include <cstring>
using namespace std;
using namespace NMSUPratt;

int main(){
	CQualifiers qualifier;
	qualifier.Read("quals.txt");
	qualifier.Print();
	
	return 0;
}
