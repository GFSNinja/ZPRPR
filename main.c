#include <stdio.h>
#include <string.h>

double pconvert(int number, int all) {
    return (double) (number * 10) / all;
}

void n(char *array, int *boolean) {
    FILE *fr;
    if ((fr = fopen("../sifra.txt", "r")) == NULL) {
        printf("Spravu sa nepodarilo nacitat\n");
        *boolean = 0;
        return;
    }
    char c;
    int i = 0;
    while ((c = fgetc(fr)) != EOF && i <= 1000 && i >= 0) {
        array[i] = c;
        i++;
    }
    array[i] = '\0';
    if (fclose(fr) == EOF) {
        printf("Spravu sa nepodarilo nacitat\n");
        *boolean = 0;
        return;
    }
    *boolean = 1;
}

void v(char *array, const int *boolean) {
    if (boolean == 0) {
        printf("Sprava nie je nacitana\n");
        return;
    }
    printf("%s\n",array);
}

void u(const char *p_array, char *u_array, int *boolean) {
    if (boolean[0] == 0) {
        printf("Sprava nie je nacitana\n");
        return;
    }
    int i = 0, j = 0;
    while (p_array[i] != '\0' && i <= 1000 && i >= 0 && j <= 1000 && j >= 0) {
        if (p_array[i] >= 'A' && p_array[i] <= 'Z') {
            u_array[j] = p_array[i];
            j++;
        } else if (p_array[i] >= 'a' && p_array[i] <= 'z') {
            u_array[j] = p_array[i] - 'z' + 'Z';
            j++;
        }
        i++;
    }
    u_array[j] = '\0';
    boolean[1] = 1;
}

void s(char *array, const int *boolean) {
    if (boolean == 0) {
        printf("Nie je k dispozicii upravena sprava\n");
        return;
    }
    printf("%s\n", array);
}

void d(const char *array, const int *boolean) {
    int n;
    scanf("%d", &n);
    if (boolean == 0) {
        printf("Sprava nie je nacitana\n");
        return;
    }
    int i = 0, count = 0;
    char temp[n + 1];
    temp[n] = '\0';
    while (array[i] != '\0') {
        if (array[i] == ' ' || count >= n || array[i] == '\n') {
            count = 0;
        } else {
            temp[count] = array[i];
            if (count == n - 1 && (array[i + 1] == ' ' || array[i + 1] == '\n' || array[i + 1] == '\0') &&
                (array[i - n] == ' ' || array[i - n] == '\n' || i - n < 0)) {
                printf("%s\n", temp);
            }
            count++;
        }
        i++;
    }
}

void h(const char *array, const int *boolean) {
    if (boolean == 0) {
        printf("Nie je k dispozicii upravena sprava\n");
        return;
    }
    int i = 0, max = 0, all = 0, adc[26];
    memset(adc, 0, 26 * sizeof(int));
    while (array[i] != '\0') {
        adc[array[i] - 65] += 1;
        if (adc[array[i] - 65] > max) {
            max = adc[array[i] - 65];
        }
        i++;
        all++;
    }
    for (int j = (int) (pconvert(max, all) + 1); j > 0; j--) {
        for (int k = 0; k < 26; k++) {
            //printf("%d %lf %d\n",adc[k],pconvert(adc[k], all),j);
            if (pconvert(adc[k], all) > j - 1)
                putchar('*');
            else {
                putchar(' ');
            }
        }
        putchar('\n');
    }
    printf("ABCDEFGHIJKLMNOPQRSTUVWXYZ\n");
}

void c(const char *array, const int *boolean) {
    if (boolean == 0) {
        printf("Nie je k dispozicii upravena sprava\n");
        return;
    }
    int cislo = 0, i = 0;
    scanf("%d", &cislo);
    while (array[i] != '\0') {
        if (array[i] - cislo < 'A') {
            putchar(array[i] - cislo + 26);
        } else {
            putchar(array[i] - cislo);
        }
        i++;
    }
    putchar('\n');
}

int main() {
    char povodny[1001], upraveny[1001];
    int boolean[2] = {0, 0};
    char volba;
    while (1) {
        scanf("%c", &volba);
        if (volba == 'n') {
            n(povodny, &boolean[0]);
        } else if (volba == 'v') {
            v(povodny, &boolean[0]);
        } else if (volba == 'u') {
            u(povodny, upraveny, boolean);
        } else if (volba == 's') {
            s(upraveny, &boolean[1]);
        } else if (volba == 'd') {
            d(povodny, &boolean[0]);
        } else if (volba == 'h') {
            h(upraveny, &boolean[1]);
        } else if (volba == 'c') {
            c(upraveny, &boolean[1]);
        } else if (volba == 'k') {
            return 0;
        }
    }
}