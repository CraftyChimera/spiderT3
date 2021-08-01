#include<stdio.h>
#include<ctype.h>
int main()
{char c;int sum=0,sum2=0,i=0;
while(isdigit(c=getc(stdin))) //get one digit at a time since there is no datatype to hold in 10^1000
{sum+=c-'0';i++;}//take in as char and convert to int since we need to do addition
if(i==1)i=0;//if there's exactly one digit we are done and no digit sums need to be done
else i=1;//This accounts for getting digit by digit in the input step,in case the number was not one digit
while(sum/10>0)
{sum2=0;//Straight forward step
while(sum>0)
{sum2+=sum%10;
sum/=10;}
sum=sum2;
i++;}
printf("%d\n",i);
return 0;
}
