#include <stdio.h>
#include <stdlib.h>
#include "expr.h"
#include "parse.h"
#include "memcheck.h"

int main(int argc, char **argv) {
    if (argc == 2) {
        expr_t e;
        int i = parse(argv[1], 0, &e);
        if (i == -1) {
            printf("parse error\n");
        } else {
            expr_t e_squared = mkTimes(copy_expr(e), copy_expr(e));
            print_expr(e);
            printf(" squared = %d\n", eval_expr(e_squared));
            free_expr(e_squared);
            free_expr(e);
            print_memory_leaks();
        }
    } else {
        printf("Expected 1 argument\n");
    }
    return 0;
}
	
