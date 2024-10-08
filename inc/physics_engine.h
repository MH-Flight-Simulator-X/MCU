
typedef struct
{
  int16_t x;
  int16_t y;
  int16_t z;

  int16_t dx;
  int16_t dy;
  int16_t dz;

  int16_t hp;

} object_t;

typedef struct
{
  int16_t amplitude;
  int16_t x;
  int16_t y;
  int16_t z;
} force_t;

void physics_engine_init(void);
void run(void);
