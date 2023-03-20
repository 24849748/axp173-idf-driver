# axp173-idf-driver



* 开发框架：ESP-IDF v4.4.4
* HOST主机：exS3
* 硬件连接：I2C_SDA->48; I2C_SCL->47; PMU_IRQ->39; 外部已上拉4.7k电阻



**AXP173的部分特性：**

1. 2路DCDC & 4路LDO
2. 12-bit ADC
3. ACIN & VBUS &BAT 三种电源输入
4. 使用 I2C 与主机通讯
5. 过压 & 过温 & 过流等保护电路



### 使用方法：

* 根据硬件情况修改 `i2c_mid.h`文件里相关定义

* 先初始化I2C总线`g_i2c_init()`，再初始化axp173设备`axp_init()`

* 一些操作

  ```c
  // 单个电源输出控制
  axp_en_ctrl(EN_OP_DC1, true);
  
  // 多个电源输出控制
  axp_write_byte(0x12, axp_op_generate_byte(true, false, ...));
  
  // 设置电压
  axp_set_volt(DC1_SET_VOLT, 3300);
  
  // 读取常用设备信息
  axp_info_t info;
  axp_read_info(&info);
  
  // ...
  ```



### 更新说明：

*> -* *[**2023.03.19**]* *重构仓库：更新硬件平台(exS3)，IDE框架，使用iot-solution的i2c bus组件*



### Todo：

- [x] I2C读写保护
- [x] 将常用操作封装成函数，方便使用简单
- [ ] 库仑计，实时功耗、剩余电量、剩余使用时间、充满时间等电源信息
- [ ] 中断通知



### 致谢

Expressif、X-Powers、@Forairaaaaa、@tuupola等

