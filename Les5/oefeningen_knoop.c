#include <stdio.h>
#include <stdlib.h>

struct knoop{
    int getal;
    struct knoop *next;
};

void print_lijst(const struct knoop *l)
{
    while( l != 0 )  //it's the pointer which gets null !
    {
        printf("%d \t",l->getal); //print node value
        l = l->next;
    }
    printf("\n");
}

struct knoop * zoek_element(struct knoop *l, int g)
{
    while (l != 0 && l->getal != g)
        l = l->next;
    return l;    
}

struct knoop * maak_lijst()
{
    struct knoop *l = 0;   
    struct knoop *tmp;
    int g;
    scanf("%d",&g);
    //1e knoop
    if(g!=0)
    {
        l = malloc(sizeof(struct knoop));
        l->getal = g;   
        tmp = l;
        scanf("%d",&g);
    }
    //"Al de rest"
    while(g!=0)
    {
       tmp->next = malloc(sizeof(struct knoop)); 
       tmp = tmp->next;
       tmp->getal = g;
       scanf("%d",&g);        
    }
    tmp->next = 0;
    return l;
}

struct knoop * maak_omgekeerde_lijst()
{
    struct knoop *l = 0;
    struct knoop * tmp;
    int g;
    
    scanf("%d",&g);
    
    while(g!=0)
    {
        tmp = malloc(sizeof(struct knoop)) ;
        tmp->getal = g;
        tmp->next = l;
        scanf("%d",&g);
        l = tmp;      
    }
    return l;   
}

//Pointer naar pointer als je een bestaande lijst aanpast
struct knoop * maak_gesorteerde_lijst(struct knoop *l, int g)
{
   //Note: dubbele waardes toegestaan
   struct knoop *h;
   struct knoop *tmp;

   if (l == 0 || l->getal >= g)
   {
       h = malloc(sizeof(struct knoop));
       h->getal = g;
       h->next = l;
       l = h;  
   }
   else
   {
       h = l;
       while(h->next !=0 && h->next->getal <= g)
       {
         h = h->next;
       }    
       tmp = malloc(sizeof(struct knoop));
       tmp->getal = g;
       tmp->next = h->next;
       h->next = tmp;      
   }
   return l;   
}

int main()
{
    int getal_to_search;
    //struct knoop *lijst;
    struct knoop *lijst2;
    struct knoop *res;

    //lijst = maak_lijst();
    lijst2 = maak_omgekeerde_lijst();
    maak_gesorteerde_lijst(lijst2,3);

    //print_lijst(lijst);
    print_lijst(lijst2);

    printf("Enter a search value:\n");
    scanf("%d",&getal_to_search);
    res = zoek_element(lijst2, getal_to_search);
    if( res != 0 )
        printf("Gevonden: %d\n",res->getal);
}
