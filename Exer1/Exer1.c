#include<stdio.h>
//The program accepts integer inputs and outputs the input into a 7 segment display format
//It can only accept integers from 0 to 15, else the program will prompt the user to input another integer.
//It cannot accept characters and decimals
//Tayag
int main(){
    while(1) {
             int x;
             printf("\nInput an integer from 0 to 15: ");
             scanf("%d", &x);
             if (x == 0) {
                printf("\n _\n| |\n|_|\n");
                }
             else if (x == 1) {
                printf("\n  \n  |\n  |\n");
                }
             else if (x == 2) {
                printf("\n _\n _|\n|_ \n");
                }
             else if (x == 3) {
                printf("\n _\n _|\n _|\n");
                  }
             else if (x == 4) {
                  printf("\n  \n|_|\n  |\n");
                  }
             else if (x == 5) {
                  printf("\n _\n|_ \n _|\n");
                  }
             else if (x == 6) {
                  printf("\n  \n|_ \n|_|\n");
                  }
             else if (x == 7) {
                  printf("\n _\n  |\n  |\n");
                  }
             else if (x == 8) {
                  printf("\n _\n|_|\n|_|\n");
                  }
             else if (x == 9) {
                  printf("\n _\n|_|\n _|\n");
                  }
             else if (x == 10) {
                  printf("\n  \n _ \n|_ \n");
                  }
             else if (x == 11) {
                  printf("\n  \n _ \n _|\n");
                  }
             else if (x == 12) {
                  printf("\n  \n|_|\n   \n");
                  }
             else if (x == 13) {
                  printf("\n _\n|_ \n _ \n");
                  }
             else if (x == 14) {
                  printf("\n  \n|_ \n|_ \n");
                  }
             else if (x == 15) {
                  printf("\n");
                  }
             else {
                  printf("Please enter a number from 0-15 only.");
                  }

    }
    return 0;
}
