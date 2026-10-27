%{
#include <stdio.h>
#include <string.h>

int flag = 0;
%}

%%
^[a-z0-9.]+@[a-z]+(\.com|\.in)$ { flag = 1; }
.*                               { flag = 0; }
%%

int main()
{
    printf("Enter email: ");
    yylex();

    if(flag == 1)
        printf("Accepted\n");
    else
        printf("Not Accepted\n");

    return 0;
}

int yywrap()
{
    return 1;
}