#include<stdio.h>
#include<ctype.h>
/*
Schrijf een procure wis(s) die uit de string s alle tekens wist die geen kleine letter of geen blanco zijn. Je mag gebruik maken van de functies islower(char) en isspace(char). Test uit met de string"8d’a7!<t-)>+. -)4h&!e9)b*(  )j’(e)!4\n8g|’92o!43e5d/.’ 2 3g*(e(’d22a’(a25n’("."))))"
*/

void shiftleft(char * string);
void decode(char * string);

int main()
{
    char string[]="8d’a7!<t-)>+. -)4h&!e9)b*(  )j’(e)!4\n8g|’92o!43e5d/.’ 2 3g*(e(’d22a’(a25n’(\".\"))))";
    decode(string);
    printf("The new decoded string is %s\n",string);
}

void decode(char * string)
{
    while(*string)
    {
        if(!islower(*string) && !isspace(*string))
            shiftleft(string);
        else
            string++;
    }    
}

void shiftleft(char * string)
{
    while(*string)
    {
        *string = *(string+1);
        string++;
    }
}
