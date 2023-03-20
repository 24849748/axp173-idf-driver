#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sdkconfig.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "freertos/queue.h"

#include "i2c_mid.h"
#include "esp_log.h"
#include "axp173.h"


#define TAG "main"


#if 0
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
#endif

void app_main(void) {   
    //需要先初始化i2c总线
    g_i2c_init();

    axp_init();
    
    float vbus, bat, charge_current, discharge_current, temp, ts;

    while(1){
        axp_read_adc_data(DATA_VBUS_VOLT, &vbus);
        axp_read_adc_data(DATA_BAT_VOLT, &bat);
        axp_read_adc_data(DATA_BAT_CHARGE_CURRENT, &charge_current);
        axp_read_adc_data(DATA_BAT_DISCHARGE_CURRENT, &discharge_current);
        axp_read_adc_data(DATA_INTEL_TEMP, &temp);
        axp_read_adc_data(DATA_TS_ADC, &ts);
        ESP_LOGI(TAG, "VBUS volt: %.2f | BAT volt: %.2f | Charge_current: %.2f | Discharge_current: %.2f | temp: %.2f | ts: %.2f", vbus, bat, charge_current, discharge_current, temp, ts);

        // axp_read_columb_data(&columb);
        // ESP_LOGI(TAG, "Columb %.5f", columb);

        vTaskDelay(500/portTICK_PERIOD_MS);
    }
}

/**
 * @todo
 *      - 温度ADC有问题
 * 
 */
*/

/* 
idf.py -p /dev/cu.usbserial-1420 flash monitor
*/