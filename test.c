#include <unistd.h>  // for close() and STDIN_FILENO
#include <stdio.h>   // for printf()

int main() {
    printf("Before closing stdin...\n");
    close(STDIN_FILENO);
    printf("After closing stdin!\n");
    
    // Now try reading from stdin - what happens?
    char c;
	int	returning;
    returning = read(STDIN_FILENO, &c, 1); // or use getchar()
    printf("%d\n", returning);
    return 0;
}