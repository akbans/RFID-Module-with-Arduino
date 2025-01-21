# Arduino RFID RC522 Authentication System

This project demonstrates how to use an **RFID RC522 module** with an Arduino to authenticate RFID cards. The system turns on a green LED if an authorized RFID card is scanned and turns on a red LED and activates a buzzer for unauthorized cards.

## Features

- **RFID Authentication**: Reads the UID of an RFID card and compares it to predefined authorized UIDs.
- **Feedback**: Turns on a green LED for authorized cards, a red LED and buzzer for unauthorized ones.

---

## Components Required

- **Arduino Uno (or any compatible board)**  
- **RFID RC522 Module**  
- **Green LED**  
- **Red LED**  
- **Buzzer**  
- **Resistors (220Ω)**  
- **Jumper Wires**  
- **Breadboard**  

---

## Circuit Diagram

Refer to the included file: **`circuit.png`** for wiring details. Below is a summary of the connections:

| RFID Pin | Arduino Pin |  
|----------|-------------|  
| 3.3V     | 3.3V        |  
| GND      | GND         |  
| RST      | Pin 9       |  
| SDA      | Pin 10      |  
| MOSI     | Pin 11      |  
| MISO     | Pin 12      |  
| SCK      | Pin 13      |  

Other connections:
- **Green LED**: Connect to a digital pin (e.g., Pin 7) via a 220Ω resistor.  
- **Red LED**: Connect to another digital pin (e.g., Pin 6) via a 220Ω resistor.  
- **Buzzer**: Connect to a digital pin (e.g., Pin 5).

---

## How It Works

1. When an RFID card is brought near the RC522 module, its UID is read.  
2. The UID is compared against a list of authorized UIDs stored in the code.  
   - **If authorized**:  
     - The green LED turns on for 3 seconds.  
   - **If unauthorized**:  
     - The red LED turns on for 3 seconds, and the buzzer beeps.  

---

## Getting Started

### 1. Clone the Repository

### 2. Open the Code
Open `code.ino` in the **Arduino IDE**.

### 3. Install Required Libraries
Make sure the following libraries are installed in your Arduino IDE:
- **SPI**
- **MFRC522**

You can install them through the Arduino Library Manager (`Sketch > Include Library > Manage Libraries`).

### 4. Upload the Code
- Connect your Arduino board to your computer.
- Select the correct board and COM port in the Arduino IDE.
- Click **Upload** to flash the code to your Arduino.

### 5. Test the System
- Power the Arduino and connect all components as per the circuit diagram.
- Bring an RFID card near the module to test.

---

## Customization

- **Change Authorized UID**: Update the `authorizedUID` array in `code.ino` with your card's UID.  
- **LED and Buzzer Behavior**: Modify the delay times or patterns in the code for LEDs and buzzer as needed.

---

## Troubleshooting

- **RFID Not Detected**: Check connections between the RFID module and Arduino. Ensure correct wiring of `SCK`, `MISO`, `MOSI`, and `SDA` pins.
- **Incorrect UID**: Ensure the RFID card's UID matches the one stored in `authorizedUID`.
- **No LED/Buzzer Response**: Verify connections and that the pins match those defined in the code.

## Acknowledgments

- **RFID Library**: Thanks to [Miguel Balboa's MFRC522 library](https://github.com/miguelbalboa/rfid) for simplifying RFID communication with Arduino.
Shri Harivansh, hope you like it !
![Arduino Bluetooth Controlled Robot (1)](https://github.com/user-attachments/assets/a4b46f19-5ce9-4a01-9dd6-c1c3ec2bc612)
