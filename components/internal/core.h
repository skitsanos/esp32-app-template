#include <stdint.h>

void task_read_internal_sensors(void *ignore);

void task_read_free_mem(void *ignore);

void esp_deviceMAC(char **mac);

float esp_deviceTemperature();

uint32_t esp_deviceHall();

uint32_t esp_deviceFreeMem();