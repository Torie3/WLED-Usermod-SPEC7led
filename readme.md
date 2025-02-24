<p align="center">
  <img src="/images/wled_logo_akemi.png">
  <a href="https://github.com/Aircoookie/WLED/releases"><img src="https://img.shields.io/github/release/Aircoookie/WLED.svg?style=flat-square"></a>
  <a href="https://raw.githubusercontent.com/Aircoookie/WLED/master/LICENSE"><img src="https://img.shields.io/github/license/Aircoookie/wled?color=blue&style=flat-square"></a>
  <a href="https://wled.discourse.group"><img src="https://img.shields.io/discourse/topics?colorB=blue&label=forum&server=https%3A%2F%2Fwled.discourse.group%2F&style=flat-square"></a>
  <a href="https://discord.gg/QAh7wJHrRM"><img src="https://img.shields.io/discord/473448917040758787.svg?colorB=blue&label=discord&style=flat-square"></a>
  <a href="https://kno.wled.ge"><img src="https://img.shields.io/badge/quick_start-wiki-blue.svg?style=flat-square"></a>
  <a href="https://github.com/Aircoookie/WLED-App"><img src="https://img.shields.io/badge/app-wled-blue.svg?style=flat-square"></a>
  <a href="https://gitpod.io/#https://github.com/Aircoookie/WLED"><img src="https://img.shields.io/badge/Gitpod-ready--to--code-blue?style=flat-square&logo=gitpod"></a>

  </p>

# Welcome to this wled Usermod ✨

This usermod enables connection of an ESP32C3 (you can build the firmware for other boards) to a flight controller , allowing users to select specific presets with a switch on their remote. Originally developed for Spec7 quads, this mod can be applied to any project where a preset needs to be activated based on a PWM signal received on a designated pin.

## ⚙️ How It Works
**WLED** is a project that allows easy control of addressable RGB lights. Our focus is on enabling users to switch between different presets set up in the WLED app using a physical switch on the controller. This is achieved by leveraging a built-in feature in **Betaflight or Inav** that generates a PWM (Pulse Width Modulation) signal on a specific pin—typically used for controlling servos. While we could have read data directly from the receiver, we opted for the PWM approach for several reasons outlined below.

### Advantages and Disadvantages of Using PWM
***Advantages:***
- **Compatible with Any Remote Protocol Supported by Betaflight:** Allows flexibility across various remote protocols.
- **Minimal Data Processing from Receiver:** Only the PWM signal is processed, improving the program’s speed and efficiency.
- **Standalone Use with PWM Receivers:** Can operate as a standalone unit with just the controller and LEDs, without a flight controller (FC).
- **Protocol Agnostic:** No need to adapt to specific protocols, making the setup easily adaptable.
- **Avoids UART Conflicts:** WLED may interfere with LED-receiver communication, particularly when multiple UARTs are used (one for the receiver and one for LEDs), as adding a software serial port can consume significant processing power.

***Disadvantages:***
- **Requires a Flight Controller or PWM Receiver:** Cannot function as a standalone unit with just the receiver, ESP, and LEDs.
- **Single-Channel Limitation:** Multiple channels for selecting presets would require additional wiring and pins on the FC.
- **Consumes a Pin on the Flight Controller:** Typically, the LED pin is used, but additional motor pins may also be viable.
### Advantages and Disadvantages of Direct Receiver Connection
***Advantages:***
- **Access to Full Receiver Data:** Allows use of multiple channels.
- **Standalone Operation:** Can function with just the receiver, ESP, and LEDs.
- **No Flight Controller Pin Usage:** Frees up all pins on the flight controller.

***Disadvantages:***
- **Requires Soldering on Receiver Pads:** Soldering two wires onto a single receiver pad can be cumbersome.
- **Limited to One Remote Protocol:** Only one remote protocol can be used in this configuration.
- **Increased Processing Power Demand:** Requires significant processing resources, potentially impacting performance.
### Conclusion
Considering these factors, we chose the PWM option, which offers a balanced approach in terms of flexibility, performance, and ease of setup. For instructions on setting up the system, refer to the Quick Start Guide.


## 💡 Quick Start Guide
**Betaflight Setup**
1) **Enable Servo on Flight Controller**

Ensure you flash your flight controller with servo enabled.
<img src="/images/betaflight flashing screen.png" width="100%">

2) **Standard Flight Controller Setup**

Set up your flight controller as you normally would.

3) **Check Resource Pins in CLI**

Open the CLI and paste the following command to display all resources and their pin assignments:

`resource`

