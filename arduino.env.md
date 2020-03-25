# IDE environment preparation

First up, we're gonna setup our development environment. We'll be using a piece of software called an Integrated Development Environment (IDE). This software will facilitate compiling, executing and debugging code directly on our ESP32 device. 

Our IDE of choice is from Arduino and is funnily enough called the Arduino IDE. You create a Sketch file (.ino) and then author your code within. The programming language is C/C++ based as Arduino is a collection of C/C++ functions. These can be called from your code and under the covers Arduino passes it onto the C/C++ compiler, which translates it accordingly. 

Choose your destiny and click the relevant OS you're running to begin installation: [macOS](#macos) OR [Windows](#windows).

#### macOS

### Step 1:

Download the software package from https://www.arduino.cc/download_handler.php?f=/arduino-1.8.5-macosx.zip

### Step 2:
Unzip arduino-1.8.5-macosx.zip which will extract a file called Arduino.app. 

<p align="center"> 
<img src="https://raw.githubusercontent.com/aws-samples/aws-iot-workshop/master/images/ar_zip.png" width="13%">
</p>

>**Note**: A .app file which is actually a specially encoded Unix directory. This serves as an application bundle and contains all the necessary Apple-specific files which encompass a runnable application.

Double-click the .app file to start the IDE.

<p align="center"> 
<img src="https://raw.githubusercontent.com/aws-samples/aws-iot-workshop/master/images/app.png" width="13%">
</p>

### Step 3: 
Navigate to **Tools -> Board**. As you can see, all the standard Arduino boards are listed for selection such as Uno, Nano, Mega, etc. 

<p align="center"> 
<img src="https://raw.githubusercontent.com/aws-samples/aws-iot-workshop/master/images/ard_std.png" width="55%">
</p>

The ESP32 is a non-standard board thus we need to install a 3rd-party library for it work. This can be done in an automatic or manual fashion. In this case, we will opt for a semi-automatic installation by cloning a Github repository into an Arduino-specific folder.

Open a bash shell by pressing **"Command + Space"** and then typing "**terminal**". Press "Enter". 

<p align="center"> 
<img src="https://raw.githubusercontent.com/aws-samples/aws-iot-workshop/master/images/driver6.png" width="55%">
</p>

Paste the following and execute it in your terminal: 

```shell
mkdir -p ~/Documents/Arduino/hardware/espressif && \
cd ~/Documents/Arduino/hardware/espressif && \
git clone https://raw.githubusercontent.com/espressif/arduino-esp32.git esp32 && \
cd esp32 && \
git submodule update --init --recursive && \
cd tools && \
python get.py
```

The output should look as follows.

<p align="center"> 
<img src="https://raw.githubusercontent.com/aws-samples/aws-iot-workshop/master/images/lib1.png" width="65%">
</p>

Restart your IDE then navigate back to **"Tools -> Board"**, you'll now see the ESP32 board listed.

<p align="center"> 
<img src="https://raw.githubusercontent.com/aws-samples/aws-iot-workshop/master/images/esp32.png" width="55%">
</p>

### Step 4: 
Navigate to **"Sketch -> Include Library"**. You'll see that the standard Arduino libraries are available for inclusion.

<p align="center"> 
<img src="https://raw.githubusercontent.com/aws-samples/aws-iot-workshop/master/images/libraries.png" width="55%">
</p>

We'll be utilising a custom Arduino ESP32 library to connect to AWS IoT. This uses the AWS Embedded-C SDK and wraps the relevant IoT functions.

Open a bash shell by pressing **"Command + Space"** and then typing "**terminal**" into the prompt. Press "Enter".

Paste the following and execute it in your terminal: 

```shell
mkdir -p ~/Documents/Arduino/tempDir && \
cd ~/Documents/Arduino/tempDir && \
git clone https://raw.githubusercontent.com/ExploreEmbedded/Hornbill-Examples.git && \
cd Hornbill-Examples/arduino-esp32 && \
mv AWS_IOT ~/Documents/Arduino/libraries && \
rm -rf ~/Documents/Arduino/tempDir
```

The output should look as follows.

<p align="center"> 
<img src="https://raw.githubusercontent.com/aws-samples/aws-iot-workshop/master/images/lib1.png" width="65%">
</p>

Restart your IDE then go back to **"Sketch -> Include Library"**, you'll see that the AWS IOT library appears now.

<p align="center"> 
<img src="https://raw.githubusercontent.com/aws-samples/aws-iot-workshop/master/images/awsiot.png" width="55%">
</p>

Close your IDE.

### Step 5:
Before we plug your ESP32 device board in, we need to install drivers so that your OS knows how to communicate with it. 

Download this file: https://www.silabs.com/documents/public/software/Mac_OSX_VCP_Driver.zip and extract it.

