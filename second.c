#include <stdio.h>

int adjustValue(char ch);

int values[4] = {1, 2, 4, 8};
char results[16] = {'0','1','2','3','4','5','6','7',
                    '8','9','a','b','c','d','e','f'};

int
main(int argc, char *argv[])
{
    char val_a, val_b;
    int result, a_aux, b_aux;
    int fst_a, snd_b;
    int aux = 0, counter = 0;
    FILE *buff_a, *buff_b;

    buff_a = fopen("buff1.txt", "r");
    buff_b = fopen("buff2.txt", "r");

    while(((val_a = fgetc(buff_a))!= EOF) && ((val_b = fgetc(buff_b))!= EOF))
    {
        fst_a = adjustValue(val_a);
        snd_b = adjustValue(val_b);

        counter = 0;
        aux = 0;
        while(counter < 4)
        {
            aux = aux << 1;
            a_aux = fst_a & values[3-counter];
            b_aux = snd_b & values[3-counter];

            //printf("%d %d\n", a_aux, b_aux);
            aux = aux | ((a_aux == 0 && b_aux != 0) || (a_aux != 0 && b_aux == 0));
            counter++;
        }
        
        printf("%c", results[aux]);
    }

    printf("\n");

    fclose(buff_a); fclose(buff_b);
    return 0;
}

int adjustValue(char ch)
{
    if (ch >= 48 && ch <= 57)
        return ch - 48;
    else if (ch >= 97 && ch <= 102)
        return ch - 87;
    else return -1;
}