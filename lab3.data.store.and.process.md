# Lab3: 数据存储与数据处理
物联网数据采集之后，所面临第一个问题就是如何存储这些数据，再一个就是怎样使用这些数据。AWS IoT Core提供了非常便利的手段帮助用户对数据进行存储和处理。在本文所介绍的应用场景中，我们主要通过AWS IoT Core所提供的规则(Rule)与操作(Action)来触发数据存储和处理操作。<br>
AWS IoT Core规则由 SQL SELECT 语句、主题筛选条件和规则操作组成。设备通过将消息发布到 MQTT 主题来向 AWS IoT Core发送信息。利用 SQL SELECT 语句，您可以从传入的 MQTT 消息提取数据。AWS IoT Core规则的主题筛选条件用于指定一个或多个 MQTT 主题。当主题收到与主题筛选条件匹配的 MQTT 消息时，将触发规则。借助规则操作，您可以获取从 MQTT 消息提取的信息并将其发送到其他 AWS 服务。<br>
AWS IoT Core规则操作用于指定规则触发后应执行的操作。用户可以定义一些操作以便将数据写入 Amazon DynamoDB 数据库或 Amazon Kinesis 流，或者调用 Lambda 函数等。<br>
在该业务场景中，我们使用AWS IoT Core规则触发两个操作，我们直接对AWS IoT Core所接收到的所有温度监测数据进行处理。<br>

## 1. 创建规则

