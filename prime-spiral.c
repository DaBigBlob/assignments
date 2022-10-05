#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//i write my own string length function 💪
unsigned int lenstr(char *str) {
    int size = 0;
    while (str[size] != '\0') size++;
    return(size);
}

//i write my own string compare function 💪
unsigned short cmpstr(char *str1, char *str2) {
    unsigned int str1len = lenstr(str1);
    if (str1len != lenstr(str2)) return(1);
    for (int z = 0; z < str1len; z++) {
        if (str1[z] != str2[z]) return(1);
    }
    return(0);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("\n⚠️   Too few/many arguments.\n");
        printf("help");
        return(1);
    } else if (cmpstr(argv[1], "--help") == 0) {
        printf("help");
        return(0);
    }

    unsigned int N = atoi(argv[1]), N1; N1 = N;

    unsigned long num = 1, init = 0, N2 = pow(N, 2);
    unsigned long* spiral = malloc(sizeof(unsigned long) * N2);
    if (!spiral) {
        printf("\n⚠️   Could not allocate heap memory.\n");
        return(1);
    }
    
    while (N >= 1) {
        for (unsigned int i=0; i<N; ++i) {
            spiral[init + i] = num + i;
            spiral[init + i + N*(N - 1)] = num + 3*(N - 1) - i;
        }
        for (unsigned int i=1; i<=N-2; ++i) {
            spiral[init + N*i] = num + 4*N - 3 - i;
            spiral[init + N*(i + 1) - 1] = num + N + i;
        }
        num = N*4 - 3;
        init = N + 1;
        N -= 2;
    }

    for (unsigned int i=0; i<N2; ++i) {
        num = spiral[i];
        printf("%lu", num);
        if (num%N1 == 0) {
            printf("\n");
        } else {
            printf("\t");
        }
    }
        
    return(0);
}
