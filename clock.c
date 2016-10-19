#define F_CPU 1600000UL

#include<avr/io.h>
#include<util/delay.h>

//Time setting constants
int value=0;
int shift=0;
int okflag=0;
int flag=0;

int a[4]={0,0,0,0};



//During Match


/*
0-0b01111110
1-0b00110000
2-0b01101101
3-0b01111001
4-0b00110011
5-0b01011011
6-0b01011111
7-0b01110000
8-0b01111111
9-0b01111011
*/

//During setting time only SSD1 will display time
void setInc(){
	
		value=(value+1)%10;
		
		//Value of shift is 0
		if(shift==0){
		
			PORTA&=0b00000111;////Accessing SSD1-1
			if(value==0){
				PORTC=0b01111110;//Displaying 0
		    }
		    
		    if(value==1){
				PORTC=0b00110000;//Displaying 1
		    }
		    
		    if(value==2){
				PORTC=0b01101101;//Displaying 2
		    }
		    
		    if(value==3){
				PORTC=0b01111001;//Displaying 3
		    }
		    
		    if(value==4){
				PORTC=0b00110011;//Displaying 4
		    }
		    
		    if(value==5){
				PORTC=0b01011011;//Displaying 5
		    }
		    
		    if(value==6){
				PORTC=0b01011111;//Displaying 6
		    }
		    
		    if(value==7){
				PORTC=0b01110000;//Displaying 7
		    }
		    
		    if(value==8){
				PORTC=0b01111111;//Displaying 8
		    }
		    
		    if(value==9){
				PORTC=0b01111011;//Displaying 9
		    }
		}
		    
		    //Value of shift is 1
		    if(shift==1){
		
			PORTA&=0b00001011;////Accessing SSD1-2
			if(value==0){
				PORTC=0b01111110;//Displaying 0
		    }
		    
		    if(value==1){
				PORTC=0b00110000;//Displaying 1
		    }
		    
		    if(value==2){
				PORTC=0b01101101;//Displaying 2
		    }
		    
		    if(value==3){
				PORTC=0b01111001;//Displaying 3
		    }
		    
		    if(value==4){
				PORTC=0b00110011;//Displaying 4
		    }
		    
		    if(value==5){
				PORTC=0b01011011;//Displaying 5
		    }
		    
		    if(value==6){
				PORTC=0b01011111;//Displaying 6
		    }
		    
		    if(value==7){
				PORTC=0b01110000;//Displaying 7
		    }
		    
		    if(value==8){
				PORTC=0b01111111;//Displaying 8
		    }
		    
		    if(value==9){
				PORTC=0b01111011;//Displaying 9
		    }
		}
		
		//Value of Shift is 2
		if(shift==2){
		
			PORTA&=0b00001101;////Accessing SSD1-3
			if(value==0){
				PORTC=0b01111110;//Displaying 0
		    }
		    
		    if(value==1){
				PORTC=0b00110000;//Displaying 1
		    }
		    
		    if(value==2){
				PORTC=0b01101101;//Displaying 2
		    }
		    
		    if(value==3){
				PORTC=0b01111001;//Displaying 3
		    }
		    
		    if(value==4){
				PORTC=0b00110011;//Displaying 4
		    }
		    
		    if(value==5){
				PORTC=0b01011011;//Displaying 5
		    }
		    
		    if(value==6){
				PORTC=0b01011111;//Displaying 6
		    }
		    
		    if(value==7){
				PORTC=0b01110000;//Displaying 7
		    }
		    
		    if(value==8){
				PORTC=0b01111111;//Displaying 8
		    }
		    
		    if(value==9){
				PORTC=0b01111011;//Displaying 9
		    }
    	}
    	
    	//Value of Shift is 3
    	if(shift==3){
		
			PORTA&=0b00001110;////Accessing SSD1-4
			if(value==0){
				PORTC=0b01111110;//Displaying 0
		    }
		    
		    if(value==1){
				PORTC=0b00110000;//Displaying 1
		    }
		    
		    if(value==2){
				PORTC=0b01101101;//Displaying 2
		    }
		    
		    if(value==3){
				PORTC=0b01111001;//Displaying 3
		    }
		    
		    if(value==4){
				PORTC=0b00110011;//Displaying 4
		    }
		    
		    if(value==5){
				PORTC=0b01011011;//Displaying 5
		    }
		    
		    if(value==6){
				PORTC=0b01011111;//Displaying 6
		    }
		    
		    if(value==7){
				PORTC=0b01110000;//Displaying 7
		    }
		    
		    if(value==8){
				PORTC=0b01111111;//Displaying 8
		    }
		    
		    if(value==9){
				PORTC=0b01111011;//Displaying 9
		    }
		}
		
}

