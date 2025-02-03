#include <LiquidCrystal.h>

// Initialize the LCD object with pin connections
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

const int buttonPin = 2; // Push button connected to D2
int buttonState = 0;     // Variable to store the button state
int lastButtonState = 0; // Variable to store the previous button state
int count = 0;           // Counter for button presses

void setup() {
  lcd.begin(16, 2);      // Initialize the LCD (16x2)
  lcd.print("Button Count:"); // Print message on the first line
  
  pinMode(buttonPin, INPUT); // Configure D2 as an input pin
}

void loop() {
  buttonState = digitalRead(buttonPin); // Read the button state

  // Detect a button press (falling edge)
  if (buttonState == HIGH && lastButtonState == LOW) {
    delay(20); // Debounce delay
    if (digitalRead(buttonPin) == HIGH) { // Confirm stable press
      count++; // Increment count
      // Update the LCD
      lcd.setCursor(0, 1); // Move to the second line
      lcd.print("Presses: ");
      lcd.print(count);
      lcd.print("    "); // Clear trailing characters
    }
  }

  lastButtonState = buttonState; // Save the current state as the last state
}
