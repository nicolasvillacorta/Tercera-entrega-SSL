#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

void iniVec(char *pal)
{
    int i=0;
    while(i<31)
    {
        pal[i]='\0';
        i++;
    }
}

void scanner(char *pal, FILE* p2)
{
    int f=0;

    if(pal[0]==':' && pal[1]=='=' && pal[2]=='\0')
    {
        fprintf(p2, " es el simbolo de ASIGNACION.\n");
        f=1;
    }
    if(pal[0]==',' && pal[1]=='\0')
    {
        fprintf(p2, " es un caracter de puntuación.\n");
        f=1;
    }
    if(pal[0]==';' && pal[1]=='\0')
    {
        fprintf(p2, " es un caracter de puntuación.\n");
        f=1;
    }
    if(pal[0]=='+' && pal[1]=='\0')
    {
        fprintf(p2, " es el operador de SUMA.\n");
        f=1;
    }
    if(pal[0]=='-' && pal[1]=='\0')
    {
        fprintf(p2, " es el operador de RESTA.\n");
        f=1;
    }
    if(pal[0]==')' && pal[1]=='\0')
    {
        fprintf(p2, " es el caracter: PARENDERECHO.\n");
        f=1;
    }
    if(pal[0]=='(' && pal[1]=='\0')
    {
        fprintf(p2, " es el caracter: PARENIZQUIERDO.\n");
        f=1;
    }
    if(pal[0]=='i' && pal[1]=='n' && pal[2]=='i' && pal[3]=='c' && pal[4]=='i' && pal[5]=='o' && pal[6]=='\0')
    {
        fprintf(p2, " es la palabra reservada INICIO.\n");
        f=1;
    }
    if(pal[0]=='l' && pal[1]=='e' && pal[2]=='e' && pal[3]=='r' && pal[4]=='\0')
    {
        fprintf(p2, " es la palabra reservada LEER.\n");
        f=1;
    }
    if(pal[0]=='e' && pal[1]=='s' && pal[2]=='c' && pal[3]=='r' && pal[4]=='i' && pal[5]=='b' && pal[6]=='i' && pal[7]=='r' && pal[8]=='\0')
    {
        fprintf(p2, " es la palabra reservada ESCRIBIR.\n");
        f=1;
    }
    if(pal[0]=='f' && pal[1]=='o' && pal[2]=='n' && pal[3]=='\0')
    {
        fprintf(p2, " es la palabra reservada FIN.\n");
        f=1;
    }
    if(f=0)
    {
        fprintf(p2, " es un IDENTIFICADOR.\n");
    }


}


int columna(char c)
{
        if(isalpha(c))
        {
            return 1;
        }
        if(isdigit(c))
        {
            return 2;
        }
        if(c=='+')
        {
            return 3;
        }
        if(c=='-')
        {
            return 4;
        }
        if(c=='(')
        {
            return 5;
        }
        if(c==')')
        {
            return 6;
        }
        if(c==',')
        {
            return 7;
        }
        if(c==';')
        {
            return 8;
        }
        if(c==':')
        {
            return 9;
        }
        if(c=='=')
        {
            return 10;
        }
        if(c=='\0')
        {
            return 11;
        }
        if(isspace(c))
        {
            return 12;
        }
}

int main()
{
    int mTT[15][13] = {{1, 3, 5, 6, 7, 8, 9, 10, 11, 14, 13, 0,14},
                       {1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
                       {99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99},
                       {4, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
                       {99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99},
                       {99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99},
                       {99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99},
                       {99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99},
                       {99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99},
                       {99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99},
                       {99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99},
                       {14, 14, 14, 14, 14, 14, 14, 14, 14, 12, 14, 14, 14},
                       {99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99},
                       {99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99},
                       {99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99}};

    FILE* p1;
    FILE* p2;
    p1=fopen("Archivo.txt","r");
    p2=fopen("nuevoArchivo.txt","w");
    int estado=0, i=0, j;
    char pal[32];
    iniVec(pal);
    char c;
    c = fgetc(p1);

    while(!feof)
    {
        pal[i]=c;
        j=columna(c);
        estado=mTT[estado][j];
        if(estado!=14 && estado!=99)
        {
            if(estado=14)
            {
                scanner(pal, p2);
            }
            else
            {
                fprintf(p2, "Error sintactico.\n");
            }

        }




    }






    return 0;
}
