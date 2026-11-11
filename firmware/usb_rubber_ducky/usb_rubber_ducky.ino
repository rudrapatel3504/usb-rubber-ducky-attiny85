/*
 * ============================================================
 * PROJECT: ATtiny85 USB RUBBER DUCKY
 * ============================================================
 *
 * Platform       : Digispark ATtiny85
 * Language       : Embedded C++
 * IDE            : Arduino IDE
 * USB Protocol   : USB HID
 * Library        : DigiKeyboard
 *
 * DESCRIPTION:
 * This firmware demonstrates USB keyboard emulation using
 * an ATtiny85 microcontroller.
 *
 * When connected to a computer, the board behaves like a
 * USB keyboard and types a predefined demonstration message
 * into the currently focused text editor.
 *
 * SAFETY:
 * This demonstration does not execute shell commands,
 * access files, collect data, or modify system settings.
 *
 * ============================================================
 */

#include "DigiKeyboard.h"

// ------------------------------------------------------------
// CONFIGURATION
// ------------------------------------------------------------

// Time allowed for USB initialization (milliseconds)
#define USB_STARTUP_DELAY 2000

// Delay between demonstration lines
#define LINE_DELAY 700

// Delay between individual typing operations
#define TYPING_DELAY 100


// ------------------------------------------------------------
// FUNCTION DECLARATIONS
// ------------------------------------------------------------

void initializeKeyboard();

void typeProjectTitle();

void typeProjectDetails();

void typeHardwareDetails();

void typeTechnicalDetails();

void typeSafetyNotice();

void typeLine(const char* message);

void nextLine();


// ------------------------------------------------------------
// SETUP FUNCTION
// ------------------------------------------------------------

void setup()
{
    // Initialize USB HID communication
    initializeKeyboard();

    // Give the computer time to initialize USB
    DigiKeyboard.delay(USB_STARTUP_DELAY);

    // Execute the demonstration sequence
    typeProjectTitle();

    typeProjectDetails();

    typeHardwareDetails();

    typeTechnicalDetails();

    typeSafetyNotice();

    // Finish with a confirmation message
    typeLine("Demonstration completed successfully!");

    nextLine();
}


// ------------------------------------------------------------
// MAIN LOOP
// ------------------------------------------------------------

void loop()
{
    /*
     * Empty loop.
     *
     * The demonstration runs only once during startup.
     * This prevents repeated automatic typing.
     */
}


// ------------------------------------------------------------
// USB KEYBOARD INITIALIZATION
// ------------------------------------------------------------

void initializeKeyboard()
{
    /*
     * Send an empty keyboard report.
     *
     * This initializes the keyboard interface and ensures
     * that no unwanted key is held during startup.
     */

    DigiKeyboard.sendKeyStroke(0);

    DigiKeyboard.delay(500);
}


// ------------------------------------------------------------
// PROJECT TITLE
// ------------------------------------------------------------

void typeProjectTitle()
{
    typeLine("====================================");

    typeLine("    ATTINY85 USB RUBBER DUCKY");

    typeLine("====================================");

    nextLine();
}


// ------------------------------------------------------------
// PROJECT INFORMATION
// ------------------------------------------------------------

void typeProjectDetails()
{
    typeLine("Project: USB HID Keyboard Emulator");

    typeLine("Controller: ATtiny85");

    typeLine("Platform: Digispark Development Board");

    typeLine("Language: Embedded C++");

    typeLine("Interface: USB HID");

    nextLine();
}


// ------------------------------------------------------------
// HARDWARE INFORMATION
// ------------------------------------------------------------

void typeHardwareDetails()
{
    typeLine("HARDWARE CONFIGURATION:");

    typeLine("- ATtiny85 Microcontroller");

    typeLine("- USB Interface");

    typeLine("- Digispark Development Board");

    nextLine();
}


// ------------------------------------------------------------
// TECHNICAL INFORMATION
// ------------------------------------------------------------

void typeTechnicalDetails()
{
    typeLine("TECHNICAL DEMONSTRATION:");

    typeLine("- USB HID Initialization");

    typeLine("- Keyboard Emulation");

    typeLine("- Automated Keystrokes");

    typeLine("- Firmware Timing Control");

    typeLine("- Embedded C++ Programming");

    nextLine();
}


// ------------------------------------------------------------
// SAFETY INFORMATION
// ------------------------------------------------------------

void typeSafetyNotice()
{
    typeLine("SECURITY NOTICE:");

    typeLine("This is an authorized HID demonstration.");

    typeLine("No system commands are executed.");

    typeLine("No personal information is accessed.");

    nextLine();
}


// ------------------------------------------------------------
// REUSABLE TEXT TYPING FUNCTION
// ------------------------------------------------------------

void typeLine(const char* message)
{
    /*
     * Print the supplied text through the USB keyboard
     * interface.
     */

    DigiKeyboard.print(message);

    // Allow a short interval before the next operation
    DigiKeyboard.delay(TYPING_DELAY);

    // Move to the next line
    DigiKeyboard.println("");
}


// ------------------------------------------------------------
// KEYBOARD ENTER FUNCTION
// ------------------------------------------------------------

void nextLine()
{
    /*
     * Send the Enter key.
     */

    DigiKeyboard.sendKeyStroke(0x28);

    DigiKeyboard.delay(LINE_DELAY);
}
