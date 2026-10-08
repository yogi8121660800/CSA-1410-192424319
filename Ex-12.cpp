#include <stdio.h>
#include <string.h>

char input[100];
int i = 0;

int E();
int EP();
int T();
int TP();
int F();

int main()
{
    printf("\nRecursive descent parsing for the following grammar\n");
    printf("\nE  -> TE'");
    printf("\nE' -> +TE'/@");
    printf("\nT  -> FT'");
    printf("\nT' -> *FT'/@");
    printf("\nF  -> (E)/ID");

    printf("\n\nEnter the string to be checked: ");
    scanf("%s", input);

    if (E())
    {
        if (input[i] == '\0')
            printf("\nString is accepted");
        else
            printf("\nString is not accepted");
    }
    else
    {
        printf("\nString is not accepted");
    }

    return 0;
}

int E()
{
    if (T())
    {
        if (EP())
            return 1;
        else
            return 0;
    }
    return 0;
}

int EP()
{
    if (input[i] == '+')
    {
        i++;

        if (T())
        {
            if (EP())
                return 1;
            else
                return 0;
        }
        return 0;
    }

    return 1;
}

int T()
{
    if (F())
    {
        if (TP())
            return 1;
        else
            return 0;
    }
    return 0;
}

int TP()
{
    if (input[i] == '*')
    {
        i++;

        if (F())
        {
            if (TP())
                return 1;
            else
                return 0;
        }
        return 0;
    }

    return 1;
}

int F()
{
    if (input[i] == '(')
    {
        i++;

        if (E())
        {
            if (input[i] == ')')
            {
                i++;
                return 1;
            }
            else
                return 0;
        }
        return 0;
    }
    else if ((input[i] >= 'a' && input[i] <= 'z') ||
             (input[i] >= 'A' && input[i] <= 'Z'))
    {
        i++;
        return 1;
    }

    return 0;
}