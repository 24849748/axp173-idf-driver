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

//读取电池信息
void axp173_test1(void){
    float bat;
    axp173_bat_info_t bat_info;

    axp173_enable_adc(axp173, ADC_ENABLE_BIT_BAT_VOLT, 1);
    while(1){
        axp173_get_bat_volt(axp173, &bat);
        axp173_get_bat_status(axp173, &bat_info);
        vTaskDelay(500/portTICK_PERIOD_MS);
    }
}

//设置电压 通道控制
void axp173_test2(void){

    axp173_power_output_ctrl(axp173, OUTPUT_SW_LDO2, 1);
    axp173_power_output_ctrl(axp173, OUTPUT_SW_LDO3, 1);

    axp173_set_LDO2_volt(axp173, 2.0);
    axp173_set_LDO3_volt(axp173, 3.0);

    axp173_delete(&axp173);
}


void axp173_test3(void){
    float bat_volt;
    axp173_enable_adc(axp173, ADC_ENABLE_BIT_BAT_VOLT, 1);
    axp173_get_bat_volt(axp173, &bat_volt);
}


void app_main(void) {   

    //需要先初始化i2c总线
    i2c_bus_init(AXP173_I2C_PORT);

    axp173 = axp173_create(AXP173_I2C_PORT, AXP173_I2C_ADDR);
    axp173_test1();
    // axp173_test2();
    // axp173_test3();
    while(1){
        vTaskDelay(500/portTICK_PERIOD_MS);
    }
    axp173_delete(&axp173);
}


/* 
.\..\..\..\..\esp-idf\export.ps1

. C:\Users\bosco\esp32\esp-idf\export.ps1
*/