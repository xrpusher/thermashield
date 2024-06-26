#include <stdio.h>

#include "board.h"
#include "periph/gpio.h"
#include "periph/i2c.h"
#include "periph/wdt.h"
#include "periph/pwm.h"
#include "xtimer.h"

#include "network.h"
#include "sensors.h"

#ifndef LED_ALR_ESP32 
#define LED_ALR_ESP32 GPIO_PIN(0, 17)
#endif

#define TEMP_MAX 20 // Celsius

extern struct tcp_pcb *testpcb;
extern err_t error;

extern int16_t temp_bme280;
extern int16_t temp_bmp280;
extern float sensor_temp;

static char temp_sensor[THREAD_STACKSIZE_DEFAULT];

// int16_t temp_max = 20; // Celsius
pwm_t pwm;

void alarm_temp (uint8_t alarm) {
    if (!alarm) {
        gpio_clear(LED_ALR_ESP32);
        pwm_set(pwm, 1, 0); // GPIO_PIN(0, 2)
    } else {
        gpio_set(LED_ALR_ESP32);
        pwm_set(pwm, 1, 1024); // GPIO_PIN(0, 2)
    }
}

void *temp_thread(void *arg) {
    (void) arg;
    while (1) {
        bmp280_data();
        if (sensor_temp <= TEMP_MAX) {
            tcp_setup();
            alarm_temp(0);
            xtimer_sleep(60);
        } else {
            tcp_setup();
            alarm_temp(1);
            xtimer_sleep(10);
        }
    }
    return NULL;

}

int main(void) {

    xtimer_sleep(1);
    printf("MAIN START\n");
    bmp280_init();
    printf("Initialize TCP connection...\n");
    
    int pwm_channel = pwm_channels(pwm);	
    int pwm_status = pwm_init(pwm, PWM_LEFT, 50, 1024); //65535
    printf("PWN Channels = %d\n", pwm_channel);
    printf("PWM is initialised. PWN Frequence = %d\n", pwm_status);

    gpio_init(LED_ALR_ESP32, GPIO_OUT);
    
    xtimer_sleep(12);
    
    thread_create(
        temp_sensor, 
        sizeof(temp_sensor),
        THREAD_PRIORITY_MAIN+1,
        THREAD_CREATE_STACKTEST,
        temp_thread,
        NULL,
        "ThermaShield"
    );

    while(1) {
        xtimer_sleep(1000);
    }

    return 0;
}
