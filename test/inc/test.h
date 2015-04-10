#ifndef _TEST
#define _TEST

#include <stdio.h>
#include <stdint.h>

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"

typedef enum test_status_t { PASS, FAIL, PENDING } TestStatus;

typedef TestStatus (*test_function_t)(void);

extern test_function_t test_function_array[];

#endif /* _TEST */
