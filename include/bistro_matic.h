/*
**EPITECHPROJECT,2017
**bistro-matic.h
**Filedescription:
**bistro_matic.h
*/

#ifndef BISTRO_MATIC_H_
#define BISTRO_MATIC_H_

const int EXIT_USAGE = 84;
const int EXIT_BASE = 84;
const int EXIT_SIZE_NEG = 84;
const int EXIT_MALLOC = 84;
const int EXIT_READ = 84;
const int EXIT_OPS = 84;
const int EXIT_SYNTAX_ERROR = 84;

char const *SYNTAX_ERROR_MSG = "syntax error";
char const *ERROR_MSG = "error";

char* start_bistro(char const *base,char const *ops,
		   char const *expr,unsigned int size);
#endif
