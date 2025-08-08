<img width="3188" height="1202" alt="frame (3)" src="https://github.com/user-attachments/assets/517ad8e9-ad22-457d-9538-a9e62d137cd7" />


# [Room Exit Reminder System] 🎯


## Basic Details
### Team Name: Clueless Crew


### Team Members
- Member 1:Aardra LB - College Of Engineering Munnar
- Member 2: Sreedhar Adithyan V - College Of Engineering Munnar

### Project Description
Ever walked out of your room and forgotten your phone, wallet, or any other important item?  This project is about it.
 
### The Problem (that doesn't exist)
This project solves that problem by **reminding you before you leave!**
### The Solution (that nobody asked for)
The IR sensors play detective to see if you’re sneaking in or heading out, while the load cell keeps an eye on your stuff like a paranoid roommate. If you try to leave without your precious phone, the buzzer screams, ‘Hey! Forget something?!’ before you make your great escape.
## Technical Details
### Technologies/Components Used
For Software:
- Embedded C
- Arduino IDE core framework
- `HX711.h` – for interfacing with the load cell
-  Arduino IDE (code writing, compiling, and uploading)    
-   Serial Monitor (for debugging and output logs)

For Hardware:
-  Arduino Uno (or compatible board)
    
-   HX711 Load Cell Amplifier Module
    
-   Load Cell  
    
-   Two IR Obstacle Detection Sensors
    
-   Active Buzzer Module
    
-   Breadboard
    
-   Jumper wires
##
-  Arduino IDE for programming
    
-   USB cable for uploading code
    
-   Digital multimeter (optional, for debugging)
    
-   Small screwdriver (for mounting load cell)
    
-   Soldering kit (optional, for permanent setup)

### Implementation
For Software: 
1.  **Sensor Input Handling**
    
    -   IR sensors detect motion direction (entry or exit) using **falling edge detection**.
        
    -   Debounce logic ensures stable readings and avoids false triggers.
        
2.  **Weight Measurement**
    
    -   HX711 library reads load cell data at regular intervals (every 100 ms).
        
    -   Converts measured units to grams for easier threshold comparison.
        
3.  **Direction Logic**
    
    -   If **exit** is detected, system checks current load cell reading.
        
    -   If weight is below a defined threshold (e.g., missing phone), trigger alert.
        
4.  **Buzzer Alert**
    
    -   Buzzer turns ON for a set duration (5 seconds in code) when missing item is detected.
        
    -   Alert resets when person re-enters or weight is restored.
        
5.  **Non-Blocking Code**
    
    -   Uses `millis()` timers for weight updates and sensor reads to avoid delays.
        
6.  **Serial Debugging**
    
    -   Serial Monitor outputs real-time logs for testing and calibration.
# Installation
### **1. Install Arduino IDE**

Download and install the Arduino IDE from the official Arduino website.

### **2. Install Required Library**

Open Arduino IDE → Go to **Sketch → Include Library → Manage Libraries…**  
Search for **HX711** and install it.  
Or install via ZIP file:

`# Download HX711 library ZIP https://github.com/bogde/HX711/archive/refs/heads/master.zip # In Arduino IDE Sketch → Include Library → Add .ZIP Library…` 

### **3. Connect Hardware**

-   Connect IR sensors, load cell (via HX711), buzzer, and Arduino according to the circuit diagram.
    
-   Make sure wiring matches the pin numbers in the code.
    

### **4. Upload Code**

`# Open Arduino IDE  # Load the provided .ino file  # Select the correct board and COM port  # Upload the code` 

### **5. Calibrate the Load Cell**

-   Run the code with a known weight.
    
-   Adjust `calibration_factor` in the code until the reading matches the real weight.

# Run
Once the code is uploaded to the Arduino:

`1. Connect Arduino to your PC or a 5V power source. 
 2. Open Serial Monitor in Arduino IDE (9600 baud rate) to view logs.  
 3. Place your important item (e.g., phone) on the load cell platform.  
 4. Walk towards the door — IR sensors will detect your movement. 
 5. If you exit and the item is missing, buzzer will alert you.` 

**Note:**

-   Adjust the `grams` threshold in the code if you’re using lighter or heavier items.
    
-   Make sure the sensors are positioned to clearly detect entry and exit direction.

### Project Documentation
#### **1. Language & Environment**

-   **Language:** Embedded C
    
-   **Platform:** Arduino IDE
    
-   **Target Hardware:** Arduino Uno (or compatible board)
    

#### **2. Code Structure**

-   **`setup()`** – Initializes serial communication, configures pins, sets up the load cell and IR sensors.
    
-   **`loop()`** – Runs main logic:
    
    -   Updates weight measurement at fixed intervals (`millis()`-based).
        
    -   Reads sensor states with debounce delay.
        
    -   Handles buzzer logic based on direction and item presence.
        

#### **3. Functional Flow**

1.  **Initialization** – Set calibration factor, tare load cell, and store baseline.
    
2.  **Sensor Reading** – Detects falling edges on IR sensors to determine movement direction.
    
3.  **Weight Monitoring** – Continuously measures grams and compares to threshold.
    
4.  **Decision Making** – If “exit” detected and weight is below threshold, trigger buzzer.
    
5.  **Alert System** – Buzzer stays ON for set duration, then resets after condition clears.
    

#### **4. Libraries Used**