<p align="center"> 
<img src="https://raw.githubusercontent.com/aws-samples/aws-iot-workshop/master/images/driver2.png" width="13%">
</p>

Double-click the extracted dmg file and follow the prompts to mount the drivers image

<p align="center"> 
<img src="https://raw.githubusercontent.com/aws-samples/aws-iot-workshop/master/images/driver2.1.png" width="55%">
</p>

Once the image is mounted, double-click the .pkg file.

<p align="center"> 
<img src="https://raw.githubusercontent.com/aws-samples/aws-iot-workshop/master/images/driver3.png" width="55%">
</p>

Click "Continue" and follow the rest of the prompts to install the drivers.

<p align="center"> 
<img src="https://raw.githubusercontent.com/aws-samples/aws-iot-workshop/master/images/driver4.png" width="55%">
</p>

Once the drivers have been installed, open a bash shell by pressing **"Command + Space"** and then typing "**terminal**". Press "Enter". 

<p align="center"> 
<img src="https://raw.githubusercontent.com/aws-samples/aws-iot-workshop/master/images/driver6.png" width="55%">
</p>

Plug your ESP32 board into a USB port and then type **"ls /dev/tty.*"**. Press "Enter".

<p align="center"> 
<img src="https://raw.githubusercontent.com/aws-samples/aws-iot-workshop/master/images/driver5.png" width="65%">
</p>

As you can see, the ESP32 device is now configured and picked up by your OS as **"/dev/tty.SLAB_USBtoUART"**.

>**Troubleshooting:** If you cannot see your device please follow the steps under this link - https://raw.githubusercontent.com/espressif/arduino-esp32/issues/1084#issuecomment-425542458  

### Step 6:
Open up your Arduino IDE and navigate to **"Tools"**. Click **"Board"** and select **"ESP32 Dev Module"**.  

Ensure the settings are as follows:

Board: **"ESP32 Dev Module"**
Flash Mode: **"QIO"**
Flash Frequency: **"80MHz"**
Flash Size: **"4MB (32MB)"**
Upload Speed: **"921600"**
Core Debug Level: **"None"**

<p align="center"> 
<img src="https://raw.githubusercontent.com/aws-samples/aws-iot-workshop/master/images/esp32 board info.png" width="35%">
</p>

For Port, select the one related to the previous step - **"SLAB_USBtoUART"**

<p align="center"> 
<img src="https://raw.githubusercontent.com/aws-samples/aws-iot-workshop/master/images/board2.png" width="55%">
</p>

Lastly, we'll utilise the built-in Serial Monitor to view/debug output of print statements such as **Serial.printf()**.

Navigate to **"Tools -> Serial Monitor"**

<p align="center"> 
<img src="https://raw.githubusercontent.com/aws-samples/aws-iot-workshop/master/images/serial0.png" width="55%">
</p>

Change the baud rate to **115200**

>**Note:** There is no notification once you change the rate so proceed accordingly.

<p align="center"> 
<img src="https://raw.githubusercontent.com/aws-samples/aws-iot-workshop/master/images/serial.png" width="55%">
</p>

You're now ready to start using your ESP32 device!

#### Windows

### Step 1:

Download and install Arduino from https://www.arduino.cc/download_handler.php?f=/arduino-1.8.5-windows.exe  

Once installation is complete, start the IDE.

>**Note:** The installation path for Sketches should default to C:\Users\username\Documents\Arduino where  username is the one you use to log into your PC

### Step 2: 
Navigate to **"Tools -> Board"**. As you can see, all the standard Arduino boards are listed for selection such as Uno, Nano, Mega, etc. 

<p align="center"> 
<img src="https://raw.githubusercontent.com/aws-samples/aws-iot-workshop/master/images/win2.png" width="55%">
</p>

The ESP32 is a non-standard board and thus we need to install a 3rd-party library for it work. This can be done in an automatic or manual fashion. In this case, we will opt for a semi-automatic installation by cloning a Github repository into an Arduino-specific folder.

Since Windows doesn't come with Git, proceed with installing it from this url: https://git-scm.com/download/win

>**Note:** Use the default installation options

Once installation is complete, click the Start menu and open "Git CMD".

<p align="center"> 
<img src="https://raw.githubusercontent.com/aws-samples/aws-iot-workshop/master/images/win_git0.png" width="35%">
</p>

Paste the following and execute it in the window: 

```shell
C: && mkdir %userprofile%\Documents\Arduino\hardware\espressif && cd %userprofile%\Documents\Arduino\hardware\espressif && git clone https://raw.githubusercontent.com/espressif/arduino-esp32.git esp32 && cd esp32 && git submodule update --init --recursive
```

The output should look as follows.

