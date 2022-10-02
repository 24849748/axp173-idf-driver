#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sdkconfig.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "freertos/queue.h"

#include "i2c_bus.h"
#include "esp_log.h"
#include "axp173.h"


#define TAG "main"

static axp173_handle_t axp173;


void axp173_test3(void){
    axp173 = axp173_create(AXP173_I2C_PORT, AXP173_I2C_ADDR);

    float bat_volt;
    axp173_enable_adc(axp173, ADC_ENABLE_BIT_BAT_VOLT, 1);
    axp173_get_bat_volt(axp173, &bat_volt);
    // axp173_set_charge_current(axp173, CHARGE_CURRENT_mA_1240);
}

/* 
void axp173_test1(void){
    i2c_bus_init(I2C_NUM_0);
    axp173_init(AXP173_I2C_PORT, AXP173_I2C_ADDR);

    float bat;
    axp173_bat_info_t bat_info;
    //setting
    // axp173_enable_adc(ADC_ENABLE_BIT_VBUS_VOLT, 1);
    axp173_enable_adc(ADC_ENABLE_BIT_BAT_VOLT, 1);
    while(1){
        // axp173_get_VBUS_volt(&bat);
        axp173_get_bat_volt(&bat);
        axp173_get_bat_status(&bat_info);
        vTaskDelay(500/portTICK_PERIOD_MS);
    }
}

//设置电压 通道控制
void axp173_test2(){
    i2c_bus_init(I2C_NUM_0);
    axp173_init(AXP173_I2C_PORT, AXP173_I2C_ADDR);

    // float bat;
    // axp173_bat_info_t bat_info;

    axp173_power_output_ctrl(OUTPUT_SW_LDO2, 1);
    axp173_power_output_ctrl(OUTPUT_SW_LDO3, 1);

    axp173_set_LDO2_volt(2.0);
    axp173_set_LDO3_volt(3.0);

    // axp173_set_LDO4_volt(1);

    //setting
    // axp173_enable_adc(ADC_ENABLE_BIT_VBUS_VOLT, 1);
    // axp173_enable_adc(ADC_ENABLE_BIT_BAT_VOLT, 1);
    while(1){
        // axp173_get_VBUS_volt(&bat);
        // axp173_get_bat_volt(&bat);
        // axp173_get_bat_status(&bat_info);
        vTaskDelay(500/portTICK_PERIOD_MS);
    }
} */

void app_main(void)
{   
    // axp173_dev_t axp173;

    i2c_bus_init(I2C_NUM_0);
    // axp173_init(AXP173_I2C_PORT, AXP173_I2C_ADDR);

    axp173_test3();

    // // float bat;
    // // axp173_bat_info_t bat_info;

    // axp173_power_output_ctrl(OUTPUT_SW_LDO2, 1);
    // axp173_power_output_ctrl(OUTPUT_SW_LDO3, 1);

    // axp173_set_LDO2_volt(2.0);
    // axp173_set_LDO3_volt(3.0);

    // // axp173_set_LDO4_volt(1);

    // //setting
    // // axp173_enable_adc(ADC_ENABLE_BIT_VBUS_VOLT, 1);
    // // axp173_enable_adc(ADC_ENABLE_BIT_BAT_VOLT, 1);
    while(1){
        // axp173_get_VBUS_volt(&bat);
        // axp173_get_bat_volt(&bat);
        // axp173_get_bat_status(&bat_info);
        vTaskDelay(500/portTICK_PERIOD_MS);
    }
}



/* 
.\..\..\..\..\esp-idf\export.ps1

. C:\Users\bosco\esp32\esp-idf\export.ps1
*/