// This include is for the AWS IOT library that we installed
#include <AWS_IOT.h>
// This include is for Wifi functionality
#include <WiFi.h>
#include <time.h>

// Declare an instance of the AWS IOT library
AWS_IOT hornbill;

// Wifi名字与密码
char WIFI_SSID[]="CMCC-nababy";
char WIFI_PASSWORD[]="peng7364ren736";

// AWS IoT的Endpoint，物品名称及所发送MQTT消息的Topic名称
char HOST_ADDRESS[]="a1ujsez49ccj6j-ats.iot.cn-northwest-1.amazonaws.com.cn";
char CLIENT_ID[]= "SHIIoTThing";
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
  // 建立AWS IoT连接
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

  // 生成JSON报文
  sprintf(payload,"{\"state\": {\"reported\": {\"devid\":\" %s \",\"timestamp\":\" %d \",\"temperature\":\" %f \"}}}",CLIENT_ID, ii, tempC);
  
  Serial.println(payload);
  // 向AWS IoT发送报文
  if(hornbill.publish(TOPIC_NAME,payload) == 0) {
    Serial.println("Message published successfully");
  }
  else {
    Serial.println("Message was not published");
  }
  // 每隔5秒执行一次
  delay(5000);  
}
