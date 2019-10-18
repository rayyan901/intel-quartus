int main(void)
{
/* Declare volatile pointers to I/O registers (volatile means that the locations will not be cached,
* even in registers) */
volatile int * LED_ptr = (int *) 0x00002000; // red LED address
//volatile int * HEX3_HEX0_ptr = (int *) 0xFF200020; // HEX3_HEX0 address
volatile int * SW_switch_ptr = (int *) 0x00002010; // SW slider switch address
//volatile int * KEY_ptr = (int *) 0xFF200050; // pushbutton KEY address
int HEX_bits = 0x0000000F; // initial pattern for HEX displays
int SW_value,i;
volatile int delay_count; // volatile so C compiler does not remove loop
while (1)
{
//SW_value = *(SW_switch_ptr); // read the SW slider switch values
SW_value = 1;//0x0000000F;
for(i=0;i<8;i++){


*(LED_ptr) = SW_value; // light up the red LEDs
SW_value = SW_value << 1;

for (delay_count = 100000; delay_count != 0;delay_count--); // delay loop
}
}
}