#include "comms.h"
#include "sensors.h"
#include "system.h"

void app_main() {
  system_init();
  sensors_init();

  for (;;) {
    sensors_update();

    //Process data

    comms_send();
    //pump_actuate();
    system_sleep();
  }
}