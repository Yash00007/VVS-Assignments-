#include<stdio.h>
#include<ctype.h>
float getfloat(float *a){
   char c ;
   int flag = 0;
   double value = 0;
   double divisor = 10 ;
   int mul = 1;
   double sign = 1;
   while( ( c = getchar() ) != EOF){
   if(c == '-')
      sign = -1;
   if(!isdigit(c))
   { 
    // c is not space,+ or -. Also not a digit
     if( (c != '+') && (c != '-') && (c != '.') && (c != ' ') )
       { 
         value = (value *sign);
         *a = value;
         printf("returning : %f\n\n", value);
         return value ;
     }  
   }
   if(c == '.')
      {
        flag = 1;
      }
   if(isdigit(c)){
   if(flag == 1)
     {
      value = value + (c - '0' )/divisor;
      divisor = divisor*10 ;
      printf("* value = %f = %f + %f \n ",value,(float)(c-'0'),(float)(c - '0')/divisor*10);    
    }
   else
     {
      value = value*10 + (c - '0');
      mul = mul * 10;
      printf("value = %.2f \n",value);
     }
   }
   }   
   *a = value;
   return value;
}
int main(){
   float a;
   getfloat(&a);
   printf("\n\n%.2f\n\n",a);
   return 0;
}
