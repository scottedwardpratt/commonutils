#include "msu_commonutils/log.h"

string CLog::logfilename="log.txt";
bool CLog::INTERACTIVE=true;
FILE *CLog::fptr=NULL;

using namespace std;

void CLog::Init(string &logfilename_in){
	INTERACTIVE=false;
	logfilename=logfilename_in;
	fptr=fopen(logfilename.c_str(),"w");
}

void CLog::Init(char *logfilename_in){
	INTERACTIVE=false;
	logfilename=logfilename_in;
	fptr=fopen(logfilename.c_str(),"w");
}

void CLog::Fatal(string &message){
	if(INTERACTIVE){
		printf("FATAL error:\n %s\n",logfilename.c_str());
		printf("%s",message.c_str());
	}
	else{
		fprintf(fptr,"FATAL error: %s\n",logfilename.c_str());
		fprintf(fptr,"%s",message.c_str());
		fflush(fptr);
	}
	exit(1);
}

void CLog::Fatal(char *message){
	if(INTERACTIVE){
		printf("FATAL error: %s\n",logfilename.c_str());
		printf("%s",message);
	}
	else{
		fprintf(fptr,"FATAL error: %s\n",logfilename.c_str());
		fprintf(fptr,"%s",message);
		fflush(fptr);
	}
	exit(1);
}

void CLog::Info(string &message){
	if(INTERACTIVE){
		printf("%s",message.c_str());
	}
	else{
		fprintf(fptr,"%s",message.c_str());
		fflush(fptr);
	}
}

void CLog::Info(char *message){
	if(INTERACTIVE){
		printf("%s",message);
	}
	else{
		fprintf(fptr,"%s",message);
		fflush(fptr);
	}
}
