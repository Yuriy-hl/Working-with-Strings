#include <stdio.h>
#pragma warning (disable:4996)
#include <ctype.h>

FILE* f1, * f2;
int i = 0;
char fstr[60];
int type = 0;

void type012() {
    int err = 0;
    int a = 0;
    int b = 0;
    int c = 0;
    i = 0;
    type = 0;

    while (fstr[i] != '\0') {

        if (((fstr[i] >= 'A') && (fstr[i] <= 'Z')) || ((fstr[i] >= 'a') && (fstr[i] <= 'z')) || (fstr[i] == '_')) {
            
            if ((fstr[i] >= 'A') && (fstr[i] <= 'Z')) {
                a++;
            }

            if ((fstr[i] >= 'a') && (fstr[i] <= 'z')) {
                b++;
            }

            if (fstr[i] == '_') {
                c++;
            }

        }
        else {
            err++;
        }
        i++;
    }

    if ((a > 0) && (b > 0) && (err == 1) && (c == 0)) {
        type = 1;
    }

        if ((b > 0) && (c > 0) && (err == 1) && (a == 0)) {
            type = 2;
        
    }
}
void type0() {   
    fputs("error\n",f2);
}
void type1() {   
    i = 0;

        while (fstr[i] != '\0') {
            if (fstr[i] == tolower(fstr[i])) {
                putc(fstr[i], f2);
                i++;
            }
            else if (fstr[i] == toupper(fstr[i])) {
                putc('_', f2);
                putc(tolower(fstr[i]), f2);
                i++;
            }

        }
}
void type2() {

    i = 0;

    while (fstr[i] != '\0') {
        if (fstr[i] == '_') {
            putc(toupper(fstr[i + 1]),f2);
            i++;
        }
        else {
            putc(fstr[i], f2);
        }
        i++;
    }

}
int main() {
    f1 = fopen("Vhodnoy.txt", "r");
    f2 = fopen("Vihodnoy.txt", "w");

    while (fgets(fstr, sizeof(fstr), f1)) {

        type012();
                     
        if (type == 0) {
            type0();
        }
        else {
            if (type == 1) {
                type1();
            }
            else {
                if (type == 2) {
                    type2();
                }
            }
        }
    }

    fclose(f2);
    fclose(f1);

    return 0;
}