void setShift(){
	a[shift]=value;
	shift=(shift+1)%4;
	value=0;
}
void setOK(){
	flag=1;
}

int time_in_sec(int a[]){
	int sec=0;
	sec=(a[0]*10)+a[1])*60)+((a[2]*10)+a[3]);
	return sec;
}

void display_SSD1(int l){//9999
	int m,m1,m2,s,s1,s2;
	
	m=l/100;
	m1=(m/60)/10;
	m2=(m/60)%10;
	
	s=l%100;
	s1=s/10;
	s2=s%10;
	
	//For m1
	PORTA&=(1<<3);
	if(m1==0)
		PORTC=0b01111110;
	if(m1==1)
		PORTC=0b00110000;
	if(m1==2)
		PORTC=0b01101101;
	if(m1==3)
		PORTC=0b01111001;
	if(m1==4)
		PORTC=0b00110011;
	if(m1==5)
		PORTC=0b01011011;
	if(m1==6)
		PORTC=0b01011111;
	if(m1==7)
		PORTC=0b01110000;
	if(m1==8)
		PORTC=0b01111111;
	if(m1==9)
		PORTC=0b01111011;
	_delay_ms(5);
		
	//For m2
	PORTA&=(1<<2);
	if(m1==0)
		PORTC=0b01111110;
	if(m1==1)
		PORTC=0b00110000;
	if(m1==2)
		PORTC=0b01101101;
	if(m1==3)
		PORTC=0b01111001;
	if(m1==4)
		PORTC=0b00110011;
	if(m1==5)
		PORTC=0b01011011;
	if(m1==6)
		PORTC=0b01011111;
	if(m1==7)
		PORTC=0b01110000;
	if(m1==8)
		PORTC=0b01111111;
	if(m1==9)
		PORTC=0b01111011;
	_delay_ms(5);
		
	//For s1
	PORTA&=(1<<1);
	if(m1==0)
		PORTC=0b01111110;
	if(m1==1)
		PORTC=0b00110000;
	if(m1==2)
		PORTC=0b01101101;
	if(m1==3)
		PORTC=0b01111001;
	if(m1==4)
		PORTC=0b00110011;
	if(m1==5)
		PORTC=0b01011011;
	if(m1==6)
		PORTC=0b01011111;
	if(m1==7)
		PORTC=0b01110000;
	if(m1==8)
		PORTC=0b01111111;
	if(m1==9)
		PORTC=0b01111011;
	_delay_ms(5);
		
	//For s2
	PORTA&=(1<<3);
	if(m1==0)
		PORTC=0b01111110;
	if(m1==1)
		PORTC=0b00110000;
	if(m1==2)
		PORTC=0b01101101;
	if(m1==3)
		PORTC=0b01111001;
	if(m1==4)
		PORTC=0b00110011;
	if(m1==5)
		PORTC=0b01011011;
	if(m1==6)
		PORTC=0b01011111;
	if(m1==7)
		PORTC=0b01110000;
	if(m1==8)
		PORTC=0b01111111;
	if(m1==9)
		PORTC=0b01111011;
	_delay_ms(5);
		
	
	
}

