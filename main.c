#include <stdio.h>
#include <locale.h>

int main(int argc, char *argv[]){
    setlocale(LC_ALL, "Russian");
    FILE *f1;
    FILE *f2;
    char fname[100];
    char key[100];
    char c;
    int cur=0;
    f2=fopen("output.txt", "w");
    printf("Введите название файла: ");
    scanf("%s",fname);
    f1=fopen(fname,"r");
    if (f1==NULL) {
        printf("Файл не найден!\n");
        return 0;
    }
    printf("Ключ: ");
    scanf("%s",key);

    while (!feof(f1)){
        if (fread(&c,1,1,f1)){
            if ((c>=97)&&(c<=122)){
                if ( (c+key[cur]-97)<=122) c=c+key[cur]-97;
                else
                    c=key[cur]+c-123;

                if (cur<strlen(key)-1) ++cur;
                else
                    cur=0;

            }
            fprintf(f2,"%c",c);
        }
    }


    fclose(f1);
    fclose(f2);


    f1=fopen("output.txt","r");
    f2=fopen("output2.txt","w");
    cur = 0;

    while (!feof(f1)){
        if (fread(&c,1,1,f1)){
            if ((c>=97)&&(c<=122)){
                if ( (c-key[cur]+97)>=97) c=c-key[cur]+97;
                else
                    c=c-key[cur]+123;
                if (cur<strlen(key)-1) ++cur;
                else
                    cur=0;
            }
            fprintf(f2,"%c",c);
        }
    }

    fclose(f1);
    fclose(f2);

    return 0;
}
