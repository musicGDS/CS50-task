#include <cs50.h>
#include <stdio.h>

int main(void) {
    long cardOrigNr;
    int nrLenght = 0;   
    bool numberLegit (long cardNr);
    long firstNumbers(long cardNr, long lenght);

        cardOrigNr = get_long("Number: ");
       long cardNr = cardOrigNr; 
    while(cardNr != 0)
    {
        cardNr /= 10;
        ++nrLenght;
    }
    
//     printf("Nr lenght: %d\n", nrLenght);

    
    if (nrLenght < 13 || nrLenght > 16 || nrLenght == 14){
        printf("INVALID\n");
    } else if (nrLenght == 13) { 
//         printf("choice13\n");
        long firstNum =  firstNumbers(cardOrigNr, nrLenght); 
        if (numberLegit (cardOrigNr) && firstNum >= 40 && firstNum < 50) {
            printf("VISA\n");
        } else {
            printf("INVALID\n");
        }
    } else if (nrLenght == 15) {
        printf("choice15\n");
        long firstNum =  firstNumbers(cardOrigNr, nrLenght); 
//         printf("First number: %ld", firstNum);
//         printf("Card Original number: %ld", cardOrigNr);
        
        bool legitNr = numberLegit(cardOrigNr);
//         printf("Number Legit: %d", legitNr);
        if (legitNr && firstNum == 34 && firstNum == 37) {
            printf("AMEX\n");
        } else if (numberLegit(cardOrigNr) && firstNum >= 51 && firstNum < 56) {
            printf("MASTERCARD\n");
        } else {
            printf("INVALID\n");
        }
        
    } else if (nrLenght == 16) {
//         printf("choice16\n");
        long firstNum =  firstNumbers(cardOrigNr, nrLenght); 
//         printf("choice16_2 %ld\n", firstNum);
        if (numberLegit (cardOrigNr) && firstNum == 40) {
//             (firstNum >= 40 || firstNum < 50)
            printf("VISA\n");
        } else {
            printf("INVALID\n");
        }
    }
}

bool numberLegit (long cardNr) {
    bool x = true;
    long multip = 0;
    long summ = 0;
        
    while(cardNr)
        {
             if (x) {
                 
                summ += cardNr % 10;
                 cardNr /= 10;
                 x = false;
//                  printf("Summ: %ld", summ);
             } else {
                 long temp = (cardNr % 10) * 2;
                 while (temp) {
                     multip += temp % 10;
                     temp /= 10;
                 }
                 
                 cardNr /= 10;
                 x = true;
//                  printf("multip: %ld", multip);
             }   
        }
    
//     printf("Summ + multip: %ld", (summ + multip));
    
    if ((summ + multip) % 10 == 0) {
//         printf("Legit\n");
        return true;
    } else {
//         printf("nonLegit\n");
        return false;
    }
}
   

long firstNumbers(long cardNr, long lenght) {
    long square = 0;
    
    switch (lenght) {
        case 13:
            square = 100000000000;
            break;
        case 15:
            square = 10000000000000;
            break;
        case 16: 
            square = 10000000000000;
            break;
    }
    long x = cardNr / square;
    printf("Fi")
    return x;
}
