#include <stdio.h>
#include <math.h>
int n,aa[10],ep[10],op[10],i,j,ol,el;
float odd[10],even[10],w=0,pu=0,ku=0;


float valodd(float k)
      {
        float temp=0;
        for(i=0,j=0;i<ol;i++,j=j+2)
        {
          temp=temp+odd[i]*pow(k,j);
        }
        return(temp);
      }



void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);                   //read
Serial.println("Enter order:"); 
delay(2000);
n=Serial.read();
Serial.println("Enter the coefficients:");
delay(5000);
for(i=0;i<=n+1;i++)
   {
    aa[i]=Serial.read();
   Serial.println(i);
  Serial.print("th coeff is ");
  Serial.print(aa[i]);    
   }



for(i=0,j=0;i<=n+1;i=i+2,j++)
    {
      ep[j]=aa[i];
      op[j]=aa[i+1];            
    }

if(n%2 ==0)         // even odd lenth
   {
    el=n/2+1;
    ol=n/2; 
   }
else
   {
    el=ol=n/2;
   }
   
   


for(i=0;i<=el;i++)               //for solving
   {
    odd[i]=op[i]*pow(-1,i);
    even[i]=ep[i]*pow(-1,i);
   }
if(odd[0] <0)
 {
  for(i=0;i<=el;i++)
  {
    odd[i]=-odd[i];
  }
 }


for(i=0;;i++)                    //find w
  {
   float t1=valodd(i);
   float t2=valodd(i+1);

    if(t1==0)
    w=t1;
    if(t2==0)
    w=t2;


   if(t1>0 && t2<0)
     {
      while(t1 != t2)
      {
        float t3=(t1=t2)/2;
        float temp=valodd(t3);
        if(temp>0)
        t1=t3;
        if(temp<0)
        t2=t3;
        if(temp=0);
        w=temp;
           
      }
     }
  }



        pu=2*3.1415/w;                  //pu


 
        
        for(i=0,j=0;i<el;i++,j=j+2)                       //ku
        {
          ku=ku+even[i]*pow(w,j);
        }
        






 Serial.println("Calculated Values are");
 Serial.println("Ku:");
 Serial.print(ku);
 Serial.println("pu:");
 Serial.print(pu);
 Serial.println("--------------------------");
 Serial.println("The PID Setiings are as follows");
 Serial.println("By Z-N methode:");
 Serial.println("CONTROLLER     Kp     Ti    Td     Ki    Kd "); 
 Serial.println("   P        ");
 Serial.print(ku*.5);
 Serial.print("  ");
 Serial.println("   PI       ");
 Serial.print(ku*.45);
 Serial.print(" ");
 Serial.print(pu/1.2);                                            
 Serial.println("    PID      ");
 Serial.print(ku*.6 );
 Serial.print(" ");
 Serial.print(pu/2);
 Serial.print(" ");
 Serial.print(pu/8);





}

void loop() {
  // put your main code here, to run repeatedly:


}
