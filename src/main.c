#include <freertos/FreeRTOS.h>
#include "comms.h"
#include "scanneri2c.h"
#include "sensors.h"
#include "system.h"

void app_main() {
  // while (1) {
  //   scanner_scan();
  //   vTaskDelay(100);
  // }

  vTaskDelay pdMS_TO_TICKS(pdMS_TO_TICKS(3000));

  SystemDevs* sysDevs = system_init();

  SensorConfig sensorsconfig;
  sensorsconfig.bmeDev = sysDevs->bme;
  sensors_init(&sensorsconfig);

  for (;;) {
    sensors_update();

    //Process data

    comms_send();
    //pump_actuate();
    system_sleep();
  }
}