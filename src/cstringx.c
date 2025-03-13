#include "cstringx.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* dups(char* s){
	size_t n=strlen(s);
	char* t=malloc(n+1);
	memcpy(t,s,n);
	t[n]=0;
	return t;
}
size_t nchar(char* s,char c){
	size_t n=0;
	if(!s)return 0;
	while(*s){
		if(*s==c)n++;
		s++;
	}
	return n;
}
char* replace(char* s,char o,char r){
	if(!s)return NULL;
	char* t=dups(s);
	char* p=t;
	while(*p){
		if(*p==o)*p=r;
		p++;
	}
	return t;
}
char** explode(char* s,char c){
	size_t n=nchar(s,c)+1;
	char* d=replace(s,c,0);
	char** t=malloc(sizeof(char*)*(n+1));
	for(size_t i=0;i<n;i++){
		t[i]=d;
		d=(char*)&d[strlen(d)]+1;
	}
	t[n]=NULL;
	return t;
}
void free_exploded(char** e){
	free(e[0]);
	free(e);
}
