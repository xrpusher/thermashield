#pragma once

#include "dht.h"
#include "dht_params.h"

#include "bmx280.h"

dht_t dht11;
dht_params_t dht;

bmx280_t bme280;
bmx280_params_t bme;

bmx280_t bmp280;
bmx280_params_t bmp;

int16_t temp_dht11;
int16_t hum_dht11;

int16_t temp_bme280;
uint16_t hum_bme280;
int32_t prs_bme280;

int16_t temp_bmp280;
int32_t prs_bmp280;

float sensor_temp;

void dht11_init (void);
void dht11_data (void);
void bme280_init (void);
void bme280_data (void);
void bmp280_init (void);
void bmp280_data (void);

void dht11_init (void) {

    dht.pin = GPIO_PIN(0, 7);
    dht.in_mode = DHT_PARAM_PULL;
    
    if (dht_init(&dht11, &dht) == DHT_OK) {
        printf("DHT11 sensor connected\n");
    }
    else {
        printf("Failed to connect to DHT11 sensor\n");
    }
}

void dht11_data (void) {
        
    if (dht_read(&dht11, &temp_dht11, &hum_dht11) != DHT_OK) {
        printf("Error reading values on DHT11\n");
    }
        
    sensor_temp = (float)temp_dht11 / 10;

    printf("Temperature DHT11: %d.%d C\n", (temp_dht11 / 10), (temp_dht11 % 10));
    printf("Humidity DHT11: %d %%\n\n", (hum_dht11/10));
}

void bme280_init (void) {
    bme.i2c_dev = I2C_DEV(0);
    bme.i2c_addr = 0x77;
    bme.t_sb = BMX280_SB_0_5;
    bme.filter = BMX280_FILTER_OFF;
    bme.run_mode = BMX280_MODE_FORCED;
    bme.temp_oversample = BMX280_OSRS_X1;
    bme.press_oversample = BMX280_OSRS_X1;
    bme.humid_oversample = BMX280_OSRS_X1;

    if (bmx280_init(&bme280, &bme) == BMX280_OK) {
        printf("BME280 sensor connected\n");
    }
    else {
        printf("Failed to connect to BME280 sensor\n");
    }
}

void bme280_data (void) {       

    temp_bme280 = bmx280_read_temperature(&bme280);
    //hum_bme280 = bme280_read_humidity(&bme280);
    prs_bme280 = bmx280_read_pressure(&bme280);
    sensor_temp = (float)temp_bme280 / 100;

    printf("Temperature BME280: %d.%d C\n", temp_bme280 / 100, temp_bme280 % 100 );
    printf("Humidity BME280: %d %%\n", (hum_bme280/100));
    printf("Pressure BME280: %d mBar\n\n", (prs_bme280/100));
}


void bmp280_init (void) {
    bmp.i2c_dev = I2C_DEV(0);
    bmp.i2c_addr = 0x76;
    bmp.t_sb = BMX280_SB_0_5;
    bmp.filter = BMX280_FILTER_OFF;
    bmp.run_mode = BMX280_MODE_FORCED;
    bmp.temp_oversample = BMX280_OSRS_X1;
    bmp.press_oversample = BMX280_OSRS_X1;

    if (bmx280_init(&bmp280, &bmp) == BMX280_OK) {
        printf("BMP280 sensor connected\n");
    }
    else {
        printf("Failed to connect to BMP280 sensor\n");
    }
}

void bmp280_data (void) {       

    temp_bmp280 = bmx280_read_temperature(&bmp280);
    prs_bmp280 = bmx280_read_pressure(&bmp280);
    sensor_temp = (float)temp_bmp280 / 100;

    printf("Temperature BMP280: %d.%d C\n", temp_bmp280 / 100, temp_bmp280 % 100 );
    printf("Pressure BMP280: %d mBar\n\n", (prs_bmp280/100));
}