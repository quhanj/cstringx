#include "cstringx.h"
#include <string.h>
#include <stdarg.h>
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
void replaceself(char*s,char o,char r){
	while(*s){
		if(*s==o)*s=r;
		s++;
	}
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
char* _join(const char* first, ...) {
    va_list args;
    size_t total_len = 0;
    const char* arg;
    // 计算总长度
    va_start(args, first);
    total_len = strlen(first);
    while ((arg = va_arg(args, const char*)) != NULL) {
        total_len += strlen(arg);
    }
    va_end(args);
    total_len += 1; // 终止符
    // 分配内存
    char* result = (char*)malloc(total_len);
    if (!result) {
        return NULL;
    }
    // 拼接字符串
    va_start(args, first);
    char* p = result;
    strcpy(p, first);
    p += strlen(first);
    while ((arg = va_arg(args, const char*)) != NULL) {
        strcpy(p, arg);
        p += strlen(arg);
    }
    va_end(args);
    // 确保终止符（虽然strcpy已处理，但确保安全）
    *p = '\0';
    return result;
}
