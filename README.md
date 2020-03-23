# 软硬兼施，实战构建基于AWS IoT的物联网解决方案
## 硬件准备
在这个场景当中，我们将使用到如下的硬件：<br>
*	ESP32开发板：ESP-WROOM-32(ESP32)是乐鑫最新发布的新一代WiFi & 蓝牙双模双核无线通信芯片。芯片集成蓝牙4.2和WiFi HT40技术为一身，拥有高性能Tensilica LX6 双核处理器，支持超低功耗待机，广泛应用于移动设备、可穿戴电子产品和物联网应用<br>
![](https://github.com/steelren/aws_iot_core_workshop/blob/master/pics/esp32.jpg) <br>
*	LM35温度传感器：LM35 是由National Semiconductor 所生产的温度传感器，其输出电压为摄氏温标。LM35是一种得到广泛使用的温度传感器。由于它采用内部补偿，所以输出可以从0℃开始。LM35有多种不同封装型式。在常温下，LM35 不需要额外的校准处理即可达到 ±1/4℃的准确率。<br>
![](https://github.com/steelren/aws_iot_core_workshop/blob/master/pics/lm35.jpg) <br>
上述硬件通过简单的连接即可组成一个能够通过WIFI网络发送温度数据的温度监测组件。LM35的Vcc，Vout和GND针脚分别对接ESP32的3v3，VP和GND针脚(千万别接错了，否则LM35可烫手了，还有糊味儿☹)。<br>
![](https://github.com/steelren/aws_iot_core_workshop/blob/master/pics/composite.jpg) <br>
这样一个组件就可以通过WIFI与AWS IoT Core服务进行连接，实现对温度数据的采集和处理。<br>
## AWS相关服务
本方案使用到以下Amazon Web Service（AWS）服务：<br>
* AWS IoT Core：AWS IoT服务，用于对接我们的温度监测组件
*	AWS Lambda：AWS无服务器函数服务，用于处理IoT服务接收到的数据
*	Amazon Relational Database Service (Amazon RDS) ：AWS托管的关系型数据库，这里我们使用的是MySQL，用于存储接收到的温度数据
*	Amazon Simple Notification Service (Amazon SNS) ：AWS消息通知服务，在温度异常时，用于发送邮件通知
*	Amazon Simple Storage Service (Amazon S3) ：对象存储服务，低成本存储物联网数据
实现温度监控组件与AWS IoT Core服务的对接，整个Demo场景的架构如下图所示。<br>
![](https://github.com/steelren/aws_iot_core_workshop/blob/master/pics/DemoArchitecture.png) <br>
依据上述架构，设定的业务场景如下：<br>
* 温度监测组件每5秒钟采集一次数据，包括设备号、时间和温度值，数据通过WIFI传输到AWS IoT Core云服务
* AWS IoT Core云服务接收到温度监测组件传输的数据，做如下三种处理：
* 数据存储到对象存储Amazon S3，一方面利用低成本的存储空间，另一方面为将来的数据湖大数据分析做准备
* 数据通过AWS Lambda函数进行解析，存入MySQL数据库表，以便于用户的应用直接去访问关系型数据库，对物联网数据进行处理
* 对数据进行实时监测，对于温度超过阈值(比如40℃)，发送邮件提醒相关人员
## 方案构建
构建基于AWS IoT的物联网解决方案包含如下几个步骤:<br>
Lab 1: 设备注册<br>
Lab 2: 设备链接与数据传输<br>
Lab 3: 数据存储与数据处理<br>
Lab 4: 邮件告警<br>
以下将进行详细说明：<br>
### Lab 1: 设备注册

### Lab 2: 设备链接与数据传输
### Lab 3: 数据存储与数据处理
### Lab 4: 邮件告警
