# Server Cooling Solutions

## Introduction

In the modern world, the Internet of Things (IoT) is becoming increasingly significant in various fields. With the growing adoption of IoT devices and technologies, the importance of education and acquiring skills in IoT technology stacks is also rising. Consequently, there is a growing need for demonstration materials that can quickly and clearly explain the principles of IoT networks. This need is particularly relevant for educational institutions, scientific events, and exhibitions.

This project is an educational IoT kit that serves as a prototype platform for collecting, transmitting, and processing data received from IoT devices. The platform allows interaction with sensors and actuators installed on the stand via a web application.

## Project Goal

The goal of this project is to create a system for effective monitoring and management of temperature in server rooms. The system includes hardware and software components for collecting, transmitting, and analyzing temperature data, as well as visualizing this data using VR technology.

## Project Tasks

To achieve this goal, the following tasks were formulated:

1. Analysis of the subject area and existing solutions.
2. Determining the functional requirements of the developed device.
3. Selection and integration of electronic components of the system.
4. Development of the system architecture.
5. Creation of firmware for the microcontroller.
6. Development of a web application for system interaction.
7. Integration of a VR solution for visualizing the server room state.

## Subject Area Analysis

Temperature monitoring is a critical component of managing server rooms. Overheating of servers can lead to equipment failure, resulting in downtime and data loss. Modern IoT technologies enable efficient real-time monitoring and management of temperature.

## Existing Solutions

Various systems for monitoring and managing temperature in server rooms are available on the market. However, many of them are either too expensive or difficult to integrate with existing infrastructure. Our solution aims to create an affordable and easily integrable product.

## Functional Requirements

The developed device should provide the following functionality:

1. Data collection from temperature sensors.
2. Real-time data transmission to the server.
3. Fan control based on the received data.
4. Web interface for monitoring and managing the system.
5. VR interface for visualizing the server room state.

## Electronic Component Selection

The following electronic components were selected for the project:

1. ESP32 microcontroller for data collection and transmission.
2. Temperature sensor (BMP280).
3. Fans for cooling server equipment.
4. Necessary connecting wires and adapters.

## System Architecture Development

The developed system's structural diagram includes:

1. ESP32 microcontroller connected to the temperature sensor and fans.
2. Server for receiving and processing data.
3. Web interface for monitoring and management.
4. VR interface for visualization.

## Software Development

### Microcontroller Firmware

The firmware for the ESP32 was created using VS Code and the C++ programming language on RIOT OS. The firmware provides data collection from the temperature sensor, fan control, and data transmission to the server.

### Web Application

The web application was developed using Django and Django REST Framework. It provides an interface for monitoring temperature data and controlling the fans.

### VR Application

The VR application was developed using Unreal Engine 5.3.2 for the Oculus Quest 3. It provides real-time visualization of the server room state. The application integrates with the web interface to receive temperature data.

## Results

The system was successfully assembled and tested. The web application is accessible and allows real-time monitoring of temperature data. The VR application provides an interactive visualization of the server room. The project repository includes detailed API descriptions, algorithms, and more.

## Conclusion

This project developed a system for monitoring and managing temperature in server rooms. The system includes hardware and software components that ensure data collection, transmission, and visualization. The project demonstrates the potential of integrating IoT and VR technologies for real-time monitoring and management tasks.

## Further Development

Possible directions for further development of the project include:

1. Adding support for new sensors and actuators.
2. Integrating with machine learning systems for data prediction and analysis.
3. Expanding the functionality of the web application.
4. Improving the VR interface and adding new visualization features.
5. Alpha testing.
6. Beta testing.
7. Pilot operation.
8. Project pitching.

## Project Structure

- `vr-project/` - Contains the VR project code.
- `server/` - Contains the server code and web application.
- `hardware/` - Contains descriptions and schematics of the hardware components.
- `firmware/` - Contains the firmware code for the device.

## Installation and Setup

### Server

To install and run the server:

1. Clone the repository:
    ```bash
    git clone https://github.com/xrpusher/thermashield/
    cd thermashield/server
    ```

2. Install the dependencies:
    ```bash
    pip install -r requirements.txt
    ```
   you can also use venv
   
4. Run database migrations:
    ```bash
    python manage.py migrate
    ```

5. Start the development server:
    ```bash
    python manage.py runserver
    ```

### VR Project

To set up and run the VR project:

1. Navigate to the `vr-project` directory:
    ```bash
    cd vr-project
    ```

2. Follow the instructions in the `README.md` file located in the `vr-project` directory for setup and running the VR application.

### Hardware and Firmware

1. The `hardware` directory contains descriptions and schematics of the hardware components.
2. The `firmware` directory contains the firmware for the microcontroller. To upload the firmware to the microcontroller:
    - Connect the microcontroller to your computer.
    - Open the firmware file in VS Code or another suitable tool.
    - Upload the firmware to the microcontroller.

---

This README provides an overview of the project and instructions for installing and using its various components. For more detailed information, please refer to the documentation in the respective directories.
