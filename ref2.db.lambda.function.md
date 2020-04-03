# 创建IoT报文处理函数
本节内容我们创建一个AWS Lambda函数用来接收AWS IoT Core的规则转发的物联网报文,并将报文解析后,写入到MySQL数据库的库表当中。<br>

## 1. 创建AWS Lambda函数
登录AWS控制台，选择Lambda服务，进入Lambda控制台界面。选择***函数***菜单，打开函数列表，点击***创建函数***按钮，创建一个新的Lambda函数。<br>
<p align="center"> 
<img src="./pics/ref2/01.png" width="60%">
</p>

在打开的***创建函数***界面当中，需要配置如下信息：<br>
选择***从头开始创作***<br>
设置***函数名称***，为Lambda函数设置一个名字<br>
设置***运行时***，这里我选择Node.js 10.x，通过Node.js代码来进行数据的处理<br>
设置***执行角色***，该角色为执行Lambda函数的角色，用户也可以选择创建新的。这里我们选择***使用已有角色***，在下拉列表中选择lambda_basic_execution。
<p align="center"> 
<img src="./pics/ref2/02.png" width="60%">
</p>
<p align="center"> 
<img src="./pics/ref2/03.png" width="60%">
</p>

设置完成之后，点击***创建函数***进行Lambda函数的创建。
