# Lab 2: 设备连接和数据传输

## 设备开发环境准备
在本次Workshop当中，我们将使用ESP32开发板与LM35温度传感器构建的温度监测组件与AWS IoT平台进行对接需要对ESP32开发板进行编程，这里我们使用Arduino IDE编程工具通过C语言对ESP32进行开发。<br>
Arduino是一款便捷灵活、方便上手的开源电子原型平台。包含硬件（各种型号的Arduino板）和软件（Arduino IDE)。Arduino IDE基于processing IDE开发。对于初学者来说，极易掌握，同时有着足够的灵活性。Arduino语言基于wiring语言开发，是对 AVR-GCC库的二次封装，不需要太多的单片机基础、编程基础，简单学习后，你也可以快速的进行开发。<br>
对于Arduino IDE环境的安装与配置，请点击[这里](https://github.com/steelren/aws_iot_core_workshop/blob/master/arduino.env.md)。<br>

## 准备设备证书
在开发环境准备完成之后，我们就可以开始为设备编写代码了。<br>
为了能够让ESP32开发板能够在连接AWS IoT Core的时候，能够顺利通过安全认证，需要首先为开发板配置设备证书，这些证书我们在进行设备注册时候已经下载过。<br>
在Arduino IDE的AWS库文件中，找到aws_iot_certficates.c文件，写入证书的内容。该文件位于在Arduino IDE环境安装与配置中说明的***（\Documents\Arduino\libraries\AWS_IOT\src）***目录下。参考代码说明如下:<br>
```C
/**
 * @file aws_iot_certifcates.c
 * @brief File to store the AWS certificates in the form of arrays
 */

#ifdef __cplusplus
extern "C" {
#endif

// AWS CA根证书
const char aws_root_ca_pem[] = {"-----BEGIN CERTIFICATE-----\n\
MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF\n\
……
……
-----END CERTIFICATE-----\n"};

// 设备证书
const char certificate_pem_crt[] = {"-----BEGIN CERTIFICATE-----\n\
MIIDWTCCAkGgAwIBAgIUWxxS4xnnzBXoaoxwgWQ9Ij7ikKswDQYJKoZIhvcNAQEL\n\
……
……
-----END CERTIFICATE-----\n"};

// 设备私钥
const char private_pem_key[] = {"-----BEGIN RSA PRIVATE KEY-----\n\
MIIEogIBAAKCAQEA26qt4XZCtlUSIz1acsyiXHJmqCEEkXBp6YuQUeT4wIihqr2w\n\
……
……
-----END RSA PRIVATE KEY-----\n"};

#ifdef __cplusplus
}
#endif
```
所对应的每个证书的内容，从之前下载的证书文件中分别进行提取，写入到该文件当中，并保存。具体代码可参考[这里](https://github.com/steelren/aws_iot_core_workshop/blob/master/code/aws_iot_certficates.c)。<br>

## 编写设备代码
将组装好的ESP32开发板和LM35传感器通过USB连接到电脑主机，打开之前配置好的Arduino IDE，选择对应的COM接口，新建一个项目，为选择项目保存路径，并对项目进行命名，比如Esp32_LM35，会产生一个.ino文件，该文件即为Arduino的项目文件。在Arduino IDE当中使用C语言为ESP32开发板和LM35温度传感器进行编程，这里我们让ESP32开发板通过WIFI连接到对应的AWS IoT Core，并且每5秒钟读取一下安装ESP32上的LM35传感器上的温度数据，组装成json报文，发送到AWS IoT Core对应的Topic。参考代码如下:<br>
```C
// 一些必要的头文件
#include <AWS_IOT.h>
// This include is for Wifi functionality
#include <WiFi.h>
#include <time.h>

// 初始化变量，AWS IoT端点、队列，WIFI配置，LM35引脚，报文等
// Declare an instance of the AWS IOT library
AWS_IOT hornbill;

// ESP32所需要连接的Wifi名字与密码
char WIFI_SSID[]="******";
char WIFI_PASSWORD[]="******";

// ESP32所需要连接的AWS IoT的Endpoint，可在AWS IoT Core控制台的设置菜单中查看
char HOST_ADDRESS[]="******.iot.cn-northwest-1.amazonaws.com.cn";
// 物品名称，可使用之前设备注册所使用的名称
char CLIENT_ID[]= "SHIIoTThing";
// 发送MQTT消息的Topic名称，可在AWS IoT Core控制台中，选择对应的设备查看其已有的影子Topic，也可以使用自定义的Topic
char TOPIC_NAME[]= "$aws/things/SHIIoTThing/shadow/update";

// Connection status
int status = WL_IDLE_STATUS;
// Payload array to store thing shadow JSON document
char payload[512];

// 温度传感器LM35所对应的针脚
const int analogIn = A0;

// Arduino程序初始化函数
void setup()
{
  WiFi.disconnect(true);
  Serial.begin(115200);
  // 建立WIFI连接
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to Wifi network: ");
    Serial.println(WIFI_SSID);
    status = WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    delay(5000);
  }
  Serial.println("Connected to Wifi!");
  // 建立AWS IoT连接，该连接会在底层调用之前配置好的证书
  if(hornbill.connect(HOST_ADDRESS,CLIENT_ID)== 0) {
    Serial.println("Connected to AWS, bru");
    delay(1000);
  }
  else {
    Serial.println("AWS connection failed, Check the HOST Address");
    while(1);
  }
}

// 循环执行函数
void loop()
{   
  int RawValue= 0;
  double Voltage = 0;
  double tempC = 0;
  double tempF = 0;
  // 读取LM35数据
  RawValue = analogRead(analogIn);
  Voltage = (RawValue / 2048.0) * 3300; // 5000 to get millivots.
  // 摄氏度
  tempC = Voltage * 0.1;
  // 华氏度
  tempF = (tempC * 1.8) + 32; // conver to F

  // 获得当前时间
  time_t t = time(NULL);
  int ii = time(&t);

  // 生成JSON报文，包括设备名称，消息发送的时间，所采集的温度
  sprintf(payload,"{\"state\": {\"reported\": {\"devid\":\" %s \",\"timestamp\":\" %d \",\"temperature\":\" %f \"}}}",CLIENT_ID, ii, tempC);
  
  Serial.println(payload);
  // 向AWS IoT Core发送报文
  if(hornbill.publish(TOPIC_NAME,payload) == 0) {
    Serial.println("Message published successfully");
  }
  else {
    Serial.println("Message was not published");
  }
  // 每隔5秒执行一次
  delay(5000);  
}
```
具体代码可参考[这里](https://github.com/steelren/aws_iot_core_workshop/blob/master/code/Esp32_LM35.ino)。<br>

## 代码写入开发板
代码保存之后，在开发板连接到电脑的情况下，点击Arduino IDE工具栏上的***Upload***按钮。<br>
<p align="center"> 
<img src="./pics/lab2/arduinoupload.png">
</p>
在提示写入成功之后，代码就自动开始在ESP32开发板中开始运行了。<br>
在菜单中选择Tools-Serial Monitor，就可以打开串口监控窗口，并且设定串口监视器的Baud Rate与之前设置的Upload Speed相同，比如115200，就可以看到开发板中程序的运行情况了。<br>
<p align="center"> 
<img src="./pics/lab2/serialmonitor.png">
</p>

## 数据传输测试
