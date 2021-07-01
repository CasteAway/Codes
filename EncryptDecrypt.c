#include<stdio.h>
#include<string.h>
#include<stdbool.h>
void plainText();
void orignal(char*);
void encryption(char*);
void decryption(char*);
bool check(char*);
bool goes[10];
int length;
int key=0;
void main()
{
   plainText();
}

void plainText()
{
    char message[10];
    printf("Enter 9 digit message(must be small letters) > ");  scanf("%s",message);
    printf("Enter key to encrypt the data                > ");  scanf("%d",&key);
    length=strlen(message);
   
    check(message) ? encryption(message)  : printf("Does not satisfy The condition.\n") ; 
}


void encryption(char* OrignalMessage)
{
    printf("Orignal message  > %s\n",OrignalMessage);
    char cipher[10];
    int i=0;
    int capital = 0xDF;                  //used to capitalize the cipher text
    
                                         //encrypt orignal text
                                         
    while(i<length)
    {   int temp=0;
        temp  = (int)OrignalMessage[i] + key ; 
        if(temp>122) 
        {
            temp-=26;  goes[i]=1;
        }
        cipher[i] = ( (char)temp & capital );
        i++;
    }
    
                                        // print cipher text
    
    printf("Encrypted text > ");
    for(i=0;i<length;i++)
    {
        printf("%c",cipher[i]);
    }
    printf("\n");
    
    decryption(cipher);
}

void decryption(char* CipherText)
{
    char decryptedMessage[10];
    int k=0;
    int small = 0x20;                 // convert Capital to small the decryptedMessage
    
                                      //Decrypt orignal text
                                         
    while(k<length)
    {
        CipherText[k] = (char)((int)CipherText[k] + small);
        
        if(goes[k] == 1) 
        { 
        decryptedMessage[k] = (char)((int)CipherText[k] + 26 - key);
        } 
        else
        {
        decryptedMessage[k] = (char)((int)CipherText[k]-key); 
        } 
        k++;
    }
    
                                 // print decryptedMessage text
    printf("Decrypted text > ");
    for(k=0;k<length;k++)
    {
        printf("%c",decryptedMessage[k]);
    }
    
}


bool check(char* message)
{
    int count=0;
    if(length>9) return 0;
    for(int i=0;message[i]!='\0';i++)
    {
        if(message[i] >='A' && message[i] <='Z') return 0;
    }
    
    return 1;
}

