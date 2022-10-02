# AXP173-idf-driver

最近从b站了解到AXP173这款电源管理芯片，其特性非常适合平常DIY

**AXP173的部分特性：**

- 2路DCDC
- 4路LDO
- 12-Bit ADC
- 支持外部适配器、USB、电池三种电源输入
- 整合过压、过温、过流等保护电路
- 提供I2C接口与主机通讯

看起来就很香~

于是马上基于@Forairaaaaa大佬的开源方案复刻了一个方案

不过看网友们复刻时遇到很多坑，比如买到的芯片属于定制的等等，好在我买来的芯片似乎很正常，于是练练手写了这个ESP-IDF框架的组件

- **开发框架：ESP-IDF v4.4.2**
- **HOST主机：ESP32 PICO-D4**
- **硬件连接：I2C_SDA -> 4； I2C_SCL -> 21，外部已上拉4.7k电阻**



### 使用方法：

```c
/**
 * 1.复制components文件夹下axp173、bus两个组件到工程中
 * 2.修改头文件中相关引脚定义
 * 3.使用 i2c_bus_init() 函数初始化 I2C 总线
 * 4.使用 axp173_create() 函数创建设备句柄
 * 5.执行你的操作
 * 6.使用完成后使用 axp173_delete() 函数释放资源
 */

void app_main(void) {   
    //需要先初始化i2c总线
    i2c_bus_init(AXP173_I2C_PORT);
    axp173 = axp173_create(AXP173_I2C_PORT, AXP173_I2C_ADDR);
    //do something
    while(1){
        vTaskDelay(500/portTICK_PERIOD_MS);
    }
    axp173_delete(&axp173);
}
```

main.c文件里提供3个测试代码，读取电池状态信息、控制电源通道输出并设置电压、读取电池电压。

另外已将常用操作封装成函数API，方便调用，其他不常用的暂未实现（见下文），但可根据 Datasheet 和 axp173_read/write...() 函数自己实现。头文件里注释的宏即暂未使用的寄存器地址，部分寄存器命名规范参考 @tuupola 的代码



### Todo：

- [x] I2C读写保护
- [x] 将常用操作封装成函数，方便使用简单
- [ ] 中断通知



本人还是小菜鸡一个，如果大佬们发现程序有问题，希望能得到您宝贵的意见~



### 致谢：

ESP-IDF、X-Powers、Forairaaaaa、@tuupola等