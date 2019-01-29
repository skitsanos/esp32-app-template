#include <stdio.h>
#include <console_colors.h>
#include <esp_log.h>
#include <core.h>
#include <esp_err.h>
#include <esp_event.h>
#include <nvs_flash.h>
#include <wifi_services.h>
#include <freertos/event_groups.h>
#include "app_config.h"
#include "app.h"

static uint32_t stats_heap_on_boot = 0;

static esp_err_t app_create_event_groups()
{
    xCoreEventGroup = xEventGroupCreate();
    xWifiEventGroup = xEventGroupCreate();

    return ESP_OK;
}

void app_main()
{
    console_set_color(CONSOLE_COLORS_RESET);

    printf("\033[46;1m ╔═══════════════════════════════════╗\033[0m\n");
    printf("\033[46;1m ║             hello world           ║\033[0m\n");
    printf("\033[46;1m ╚═══════════════════════════════════╝\033[0m\n");

    char *mac;
    esp_deviceMAC(&mac);

    ESP_LOGI(TAG, "Device MAC: %s", mac);
    free(mac);

    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND)
    {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }

    ESP_ERROR_CHECK(ret);

    stats_heap_on_boot = esp_deviceFreeMem();

    ESP_ERROR_CHECK(app_create_event_groups());

    wifi_init_apsta("Skitsanos", "chagsameah");
}