Find resource LED_STRIP 1 in the output and note the pin number next to it (e.g., A08).
<img src="/images/cli_led_strip_pin.png" width="50%">

4) **Reassign LED Strip Pin to Servo**

Enter the following commands in the CLI to remove the LED strip assignment from this pin and assign it to Servo 1:

```
resource LED_STRIP none
resource SERVO 1 "your noted pin number from step 4"
save
```

5) **Configure Servo Settings**

Go to the Servo tab and adjust the settings marked in the red box in the image below. Only the channel associated with the button to switch presets needs to be adjusted here. In the Receiver tab, you can check which button corresponds to which action. (We recommend using a 6-button switch on your controller; however, other setups may work, although results may vary.)
<img src="/images/servo_tab.png" width="100%">

***Note: This configuration won’t work when connected to your computer unless “live mode” is enabled.***

### Hardware Setup
1) **Connect Ground**

Connect the ground on your flight controller to the ground on the ESP. This is mandatory, as it sets a shared reference.

2) **Connect Data Pin**

Connect the LED pin on your flight controller to gpio 2 on the ESP (make sure it's not pin 2, because on some boards they aren't the same). This wire carries the data.

3) **Power the ESP and LEDs**

Power the ESP as needed, and connect the LEDs like a standard WLED setup.

***Note: The following diagram provides an example for wiring. Do not copy it exactly; please research how to power your ESP safely. We are not liable for any physical or material damage.***

<img src="/images/example_wiring_diagram.png" width="75%">

#### Custom PCB

<img src="/images/pcb_3D_model.png" width="100%">

We recently introduced a custom PCB that integrates all the necessary components to run WLED on drones. This board includes a **5V@3A buck converter**, capable of stepping down **12V-30V** to a stable **5V** supply.

At its core, the board features an **ESP32-C3**, complete with all essential supporting components for power management and Wi-Fi transmission.

To simplify wiring, we've integrated a **logic level converter**, which shifts the **ESP32-C3's 3.3V signal** to **5V**, ensuring proper operation of LED strips. 

Additionally, we've included an extra GPIO pin, which can be used for:
- Receiving an input from the flight controller
- Connecting an additional LED strip
This extra GPIO is available as both a 3.3V pad and a 5V pad (via the logic level converter), allowing seamless integration with LED strips.



### ESP Setup

This guide covers setup on Windows only. (Linux users should be able to manage on their own. Mac users: consider upgrading your hardware! Just kidding 😊)

1) **Download Firmware**

   - Navigate to `build_output/releases`, select the appropriate folder for your board, and download the `.bin` firmware file.
   - For ESP32 devices, download the bootloader file located in `.pio/build/your_board_here`.

2) **Set Up Programming Tool**

   - Follow the steps in [this guide](https://phoenixnap.com/kb/how-to-install-python-3-windows) to install Python. You may skip steps 4 and 7 as they are optional.
   - Once Python is installed, open Command Prompt (cmd) and run `pip install esptool` to install `esptool`.

3) **Connect ESP to Computer**

   - While holding the boot button on the ESP, plug it into your PC.
   - Open Device Manager and note the COM port your ESP is connected to.

4) **Upload Firmware**

   - First, install the bootloader:
     ```bash
     py -m esptool -p com(your_com_port) -b 460800 write_flash 0x0 (path_to_bootloader_file)
     ```
     **Example**:
     ```bash
     py -m esptool -p com13 -b 460800 write_flash 0x0 C:\Users\YourUser\Downloads\WLED-main\.pio\build\esp32c3dev\bootloader.bin
     ```
     - Once done, disconnect and reconnect the ESP while holding the boot button.

   - Now, upload the firmware:
     ```bash
     py -m esptool -p com(your_com_port) -b 460800 write_flash 0x10000 (path_to_firmware_file)
     ```
     **Example**:
     ```bash
     py -m esptool -p com13 -b 460800 write_flash 0x10000 C:\Users\YourUser\Downloads\WLED-main\build_output\release\WLED_0.14.4_ESP32-C3.bin
     ```
   - After completion, disconnect the ESP from your PC.

### Final Steps

Set up WLED as usual, ensuring you create six presets to avoid errors when switching. This setup is compatible with six-button switches (e.g., Radiomaster Boxer and TX16s). Future updates will include support for two- and three-position switches.

Enjoy your new LED setup on your Spec 7 quad!


*Disclaimer:*   

If you are prone to photosensitive epilepsy, we recommended you do **not** use this software.  
If you still want to try, don't use strobe, lighting or noise modes or high effect speed settings.

As per the MIT license, I assume no liability for any damage to you or any other person or equipment.  
