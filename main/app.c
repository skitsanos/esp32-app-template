#include <stdio.h>
#include <console_colors.h>
#include <esp_log.h>
#include <core.h>
#include "app_config.h"

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
}