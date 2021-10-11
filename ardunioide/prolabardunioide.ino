#include <LiquidCrystal.h>  
#include <stdio.h>
#include <stdlib.h>

const int rs=13,en=12,d4=11,d5=10,d6=9,d7=8;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);


int sum=0;

int k5=20, k10=20, k20=10, k50=30, k100=5;                                  //KASADAKI 5 10 20 50 100 BANKNOT ADETI
int a5=0, a10=0, a20=0, a50=0, a100=0;                                      //KULLANICIDAN ALINAN BANKNOT ADETI
int kopukleme=0,yikama=0,kurulama=0,cilalama=0;                             //GIRILEN ISLEM ADETI
int kopuklemeadet=30,yikamaadet=50,kurulamaadet=100,cilalamaadet=20;        //KASADAKI KALAN HIZMET ADETI
int kopuklemefiyat=15,yikamafiyat=10,kurulamafiyat=5,cilalamafiyat=50;      //HIZMET FIYATI
int c1=0,c2=1,c3=2,c4=3,c5=4,cbitis=5,creset=6,yesil=A0,kirmizi=A1;
int b1=0,b2=0,b3=0,b4=0,b5=0,bitis=0,reset=0,kled=0,yled=0;
int adim=0;                                                                 //ISLEMLERIN SIRASINI TUTAN DEGISKEN
int number;                                                                 //RANDOM SAYI DEGISKENI
int paraustu=0,p5=0,p10=0,p20=0,p50=0,p100=0;                               //PARAUSTU BANKNOT ADETI
int islemtutar=0;                                                           //SECILEN ISLEMLERIN FIYAT TOPLAMI
int sayac=0;
int p;                                                                      //PARAUSTU BANKNOT ADETI TOPLAMI

void setup() {
  pinMode(yesil,OUTPUT);
  pinMode(kirmizi,OUTPUT);
  pinMode(c1,INPUT);
  pinMode(c2,INPUT);
  pinMode(c3,INPUT);
  pinMode(c4,INPUT);
  pinMode(c5,INPUT);
  pinMode(cbitis,INPUT);
  pinMode(creset,INPUT);
}


void paraGirisi(){ 
  delay(500);
   
    if (reset== HIGH)                      //RESETLEME BUTONU
 { 
  sum=0;
  a5=0; 
  a10=0;
  a20=0;
  a50=0;
  a100=0;  
 }

 if (b1 == HIGH) 
 {                    
  a5= a5+1;
  sum = sum + 5;                       
 }
 
 if (b2 == HIGH)
 {                   
  a10=a10+1;
  sum = sum + 10;          
 }
 
 if (b3 == HIGH)                    
 { 
  a20=a20+1;
  sum = sum + 20;        
 }

 if (b4 == HIGH)                     
 {  
  a50=a50+1;
  sum = sum + 50;         
 }

 if (b5 == HIGH)                     
 {
  a100=a100+1;
  sum = sum + 100;         
 } 
 
  if(bitis==HIGH)
  {
    sayac++;
  }

 delay(100); 
}

void islemGiris(){
  
   if (reset== HIGH)                      //RESETLEME BUTONU
 { 
  kopukleme=0; 
  yikama=0;
  kurulama=0;
  cilalama=0;
 }

 if (b1 == HIGH) 
 {                    
  kopukleme=kopukleme+1;                      
 }
 
 if (b2 == HIGH)
 {                   
  yikama=yikama+1;         
 }
 
 if (b3 == HIGH)                    
 { 
  kurulama=kurulama+1;
 }

 if (b4 == HIGH)                     
 {  
 cilalama=cilalama+1;         
 }
 
  if(bitis==HIGH)
  {
    sayac++;
  }
}

void bakiyeKontrol(){
  islemtutar=(kopukleme*kopuklemefiyat)+(yikama*yikamafiyat)+(kurulama*kurulamafiyat)+(cilalama*cilalamafiyat);
  if(sum>=islemtutar){
    sayac=sayac+2;
    adim++;
  }
  else{
    sayac++;
    kopukleme=0; 
    yikama=0;
    kurulama=0;
    cilalama=0;
    sum=0;
    a5=0; 
    a10=0;
    a20=0;
    a50=0;
    a100=0;
  }
}

void sayiUret(){
   
  number= millis()%4 +1;
  if(number==2){
    digitalWrite(kirmizi,HIGH);
    delay(2500);
    digitalWrite(kirmizi,LOW);
    adim=4;
    sayac=10;
  }
  else{
    digitalWrite(yesil,HIGH);
    delay(2500);
    digitalWrite(yesil,LOW);
    adim++;
    sayac++;
  }
  
}

void paraSikisma(){
  if(number==2){
   
      kopukleme=0; 
      yikama=0;
      kurulama=0;
      cilalama=0;
      sum=0;
      a5=0; 
      a10=0;
      a20=0;
      a50=0;
      a100=0; 
      sayac=0;
      adim=0;
    
}
  else
  {
    k5=k5+a5;
    k10=k10+a10;
    k20=k20+a20;
    k50=k50+a50;
    k100=k100+a100;
    kopuklemeadet=kopuklemeadet-kopukleme;
    yikamaadet=yikamaadet-yikama;
    kurulamaadet=kurulamaadet-kurulama;
    cilalamaadet=cilalamaadet-cilalama;
    sayac++;
    adim++;    
  }
}

