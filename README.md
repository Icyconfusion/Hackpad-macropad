# Hackpad-macropad
A small macropad based off of Blueprint Hackclub's hackpad guide. It has 2x EC11 rotary encoders, 14x switches, and an oled screen. based off the XIAO rp2040 DIP. 

The left rotary encoder is used to cycle through 3 layers, creating 54 unique outputs from just 16 physical inputs. The firmware was very difficult on QMK, as I used charlieplexing in the wiring. The case comes in two parts, a base, which the pcb sits inside, and a top plate which sits on top and is held in by screws. 

The case assembles as so:
![alt text](image.png)

![alt text](image-1.png)

Schematic:
![alt text](image-2.png)

PCB:
![alt text](image-3.png)

BOM:
14x Cherry MX switches
2x EC11 rotary encoders
1x 0.91" 128x32 SSD1306 Oled display
1x XIAO RP2040
1x PCB
14x Blank DSA Keycaps
4x M3x16 Bolt
4x M3 Heatset

During the prject I had to solve the issue of not having enough pins to fit all the buttons. This led me to trying a button matrix, but instead I chose charlieplexing as the more appropriate method to fit the buttons. I then decided, to increase the outputs, I should introduce layers to the macropad in QMK. This part of the QMK firmware was quite easy, but it took many, many hours attempting to solve the problems that arose from charlieplexing.
A massive thank you to Hackclub blueprint for this project and their guidance on the Hackpad project.
