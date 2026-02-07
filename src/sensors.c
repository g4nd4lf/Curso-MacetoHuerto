#include "sensors.h"
#include <esp_log.h>
#include <freertos/FreeRTOS.h>
#include "bme280.h"
#include "iBme280.h"

struct bme280_dev bmedev;

struct {
  struct bme280_dev bmedev;
} sensors;

static char* TAG = "SENSORS";

void sensors_init(SensorConfig* config) {
  sensors.bmedev.read = ibme280_i2c_read;
  sensors.bmedev.write = ibme280_i2c_write;
  sensors.bmedev.delay_us = ibme280_delay;

  sensors.bmedev.intf_ptr = &(config->bmeDev);
  sensors.bmedev.intf = BME280_I2C_INTF;
  if (bme280_init(&sensors.bmedev) == 0) {
    ESP_LOGE(TAG, "BME280 Initialized!");
  } else {
    while (1) {
      ESP_LOGE(TAG, "BME280 ERROR!");
      vTaskDelay(pdMS_TO_TICKS(1000));
    }
  }
}

void sensors_update(void) {}