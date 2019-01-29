# esp32-app-template

ESP-IDF Template application for building apps running on ESP32 modules

### WIFI

When it comes to WIFI, application preconfigured to run in station and dual modes, use _wifi_init_apsta_ to run dual-mode and _wifi_init_sta_ to run in station mode.

In order to set your device as access point, in _app_config.h_ modify the access point SSID (_ap_ssid_) and password (_ap_password_):

```
#define ap_ssid "ESP32-node"
#define ap_password "password12345678"
```