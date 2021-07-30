#include <stdio.h>
#include<string.h>
#define max 100000
void SUM(char[],char[],const int*);
void copy(char[],char[]);
char temp[max];
int n;

int main()
{
    char first[max]  = "1";
    char second[max] = "1";
    printf("Enter n > "); scanf("%d",&n);
    if(n<=2)               printf("1");
    else
    {
        for(int l=2;l<n;l++)
        {
            SUM(first,second,&l);
            copy(first,second);
            copy(second,temp);
        }
    }
    return 0;
}

//Function to calculate sum 
void SUM(char num1[max],char num2[max],const int* l)
{
    int a[max],b[max],sum[max];
    int ac=0,bc=0,sc=0;
    int reminder = 0;
    int i,j=0;
    char *pa,*pb;

    pa = num1; 
    pb = num2; 
    
    while(*pa){
        a[ac++] = *pa++ - 48;  
    }
    
    while(*pb){
         b[bc++] = *pb++ - 48;
    }

    if(ac<bc){
         for(i = ac;i > 0;i--){
             sum[sc++]= ((a[i-1] + b[--bc]) + reminder)%10;
             reminder = ((a[i-1] + b[bc]) + reminder)/10;
         }
         while(bc>0){
             sum[sc++] = b[--bc] + reminder;
             reminder = 0;
         }
    }
    else{
         for(i = bc;i > 0;i--){
             sum[sc++]= ((b[i-1] + a[--ac]) + reminder)%10;
            reminder = ((b[i-1] + a[ac]) + reminder)/10;
        }
         if(ac==0 && reminder==1)
             sum[sc++] = reminder;
            while(ac>0){
            sum[sc++] = a[--ac] + reminder;
                reminder = 0 ;
            }
    }
  
     for(i=sc-1;i>=0;i--){
         temp[j] = (char)(sum[i] + 48); 
         j++;
    }
    temp[j] = '\0';
    
   if(*l == n-1)
   {
       for(int k=0;k<sc;k++)
       {
       printf("%c",temp[k]);
       }
   }
     
}

// used to change strings 
void copy(char a[],char b[])
{
    int i=0;
         for(;b[i]!='\0';i++)
    {
        a[i] = b[i];
    }
    a[i] = '\0';
}
