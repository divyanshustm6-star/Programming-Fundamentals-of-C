/* Write a C program to print your name in the star pattern. */


#include <stdio.h>
int main() {
    for (int r = 0; r < 7; r++) {
        /* D */
        for (int c = 0; c < 5; c++)
            printf((c == 0 || (r == 0 && c < 4) || (r == 6 && c < 4) || (c == 4 && r > 0 && r < 6)) ? "* " : "  ");
        printf("  ");

        /* I */
        for (int c = 0; c < 5; c++)
            printf((r == 0 || r == 6 || c == 2) ? "* " : "  ");
        printf("  ");

        /* V */
        for (int c = 0; c < 12; c++) {
            int star = 0;
            if (r < 6 && (c == r || c == 10 - r)) star = 1;  
            printf(star ? "* " : "  ");
        }
        printf("  ");

        /* Y */
        for (int c = 0; c < 5; c++)
            printf(((r < 3 && (c == r || c == 4 - r)) || (r >= 3 && c == 2)) ? "* " : "  ");
        printf("  ");

        /* A */
        for (int c = 0; c < 5; c++)
            printf(((r == 0 && c > 0 && c < 4) || (r == 3 && c > 0 && c < 4) ||
                    (c == 0 && r > 0) || (c == 4 && r > 0)) ? "* " : "  ");
        printf("  ");

        /* N */
        for (int c = 0; c < 5; c++)
            printf((c == 0 || c == 4 || c == r) ? "* " : "  ");
        printf("  ");

        /* S */
        for (int c = 0; c < 5; c++)
            printf(((r == 0 || r == 3 || r == 6) ||
                    (r < 3 && c == 0) ||
                    (r > 3 && c == 4)) ? "* " : "  ");
        printf("  ");

        /* H */
        for (int c = 0; c < 5; c++)
            printf((c == 0 || c == 4 || r == 3) ? "* " : "  ");
        printf("  ");

        /* U */
        for (int c = 0; c < 5; c++)
            printf(((c == 0 || c == 4) && r < 6 ||
                    (r == 6 && c > 0 && c < 4)) ? "* " : "  ");
        
        printf("\n");
    }

    return 0;
}
