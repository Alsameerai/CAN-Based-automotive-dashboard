# CAN-Based-automotive-dashboard

This project implements a CAN-based automotive dashboard using the PIC18F4580 microcontroller. 
It enables real-time monitoring of vehicle parameters through CAN communication.

## 🚗 Features
- CAN frame transmission and reception
- Message ID filtering and parsing
- Interrupt-based CAN communication
- Real-time display of vehicle parameters on CLCD
- UART-based debugging support

## 📊 Parameters Displayed
- Vehicle Speed
- Engine RPM
- Indicator status
- Gear Position

## ⚙️ Technologies Used
- PIC18F4580
- Embedded C
- CAN Protocol
- UART
- MPLAB X IDE
- Terra term for debugging

## 🧠 Concepts Implemented
- CAN arbitration
- Frame structure handling
- Register configuration
- Interrupt handling
- Real-time embedded system design

## 🛠 Working Principle
1. CAN controller initializes with configured baud rate.
2. ECU transmits vehicle data over CAN bus.
3. Dashboard node receives and filters relevant message IDs.
4. Data is parsed and displayed on CLCD.
5. UART used for debugging and monitoring communication.