void paraUstuHesapla(){
    paraustu=sum-(kopukleme*kopuklemefiyat);
    paraustu=paraustu-(yikama*yikamafiyat);
    paraustu=paraustu-(kurulama*kurulamafiyat);
    paraustu=paraustu-(cilalama*cilalamafiyat);
    sayac++;
  
}

void paraUstu(){
 
  if(paraustu>=100){
      p100=paraustu/100;
      if(k100>=p100){
        paraustu=paraustu-(p100*100);
      } 
      else{
        p100=0;  
      }
  }
  if(paraustu>=50){
    p50=paraustu/50;
    if(k50>=p50){
      paraustu=paraustu-(p50*50);
    } 
    else{
      p50=0;   
    }
  }
  if(paraustu>=20){
    p20=paraustu/20;
    if(k20>=p20){
      paraustu=paraustu-(p20*20);
    } 
    else{
      p20=0;  
    }
  }
  if(paraustu>=10){
    p10=paraustu/10;
    if(k10>=p10){
      paraustu=paraustu-(p10*10);
    }
    else{
      p10=0;    
    }
  }
  if(paraustu>=5){
    p5=paraustu/5;
    if(k5>=p5){
      paraustu=paraustu-(p5*5);
    } 
    else{
      p5=0;  
    }
  }
  sayac++; 
  p=p100+p50+p20+p10+p5;   
     
}

void kasaKontrol(){
  if(p>0){
  if(k100>=p100 && k50>=p50 && k20>=p20 && k10>=p10 && k5>=p5){
    k100=k100-p100;
    k50=k50-p50;
    k20=k20-p20;
    k10=k10-p10;
    k5=k5-p5;
    sayac=sayac+2;
    adim++;    
  }
  
  }
  else
  {
    sayac++;                                                     //YETERSIZ BAKIYE DURUMU     
  }
}


void loop() {
  b1=digitalRead(c1);
  b2=digitalRead(c2);
  b3=digitalRead(c3);
  b4=digitalRead(c4);
  b5=digitalRead(c5);
  bitis=digitalRead(cbitis);
  reset=digitalRead(creset);
  
  if(adim==0){
    if(sayac==0){
      lcd.print("PARA GIRISI: ");
      delay(1000);
      lcd.clear();
      sayac++;
    }
    else if(sayac==1){   
      paraGirisi();
    }
    else if(sayac==2){  
    lcd.print(sum);
    lcd.print(" TL ATTINIZ");
    delay(2000);
    sayac++;
    }
    else if(sayac==3){
      lcd.clear();
      sayac++; 
      adim++;
    }              
  }
  else if(adim==1){
    if(sayac==4){
      lcd.print("ISLEM SECINIZ: ");
      delay(1000);
      lcd.clear();
      sayac++;
    }
    else if(sayac==5){
      islemGiris();
    }
    else if(sayac==6){
      lcd.print("KOPUKLEME: ");
      lcd.print(kopukleme);
      delay(1000);   
      lcd.clear();
      lcd.print("YIKAMA: ");
      lcd.print(yikama);
      delay(1000);   
      lcd.clear();
      lcd.print("KURULAMA: ");
      lcd.print(kurulama);
      delay(1000);   
      lcd.clear();
      lcd.print("CILALAMA: ");
      lcd.print(cilalama);
      delay(1000);   
      lcd.clear();
      sayac++;
      adim++;      
    }    
  }
  else if(adim==2){
    if(sayac==7){
      sayiUret();      
      lcd.print("URETILEN SAYI ");
      lcd.print(number);
      delay(1000);
      lcd.clear();
    }      
  }
  else if(adim==3){
    if(sayac==8){
      bakiyeKontrol();
    }
    else if(sayac==9){
      lcd.print("YETERSIZ PARA!"); 
      delay(2000);
      lcd.clear();
      sayac=0;
      adim=0;
    }     
  }
  else if(adim==4){
    if(sayac==10){
      paraSikisma();            
    }
  }
  else if(adim==5){
    if(sayac==11){
      paraUstuHesapla();
    }
    else if(sayac==12){
      lcd.print("PARA USTU: ");
      lcd.print(paraustu);
      delay(1000);
      lcd.clear(); 
      sayac++;
      
    }
    else if(sayac==13){
      paraUstu();
      
    }
    else if(sayac==14){
      lcd.print(p100);
      lcd.print(" YUZLUK");
      delay(1000);
      lcd.clear();
      lcd.print(p50);
      lcd.print(" ELLILIK");
      delay(1000);
      lcd.clear();
      lcd.print(p20);
      lcd.print(" YIRMILIK");
      delay(1000);
      lcd.clear();
      lcd.print(p10);
      lcd.print(" ONLUK");
      delay(1000);
      lcd.clear();
      lcd.print(p5);
      lcd.print(" BESLIK");
      delay(1000);
      lcd.clear();
      sayac++;
      adim++;
    }
}
  else if(adim==6){
    if(sayac==15){
       kasaKontrol();
    }
    else if(sayac==16){
       lcd.print("KASADA PARA YOK");
       delay(2000);
    }
}
  else if(adim==7){
    if(sayac==17){
      lcd.print("ISLEM TAMAMLANDI");
      delay(10000);
    }
    
  } 
  delay(1000);
}
