#include <stdio.h>

int faculteit(int n)
{
    if(n==1)
    {
        return 1;
    }
    else
    {
        return n*faculteit(n-1);
    }
}

int main(int argc, char **argv)
{
    int i;

    if(argc>1)
    {
        printf("%d nummers ingegeven waarvan de faculteit berekend wordt\n\n",argc-1);
        for(i=1;i<argc;i++)
        {
            printf("De faculteit van %d is %d\n",atoi(argv[i]),faculteit(atoi(argv[i])));
        }    
    }
}
