#include <stdio.h>

#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

char ssid[] = "wifi-name";
char password[] = "Password";

int main() {
  stdio_init_all();


  if (cyw43_arch_init_with_country(CYW43_COUNTRY_LITHUANIA)) {
    printf("Failed to initialise\n");
    return 1;
  }
  printf("Initialised\n");
  
  cyw43_arch_enable_sta_mode();

  if (cyw43_arch_wifi_connect_timeout_ms(ssid, password, CYW43_AUTH_WPA2_AES_PSK, 10000)) {
    printf("Failed to connect\n");
    return 1;
  }
  printf("Connected\n");
}