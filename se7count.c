void delay(){
volatile int delay_count;
for (delay_count = 500000; delay_count != 0;delay_count--);
}

int main(void)
{
/* Declare volatile pointers to I/O registers (volatile means that the locations will not be cached,
* even in registers) */
volatile int * HEX_ptr = (int *) 0x00002000; // red LED address
//volatile int * HEX3_HEX0_ptr = (int *) 0xFF200020; // HEX3_HEX0 address
volatile int * SW_switch_ptr = (int *) 0x00002010; // SW slider switch address
//volatile int * KEY_ptr = (int *) 0xFF200050; // pushbutton KEY address
//int HEX_bits = 0x0000000F; // initial pattern for HEX displays

int SW_value,i,led;
int seg[10] = {0x0c0,0x0f9,0x0a4,0x0b0,0x099,0x092,0x082,0x0f8,0x080,0x090};


//volatile int delay_count; // volatile so C compiler does not remove loop
while (1)
{
SW_value = *(SW_switch_ptr)&0x00000003; // read the SW slider switch values

//==
switch(SW_value) {
      case 1 :
	     led = 0x20;
for(i=0;i<10;i++){

*(HEX_ptr) = seg[i]; // light up the red LEDs
//led = led >> 1;
delay();

}
         
         break;
      case 2 :
	  led = 0x01;//0x0000000F;
for(i=9;i>=0;i--){

*(HEX_ptr) = seg[i]; // light up the red LEDs
//led = led << 1;
delay();

}
         break;
  }
 }
}