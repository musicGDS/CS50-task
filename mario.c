#include <cs50.h>
#include <stdio.h>

int main(void)
{
   int h = 0;
    
    do{
        h = get_int("Name Height: ");
    } while (h < 1 || h > 8);
//     int h = get_int("Name Height: ");
    
    int spaces = h - 1;
    int hashs = h - spaces;
    
//     printf("Height: %i\n", height);
    for (int i = 0; i < h; i++) 
    {
        for (int j = 0; j < spaces; j++) {
            printf(" ");
        }
        
        for (int k = 0; k < hashs; k++) {
            printf("#");
        }
        
        printf("  ");
        
        for (int k = 0; k < hashs; k++) {
            printf("#");
        }
        printf("\n");
        
        spaces--;
        hashs++;
    }
    
}
