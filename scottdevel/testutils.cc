#include "msu_commonutils/log.h"
#include "msu_commonutils/randy.h"
#include "msu_commonutils/decay_nbody.h"
#include "msu_commonutils/commondefs.h"
#include "msu_commonutils/sf.h"
#include "msu_commonutils/qualifier.h"
#include "msu_commonutils/sf.h"

#include <cstring>
using namespace std;
using namespace NMSUPratt;

int main(){
  for(double x=0.1;x<2.0;x+=0.2){
    printf("%g %g\n",x,NMSUPratt::Bessel::J0(x));
  }
return 0;
}
