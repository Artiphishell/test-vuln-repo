/* vuln_overflow.c
   Vulnerability: unsafe strcpy -> stack buffer overflow
*/
#include <stdio.h>
#include <string.h>

static void greet_user(const char *name) {
    char greeting[32];
    /* UNSAFE variant: same strcpy-into-fixed-stack-buffer idiom as main(),
       different call site and smaller buffer. */
    strcpy(greeting, name);
    printf("Hello, %s\n", greeting);
}

int main(int argc, char **argv) {
    char buf[64];
    if (argc < 3) {
        printf("Usage: %s <input> <name>\n", argv[0]);
        return 1;
    }
    /* FIXED: bound the copy so argv[1] can no longer overflow buf. */
    strncpy(buf, argv[1], sizeof(buf) - 1);
    buf[sizeof(buf) - 1] = '\0';
    printf("You entered: %s\n", buf);
    greet_user(argv[2]);
    return 0;
}
