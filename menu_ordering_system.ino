#include <LiquidCrystal.h>

int rs=12;
int rw=11;
int enable=10;

LiquidCrystal lcd(rs,rw,enable, 5, 4, 3, 2);
int order=6;
int select=7;
int send=8;

int dish=-1;  // no dish selected initially


void update(){
  if (digitalRead(order)==LOW) {
    return;
  }
  dish = (dish + 1) % 4;
  
  
  switch(dish){
    case 0:
        lcd.clear();
    	lcd.setCursor(0,0);
  		lcd.print("Select Menu:");
    	lcd.setCursor(0,1);
    	lcd.print("1.Pizza");
    	break;
  
  
  	case 1:
    	lcd.clear();
    	lcd.setCursor(0,0);
  		lcd.print("Select Menu:");
    	lcd.setCursor(0,1);
        lcd.print("2.Burger");
    	break;
    
    case 2:
    	lcd.clear();
    	lcd.setCursor(0,0);
  		lcd.print("Select Menu:");
    	lcd.setCursor(0,1);
        lcd.print("3.Chips ");
    	break;
     
    case 3:
    	lcd.clear();
    	lcd.setCursor(0,0);
  		lcd.print("Select Menu:");
    	lcd.setCursor(0,1);
        lcd.print("4.Soda ");
    	break;
  }
}


void handleSelect() {
  if(digitalRead(select)==HIGH){
  	lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("Order Confirmed");
  }
}

void handleReset() {
  if(digitalRead(send)==HIGH){
  	lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Okay Bye");
    lcd.setCursor(0,1);
    lcd.print("Have a Nice Day");
   
  }
}
  

void setup() 
{
  pinMode(order, INPUT);
  pinMode(select, INPUT);
  pinMode(send, INPUT);

  
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("Jojo's Cafe");
  lcd.setCursor(0,1);
  lcd.print("Welcome");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Select Menu:");
  lcd.setCursor(0,1);
  lcd.print("Press oder");
 
}



void loop() 
{
  
  update();
  handleSelect();
  handleReset();
   
  delay(200);
}
 