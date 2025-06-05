# H2O-NURC-2024
2024 NURC Team!
Followed Brandon's instructions on Slack to fix the issue where the Teensy wouldn't recognize the joysticks:
The Teensy computer in the top box doesn't know about many varieties of XBox gamepads. We need to help it find your particular mode. This is a a bit complicated because the Teensy USB library isn't as clever as Windows, so it needs help from you.

At a Windows 10 or 11 computer with a USB port available:

Plug in your gamepad into a USB port on the computer
Type Device Manager into the Windows search box at left end of task bar at bottom of screen
Click on "Device Manager (control panel)" in the search results
Scroll down to Universal Serial Bus Controllers
Click arrow to left of Universal Serial Bus Controllers
Double-click on USB Root Hub (3.0)
Click on the Details tab
Click on the Property bar, then pull down to select Children
Click on Children
You should see the gamepad ID show up as the last line.
Here's a PowerA Enhanced Wired XBox controller (blue):

USB\VID_20D6&PID_200A\0000DE339D005B26

The important numbers are VID_20D6 and PID_200A.

This ID needs to be added to the joystick.cpp file in the TeensyDuino library.

Using a text editor, open the following file:

C:\Program Files (x86)\Arduino\hardware\teensy\avr\libraries\USBHost_t36\joystick.cpp

Locate the line of the first page:
{ 0x045e, 0x02ea, XBOXONE, false },{ 0x045e, 0x02dd, XBOXONE, false },

Add a line below it:
{ 0x20d6, 0x200a, XBOXONE, false },
but instead of the values shown above, use the VID and PID you saw in Device Manager.

Save the file.
Your text editor will complain that it needs to be run as administrator.
Say Yes if it lets you run it as administrator. If not, get Windows tech help.

To upload the code into the Teensy:
You can just plug the top box into the Windows computer's USB port directly to program the Teensy. You don't need to use the whole robot to do this.

Start the Arduino IDE software.

In the File menu, open the file RVTOP-Ccode.ino
It may ask you if it can make a folder to hold the file. Say Yes.

In the Tools menu, choose Board > TeensyDuino > Teensy 4.1
Plug the RVTOP-C board into a USB port on your Windows computer, using a USB A to USB Micro cable.

Select the port in Tools menu > Port > whichever port shows under "Teensy".

Click the right arrow at upper left corner of Arduino IDE window to uplaod the code to the Teensy.
After a minute, the top box LCD display will show the following messages:
"ROVotron Cadet/ ROV Control System / Rev 1.20"
After a moment, it will display "Seeking Gamepad"

Plug in the gamepad into the RVTOP board's USB A port.
The device ID you entered above should appear on the screen.

Now you can unplug the top box from the Windows computer and connect it via the tether to the ROV.
Then connect the 24V battery power to the ROV.
The robot should work after ten seconds of startup time.

