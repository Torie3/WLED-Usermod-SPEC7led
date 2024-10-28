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

This usermod enables connection of an ESP32 (ESP32 Devboard or ESP32-C3) to a flight controller, allowing users to select specific presets with a switch on their remote. Originally developed for Spec7 quads, this mod can be applied to any project where a preset needs to be activated based on a PWM signal received on a designated pin.

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


## 💡 quick start guide
### Betaflight setup
1) Make sure you flash your flight controller with servo's enabled.
<img src="/images/betaflight flashing screen.png" width="100%">

2) Set up your flight controller as you normaly would.
  
3) Paste this in the CLI, it will display all of your resources and their pins.

   `resource`

4) Find **resource LED_STRIP 1** and note the pin number behind it. In this case it is **A08**.
   <img src="/images/cli_led_strip_pin.png" width="50%">
5) Then write this in the cli, it will remove the pin from the led strip and it will add the pin to servo 1.

   ```
   resource LED_STRIP none
   recource SERVO 1 "your noted pin number from step 4"
   save
   ```
6) Now you are going to go to the servo tab and enter the settings, that are in the red box. The only thing you can change is the channel that the button is on that you want to use to change the presets. You can view which button does what in the receiver tab.
   <img src="/images/servo_tab.png" width="100%">

*Note that it will not work when you are plugged into the pc unless you enable live mode.*

### hardware setup
1) Connect the ground of your flight controller to a ground on the esp. (This is mandatory!!!, because it sets a refernce).

2) Connect the led pin on your flight controller to pin 2 on the esp. This is the wire that caries the data.

3) Power the esp as you want to and connect the leds like you would do on a normal Wled setup.

This is an example wiring diagram, not to be exactly copied. You should do your own research on how to power your esp. We are in no instance responsible for any damage physical or material.

<img src="/images/example_wiring_diagram.png" width="75%">

### Esp setup
1) go to https://espressif.github.io/esptool-js/

## 📲 Quick start guide and documentation

See the [documentation on our official site](https://kno.wled.ge)!

[On this page](https://kno.wled.ge/basics/tutorials/) you can find excellent tutorials and tools to help you get your new project up and running!

## 🖼️ User interface
<img src="/images/macbook-pro-space-gray-on-the-wooden-table.jpg" width="50%"><img src="/images/walking-with-iphone-x.jpg" width="50%">

## 💾 Compatible hardware

See [here](https://kno.wled.ge/basics/compatible-hardware)!

## ✌️ Other

Licensed under the MIT license  
Credits [here](https://kno.wled.ge/about/contributors/)!

Join the Discord server to discuss everything about WLED!

<a href="https://discord.gg/QAh7wJHrRM"><img src="https://discordapp.com/api/guilds/473448917040758787/widget.png?style=banner2" width="25%"></a>

Check out the WLED [Discourse forum](https://wled.discourse.group)!  

You can also send me mails to [dev.aircoookie@gmail.com](mailto:dev.aircoookie@gmail.com), but please, only do so if you want to talk to me privately.  

If WLED really brightens up your day, you can [![](https://img.shields.io/badge/send%20me%20a%20small%20gift-paypal-blue.svg?style=flat-square)](https://paypal.me/aircoookie)


*Disclaimer:*   

If you are prone to photosensitive epilepsy, we recommended you do **not** use this software.  
If you still want to try, don't use strobe, lighting or noise modes or high effect speed settings.

As per the MIT license, I assume no liability for any damage to you or any other person or equipment.  

