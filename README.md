# High-Beam-and-Low-Beam-control-ECU
This project uses two Arduino Uno boards connected via UART to control a vehicle's high-beam and low-beam headlights.
One Arduino handles user input and sends commands to the other Arduino for headlight adjustment. The receiving Arduino interprets these commands and controls the headlight bulbs accordingly. The code on the sending Arduino continuously monitors user input and sends instructions to the receiving Arduino, which in turn adjusts the headlight system based on those instructions.
