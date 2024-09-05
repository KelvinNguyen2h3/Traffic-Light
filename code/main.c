#include <REGX52.H>
#include "..\lib\delay.h"

unsigned char code Code7Seg[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
#define ledPort P2
sbit green = P0^0;
sbit yellow = P0^1;
sbit red = P0^2;
sbit seg1 = P3^0;
sbit seg2 = P3^1;

void main(){
	int count,i;
	green = 0;
	yellow = 0;
	red = 0;
	while(1){
		//green
		green = 1;
		for(count=60;count>=0;count--){
			for(i=0;i<500;i++){
				//2ms
				ledPort = Code7Seg[count%10];
				seg2 = 0;
				delay_ms(1); //1ms
				seg2 = 1;
				
				ledPort = Code7Seg[count/10];
				seg1 = 0;
				delay_ms(1); //1ms
				seg1 = 1;
			}
		}
		green = 0;
		//yellow
		yellow = 1;
		for(count=5;count>=0;count--){
			for(i=0;i<500;i++){
				//2ms
				ledPort = Code7Seg[count%10];
				seg2 = 0;
				delay_ms(1); //1ms
				seg2 = 1;
				
				ledPort = Code7Seg[count/10];
				seg1 = 0;
				delay_ms(1); //1ms
				seg1 = 1;
			}
		}
		yellow = 0;
		//red
		red = 1;
		for(count=60;count>=0;count--){
			for(i=0;i<500;i++){
				//2ms
				ledPort = Code7Seg[count%10];
				seg2 = 0;
				delay_ms(1); //1ms
				seg2 = 1;
				
				ledPort = Code7Seg[count/10];
				seg1 = 0;
				delay_ms(1); //1ms
				seg1 = 1;
			}
		}
		red = 0;
	}
}