<p align="center"> 
<img src="https://raw.githubusercontent.com/aws-samples/aws-iot-workshop/master/images/win_git1.png" width="85%">
</p>

Click the Start menu, type ""**CMD**" and press enter to open a regular Command Prompt.

Paste the following and execute it in the window: 

```shell
C: && cd %userprofile%\Documents\Arduino\hardware\espressif\esp32\tools\ && get.exe
```

The output should look as follows.

<p align="center"> 
<img src="https://raw.githubusercontent.com/aws-samples/aws-iot-workshop/master/images/win_git3.png" width="65%">
</p>

Restart your IDE then navigate back to **"Tools -> Board"**, you'll now see the ESP32 board listed.

<p align="center"> 
<img src="https://raw.githubusercontent.com/aws-samples/aws-iot-workshop/master/images/win3.png" width="55%">
</p>

### Step 3: 
Navigate to **"Sketch -> Include Library"**. You'll see that the standard Arduino libraries are available for inclusion.

<p align="center"> 
<img src="https://raw.githubusercontent.com/aws-samples/aws-iot-workshop/master/images/win4.png" width="55%">
</p>

We'll be utilising a custom Arduino ESP32 library to connect to AWS IoT. This library itself makes use of the AWS Embedded-C SDK and wraps the IoT functions.

Click the Start menu and open "Git CMD".

<p align="center"> 
<img src="https://raw.githubusercontent.com/aws-samples/aws-iot-workshop/master/images/win_git00.png" width="45%">
</p>

Paste the following and execute it in the Git CMD window: 

```shell
C: && mkdir %userprofile%\Documents\Arduino\tempDir && cd %userprofile%\Documents\Arduino\tempDir && git clone https://raw.githubusercontent.com/ExploreEmbedded/Hornbill-Examples.git && cd Hornbill-Examples\arduino-esp32 && move AWS_IOT %userprofile%\Documents\Arduino\libraries && cd \ && rmdir /s /q %userprofile%\Documents\Arduino\tempDir
```

The output should look as follows.

<p align="center"> 
<img src="https://raw.githubusercontent.com/aws-samples/aws-iot-workshop/master/images/win_git2.png" width="85%">
</p>

Restart your IDE then go back to **"Sketch -> Include Library"**, you'll see that the AWS IOT library appears now.

<p align="center"> 
<img src="https://raw.githubusercontent.com/aws-samples/aws-iot-workshop/master/images/win5.png" width="45%">
</p>

Close your IDE.

### Step 4:
For Windows to recognise the ESP32 device we need to install applicable drivers. 

Download and install the drivers from this location: https://www.silabs.com/documents/public/software/CP210x_Universal_Windows_Driver.zip

>**Note:** The installation file is usually named CP210xVCPInstaller_x64.exe

Once you've completed the driver installation, plug your ESP32 into a USB port.

### Step 5:
Open up your Arduino IDE and navigate to **"Tools"**. Click **"Board"** and select **"ESP32 Dev Module"**.  

Ensure the settings are as follows:

Board: **"ESP32 Dev Module"**
Flash Mode: **"QIO"**
Flash Frequency: **"80MHz"**
Flash Size: **"4MB (32MB)"**
Upload Speed: **"921600"**
Core Debug Level: **"None"**

<p align="center"> 
<img src="https://raw.githubusercontent.com/aws-samples/aws-iot-workshop/master/images/port0.png" width="35%">
</p>

Click the Start menu, type "**Device Manager**" and press Enter.

Scroll down to Ports and expand the dropdown. Make a note of the COM port associated with Silicon labs.

<p align="center"> 
<img src="https://raw.githubusercontent.com/aws-samples/aws-iot-workshop/master/images/win_git4.png" width="55%">
</p>

In your Arduino IDE, select the matching COM Port.

<p align="center"> 
<img src="https://raw.githubusercontent.com/aws-samples/aws-iot-workshop/master/images/port1.png" width="35%">
</p>

Lastly, we'll utilise the built-in Serial Monitor to view/debug output of print statements such as **Serial.printf()**.

Navigate to **"Tools -> Serial Monitor"**

<p align="center"> 
<img src="https://raw.githubusercontent.com/aws-samples/aws-iot-workshop/master/images/win8.png" width="35%">
</p>

Change the baud rate to **115200**.

>**Note:** There is no notification once you change the rate so proceed accordingly.

<p align="center"> 
<img src="https://raw.githubusercontent.com/aws-samples/aws-iot-workshop/master/images/win9.png" width="55%">
</p>

You're now ready to start using your ESP32 device!

### What did we learn?

- How to configure your IDE on macOS or Windows
- How to install 3rd party libraries into your IDE
- How to configure your ESP32 in your IDE
- How to install device drivers for your ESP32
