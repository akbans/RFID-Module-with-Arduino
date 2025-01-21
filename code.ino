// Include necessary libraries
#include <SPI.h>
#include <MFRC522.h>

// Define RFID module pins
#define RST_PIN 9     // Reset pin connected to D9 on Arduino
#define SS_PIN 10     // Slave Select pin connected to D10 on Arduino

// Define LED and buzzer pins
#define GREEN_LED 5   // Green LED pin
#define RED_LED 6     // Red LED pin
#define BUZZER 7      // Buzzer pin

// Initialize RFID reader
MFRC522 rfid(SS_PIN, RST_PIN);

// Define an authenticated card UID (modify this to match your card's UID)
byte authorizedUID[] = {0xDE, 0xAD, 0xBE, 0xEF};

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  Serial.println("Place your RFID card near the reader...");

  // Initialize SPI and RFID module
  SPI.begin();
  rfid.PCD_Init();

  // Configure LED and buzzer pins as output
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  // Turn off LEDs and buzzer initially
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, LOW);
  digitalWrite(BUZZER, LOW);
}

void loop() {
  // Check if an RFID card is present
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) {
    return;
  }

  // Print the UID of the card
  Serial.print("Card UID: ");
  for (byte i = 0; i < rfid.uid.size; i++) {
    Serial.print(rfid.uid.uidByte[i], HEX);
    Serial.print(" ");
  }
  Serial.println();

  // Check if the UID matches the authorized UID
  if (isAuthorized(rfid.uid.uidByte, rfid.uid.size)) {
    Serial.println("Access Granted!");
    digitalWrite(GREEN_LED, HIGH); // Turn on green LED
    digitalWrite(RED_LED, LOW);    // Turn off red LED
    digitalWrite(BUZZER, LOW);     // Turn off buzzer
    delay(2000);                   // Keep the green LED on for 2 seconds
    digitalWrite(GREEN_LED, LOW);  // Turn off green LED
  } else {
    Serial.println("Access Denied!");
    digitalWrite(GREEN_LED, LOW);  // Turn off green LED
    digitalWrite(RED_LED, HIGH);   // Turn on red LED
    digitalWrite(BUZZER, HIGH);    // Turn on buzzer
    delay(2000);                   // Keep the red LED and buzzer on for 2 seconds
    digitalWrite(RED_LED, LOW);    // Turn off red LED
    digitalWrite(BUZZER, LOW);     // Turn off buzzer
  }

  // Halt the RFID card
  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
}

// Function to check if the UID matches the authorized UID
bool isAuthorized(byte *uid, byte length) {
  if (length != sizeof(authorizedUID)) {
    return false;
  }
  for (byte i = 0; i < length; i++) {
    if (uid[i] != authorizedUID[i]) {
      return false;
    }
  }
  return true;
}
