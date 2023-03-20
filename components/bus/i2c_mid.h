#ifndef _I2C_MID_H_
#define _I2C_MID_H_

#include "i2c_bus.h"

/* custom define */
#define I2C_PIN_SCL     (gpio_num_t)47
#define I2C_PIN_SDA     (gpio_num_t)48
#define I2C_PORT        I2C_NUM_0
#define I2C_SPEED_HZ    200000
#define I2C_PULLUP_SCL  0
#define I2C_PULLUP_SDA  0


#define AXP_PIN_IRQ     (gpio_num_t)39
#define AXP_I2C_ADDR    (0x34)



esp_err_t g_i2c_init();

/* Provide API for axp192.c */
esp_err_t axp_read_byte(uint8_t reg, uint8_t *data);
esp_err_t axp_read_bytes(uint8_t reg, uint8_t *data, size_t len);
esp_err_t axp_write_byte(uint8_t reg, const uint8_t data);


#endif