-   `HX711.h` – For interfacing with the load cell ADC module.
    

#### **5. Special Features**

-   Non-blocking design using `millis()` for smooth operation.
    
-   Debounce logic for stable IR sensor readings.
    
-   Easily configurable weight threshold and buzzer duration.

# Screenshots (Add at least 3)
 https://drive.google.com/file/d/1ttz8TlK2KD76LSznvuZd0Z97MNJNQV7l/view?usp=drivesdk 
*Arduino IDE showing the code setup for IR sensors, load cell, and buzzer, with Serial Monitor output indicating multiple entry and exit triggers detected by the system.
https://drive.google.com/file/d/1tv1oIU7LX03Vbuyf2Zka1dvfczA81_xY/view?usp=drivesdk
*System actively detecting both entry and exit events, printing direction decisions (‘GOING OUT’ / ‘GOING IN’) to the Serial Monitor in real time.*

https://drive.google.com/file/d/1ttmYkGu4HSOdYQijEsDPo36KR-McKVzB/view?usp=drivesdk
https://drive.google.com/file/d/1ttmYkGu4HSOdYQijEsDPo36KR-McKVzB/view?usp=drivesdk
IR sensors detecting sequential movement patterns, with Serial Monitor confirming direction detection logic and transitions between entry and exit states.
# Schematic & Circuit
https://drive.google.com/file/d/1u-6sBsLPm-INNRh3JPVmdztRGS0Zosno/view?usp=drivesdk
*The circuit connects two IR obstacle sensors to Arduino digital pins for entry/exit detection, a load cell via the HX711 module to measure item weight, and a buzzer to pin 13 for alerts. The load cell’s DT and SCK pins connect to Arduino pins 2 and 3, while IR sensors are connected to pins 4 and 5 with VCC to 5V and GND to ground.*

# Build Photos
https://drive.google.com/file/d/1u2NKfekXJkl7UbKUPv8U407rKcrkDtsE/view?usp=drivesdk
*-   Arduino Uno (or compatible board)
    
-   HX711 Load Cell Amplifier Module
    
-   Load Cell (1–5 kg capacity, depending on item weight)
    
-   Two IR Obstacle Detection Sensors
    
-   Active Buzzer Module
    
-   Breadboard
    
-   Jumper wires*

https://drive.google.com/drive/folders/1uA_-0DhaYI4SQREbvXQX9Yhrj8tsxewa
*### **1. Gather Components**

-   **Arduino Uno** (or compatible board)
    
-   **2 × IR Sensors** (entry & exit detection)
    
-   **HX711 module + Load cell** (weight measurement)
    
-   **Active buzzer** (alert system)
    
-   Breadboard, jumper wires, USB cable
    

----------

### **2. Assemble the Circuit**

1.  **Connect the HX711** to the Arduino
    
    -   VCC → 5V, GND → GND, DT → D2, SCK → D3
        
    -   Connect the **load cell wires** to the HX711 (verify colour mapping from manufacturer).
        
2.  **Connect the IR Sensors**
    
    -   Entry sensor OUT → D4, Exit sensor OUT → D5
        
    -   Both sensors VCC → 5V, GND → GND.
        
3.  **Connect the Buzzer**
    
    -   -   → D13, − → GND.
            
4.  Ensure **all grounds are common**.
    

----------

### **3. Upload the Code**

-   Open **Arduino IDE**.
    
-   Install **HX711 library** (Tools → Manage Libraries → Search "HX711").
    
-   Paste the project code.
    
-   Adjust `calibration_factor` for the load cell.
    
-   Upload to Arduino via USB.
    

----------

### **4. Test the Sensors**

-   Place your important item (phone, keys, etc.) on the load cell.
    
-   Walk past the entry and exit IR sensors to check direction detection.
    
-   Verify that:
    
    -   If you **exit** and the **item is missing**, buzzer beeps.
        
    -   If you **exit** with item in place, no alarm.
        

----------

### **5. Fine-Tune**

-   Adjust IR sensor sensitivity (potentiometer on sensor).
    
-   Modify code for different weight thresholds.
    
-   Add small delays or debounce logic to avoid false triggers*

https://drive.google.com/file/d/1u9bGgFu02IPFxdtWHAxdo8xj2LIq0gfX/view?usp=drivesdk


### Project Demo
# Video
[https://drive.google.com/file/d/1uB2zkn4YiwwXrmHkxZGpuoDaW1IpHxIM/view?usp=drivesdk
-   **IR Sensors** detect the direction of movement — whether you’re going **in** or **out** of the room.
    
-   A **Load Cell (HX711)** continuously measures the weight of items placed in a specific spot (e.g., your table or a shelf near the door).
    
-   If you leave the room (**exit detected**) and the system notices that the weight of your important item is missing (e.g., your phone isn’t there),  
    the **buzzer alerts you** before you’re too far away.

 
 
---
Made with ❤️ at TinkerHub Useless Projects 

![Static Badge](https://img.shields.io/badge/TinkerHub-24?color=%23000000&link=https%3A%2F%2Fwww.tinkerhub.org%2F)
![Static Badge](https://img.shields.io/badge/UselessProjects--25-25?link=https%3A%2F%2Fwww.tinkerhub.org%2Fevents%2FQ2Q1TQKX6Q%2FUseless%2520Projects)


