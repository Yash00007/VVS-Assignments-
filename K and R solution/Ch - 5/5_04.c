#include<stdio.h>
int strend(char *s,char *t){
//we will be finding string t at the end of s

//First find end of the both strings
int j=0 , i = 0;
// i is for target string and j for source
   while(*s != '\0'){
   j++; 
   s++;
   }
   while(*t != '\0'){
   i++;
   t++;
   }  
   //if target is larger than source return 0
   if(i > j)
      return 0;
   t--;
   s--;
   while(i != 0 )
   {
   if( *s != *t){

   return 0;
   }
   s--;
   t--;
   i--;
   }
   return 1;
}


int main(){
   char a[10] = "yash";
   char b[10] = "sh"; 
   printf("%d ", strend(a,b));
 


}
