#include "msu_commonutils/qualifier.h"
#include "msu_commonutils/parametermap.h"
#include "msu_commonutils/log.h"

using namespace std;
using namespace NMSUPratt;

void CQualifiers::Read(string qfilename){
	CQualifier *qptr;
	char cread[200],dummy[200];
	int npars=0,iqual=-1;
	string sread;
	FILE *fptr=fopen(qfilename.c_str(),"r");
	while(!feof(fptr)){
		fscanf(fptr,"%s",cread);
		sread=cread;
		if(sread[0]=='#'){
			fgets(dummy,200,fptr);
		}
		else if(sread=="qualifier"){
			npars=0;
			iqual+=1;
			qptr=new CQualifier();
			qualifier.push_back(qptr);
			fscanf(fptr,"%s",cread);
			sread=string(cread);
			qualifier[iqual]->qualname=sread;
			fgets(dummy,200,fptr);
		}
		else{
			if(sread=="int" || sread=="double" || sread=="bool"){
				qualifier[iqual]->type.push_back(sread);
				fscanf(fptr,"%s",cread);
				sread=string(cread);
				qualifier[iqual]->parname.push_back(sread);
				fscanf(fptr,"%s",cread);
				sread=string(cread);
				qualifier[iqual]->value.push_back(sread);
			}
			else{	
				qualifier[iqual]->type.push_back("string");
				qualifier[iqual]->parname.push_back(sread);
				fscanf(fptr,"%s",cread);
				sread=string(cread);
				qualifier[iqual]->value.push_back(sread);
			}
			fgets(dummy,200,fptr);
			npars+=1;
		}
		if(iqual>=0)
			qualifier[iqual]->npars=npars;
	}
	nqualifiers=qualifier.size();
	fclose(fptr);
}

void CQualifiers::SetPars(CparameterMap *pmap,int iqual){
	for(int ipar=0;ipar<qualifier[iqual]->npars;ipar++){
		pmap->set(qualifier[iqual]->parname[ipar],qualifier[iqual]->value[ipar]);
	}
}

void CQualifiers::Print(){
	CLog::Info("------ QUALIFIERS -------\n");
	for(int iqual=0;iqual<nqualifiers;iqual++){
		CLog::Info("--- "+qualifier[iqual]->qualname+" ---\n");
		for(int ipar=0;ipar<qualifier[iqual]->npars;ipar++){
			CLog::Info(qualifier[iqual]->type[ipar]+"  "+qualifier[iqual]->parname[ipar]+"  " +qualifier[iqual]->value[ipar]+"\n");
		}
	}
}
