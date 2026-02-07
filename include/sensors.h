#ifndef SENSORS_C__
#define SENSORS_C__

#include <driver/i2c_master.h>

void sensors_update(void);

typedef struct {
  i2c_master_dev_handle_t bmeDev;
} SensorConfig;

void sensors_init(SensorConfig* config);

#endif  //SENSORS_C__