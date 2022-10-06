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

    long N = atoi(argv[1]), N1; N1 = N;

    unsigned long num = 1, init = 0, N2 = pow(N, 2);
    unsigned long* spiral = malloc(sizeof(unsigned long) * N2);
    if (!spiral) {
        printf("\n⚠️   Could not allocate heap memory.\n");
        return(1);
    }
    
    int a1, a2, b1, b2, c1, c2, d1, d2;
    
    while (N >= 1) {
        printf("\nnum = %lu; init = %lu; N = %ld;\n\n", num, init, N);
        for (unsigned int i=0; i<N; ++i) {
            a1 = init + i;
            a2 = num + i;
            b1 = init + i + N1*(N - 1);
            b2 = num + 3*(N - 1) - i;
            printf("a: %d ----> %d\n", a1, a2);
            printf("b: %d ----> %d\n", b1, b2);
            spiral[a1] = a2;
            spiral[b1] = b2;
        }
        printf("\nend ab\n\n");
        for (unsigned int i=1; i<=N-2; ++i) {
            c1 = init + N1*i;
            c2 = num + 4*N - 4 - i;
            d1 = init + N1*i + N - 1;
            d2 = num + N - 1 + i;
            printf("c: %d ----> %d\n", c1, c2);
            printf("d: %d ----> %d\n", d1, d2);
            spiral[c1] = c2;
            spiral[d1] = d2;
        }
        printf("\nend cd\n\n");
        num = N*4 - 3;
        init = N + 1;
        N -= 2;
    }

    for (unsigned int i=0; i<N2; ++i) {
        num = spiral[i];
        printf("%lu", num);
        if ((i+1)%N1 == 0) {
            printf("\n");
        } else {
            printf("\t");
        }
    }

    free(spiral);
    return(0);
}