void display_SSD2(int l){//9999
	int m,m1,m2,s,s1,s2;
	
	m=l/60;
	m1=m/10;
	m2=m%10;
	
	s=l%100;
	s1=s/10;
	s2=s%10;
	
	//For m1
	PORTB&=(1<<3);
	if(m1==0)
		PORTD=0b01111110;
	if(m1==1)
		PORTD=0b00110000;
	if(m1==2)
		PORTD=0b01101101;
	if(m1==3)
		PORTD=0b01111001;
	if(m1==4)
		PORTD=0b00110011;
	if(m1==5)
		PORTD=0b01011011;
	if(m1==6)
		PORTD=0b01011111;
	if(m1==7)
		PORTD=0b01110000;
	if(m1==8)
		PORTD=0b01111111;
	if(m1==9)
		PORTD=0b01111011;
	_delay_ms(5);
		
	//For m2
	PORTB&=(1<<2);
	if(m1==0)
		PORTD=0b01111110;
	if(m1==1)
		PORTD=0b00110000;
	if(m1==2)
		PORTD=0b01101101;
	if(m1==3)
		PORTD=0b01111001;
	if(m1==4)
		PORTD=0b00110011;
	if(m1==5)
		PORTD=0b01011011;
	if(m1==6)
		PORTD=0b01011111;
	if(m1==7)
		PORTD=0b01110000;
	if(m1==8)
		PORTD=0b01111111;
	if(m1==9)
		PORTD=0b01111011;
	_delay_ms(5);
		
	//For s1
	PORTB&=(1<<1);
	if(m1==0)
		PORTD=0b01111110;
	if(m1==1)
		PORTD=0b00110000;
	if(m1==2)
		PORTD=0b01101101;
	if(m1==3)
		PORTD=0b01111001;
	if(m1==4)
		PORTD=0b00110011;
	if(m1==5)
		PORTD=0b01011011;
	if(m1==6)
		PORTD=0b01011111;
	if(m1==7)
		PORTD=0b01110000;
	if(m1==8)
		PORTD=0b01111111;
	if(m1==9)
		PORTD=0b01111011;
	_delay_ms(5);
		
    //For s2
	PORTB&=(1<<0);
	if(m1==0)
		PORTD=0b01111110;
	if(m1==1)
		PORTD=0b00110000;
	if(m1==2)
		PORTD=0b01101101;
	if(m1==3)
		PORTD=0b01111001;
	if(m1==4)
		PORTD=0b00110011;
	if(m1==5)
		PORTD=0b01011011;
	if(m1==6)
		PORTD=0b01011111;
	if(m1==7)
		PORTD=0b01110000;
	if(m1==8)
		PORTD=0b01111111;
	if(m1==9)
		PORTD=0b01111011;
	_delay_ms(5);
}

int main(){
	int i=0;
	int p1[4],p2[4];
	int pause_flag=0;
	int p1_sec=0;
	int p2_sec=0;
	
	DDRA=0b00011111;/*PA0-PA3=>SSD1,PA4=>LED1,PA5-PA7=>(P1,OK,PAUSE)SWITCHES*/
	DDRB=0b00011111;/*PB0-PB3=>SSD2,PB4=>LED2,PB5-PB7=>(SHIFT,INCREMENT,P2)SWITCHES*/
	DDRC=0b11111111;/*SSD1 DATA PINS*/
	DDRD=0b11111111;/*SSD2 DATA PINS*/
	
	while(flag==0){//Setting Time
		if(PINB&(1<<6))//Increment switch is pressed
			setInc();
		if(PINB&(1<<7))//Shift switch is pressed
			setShift();
		if(PINA&(1<<6))//OK switch is pressed
			setOK();
		}
	
	for(i=0;i<4;i++){
		p1[i]=a[i];
		p2[i]=a[i];
	}
	
	p1_sec=time_in_sec(p1);
	p2_sec=time_in_sec(p2);
	
	while(1){
		if(PINB&(1<<5)){//P1 player has pressed ,time of P2 will decrement
			while( !(PORTA&(1<<7)) || !(PORTA&(1<<5)) ){//until P2 has pressed OR PAUSED pressed 
				PORTA|=(1<<4);//Lighting Up the Player 2's LED
				_delay_ms(1000);
				p2_sec=p2_sec -1;
				display_SSD1(p1_sec);
				display_SSD2(p2_sec);
			}
		}
		if(PINA&(1<<5)){//P2 player has pressed ,time of P1 will decrement
			while( !(PINA&(1<<7)) || !(PINB&(1<<5)) ){//until P1 has pressed OR PAUSED pressed 
			    PORTB|=(1<<4);//Lighting Up the Player 1's LED
				_delay_ms(1000);
				p1_sec=p1_sec -1;
				display_SSD1(p1_sec);
				display_SSD2(p2_sec);
			}	
		}
		if(PINA&(1<<7)){//Paused pressed
			while(pause_flag==0){
				display_SSD1(p1_sec);
				display_SSD2(p2_sec);
					
				if(PINA&(1<<7){//Paused pressed again
					pause_flag=1;
				}
			}
			
		}
		
	}
	
	return 0;
}
