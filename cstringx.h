#ifndef _CSTRINGX_H
#define _CSTRINGX_H
#include <stddef.h>

#define join(...) _join(__VA_ARGS__, NULL)
char* dups(char* s);//复制一个字符串
size_t nchar(char* s,char c);//数出字符串中某个字符的数量
char* replace(char* s,char o,char r);//将字符串中某一个字符替换为另一个字符
void replaceself(char*s,char o,char r);
char** explode(char* s,char c);//将字符串按某一个字符串截断
void free_exploded(char** e);//释放因执行explode而动态分配的内存
char* _join(const char* first, ...);
size_t cap(void* p);
#endif