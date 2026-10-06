/* vuln_overflow.c
   Vulnerability: unsafe strcpy -> stack buffer overflow
*/
#include <stdio.h>
#include <string.h>

static void greet_user(const char *name) {
    char greeting[32];
    snprintf(greeting, sizeof greeting, "%s", name);
    printf("Hello, %s\n", greeting);
}

int main(int argc, char **argv) {
    char buf[64];
    if (argc < 3) {
        printf("Usage: %s <input> <name>\n", argv[0]);
        return 1;
    }
    snprintf(buf, sizeof buf, "%s", argv[1]);
    printf("You entered: %s\n", buf);
    greet_user(argv[2]);
    return 0;
}
