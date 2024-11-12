typedef struct
{
  long double pitch;
  long double roll;
  long double throttle;
} Controller;

void adc_init(void);
void read_adc(uint32_t *);
void get_controller_inputs(Controller *);
void voltage_to_controller(volatile uint32_t*, Controller *);


