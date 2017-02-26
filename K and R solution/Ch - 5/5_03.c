#include<stdio.h>

void strcat1(char *s, char *t){
   
   while(*s != '\0'){
   s++;
   }
   while((*t)!='\0'){
   *s = *t ;
   t++ ;
   s++;
   }
}
int main(){
   char a[10]= "yash ";
   char b[10] = "shukla ";
   strcat1(a,b);      
   printf("%s",a); 

   return 0;
}
