# noshroboticsassignment
# Embedded Systems Assignment

## Overview

This repository contains solutions for the Embedded Systems Assignment consisting of two tasks:

1. STM32G070RB LED Blinking with Switch and Low Power Optimization.
2. C Program to Simulate Sensor Data Generation using Timers.

---

## Project Structure

```
├── Q1_STM32_LED_Blink/
│   ├── main.c
│   ├── stm32g0xx_hal_conf.h
│   ├── README.md
│
├── Q2_Sensor_Simulation/
│   ├── main.c
│   ├── README.md
│
└── README.md
```

---

# Question 1 - STM32 LED Blinking

## Objective

Control the onboard LED of the STM32G070RB NUCLEO board using a single push button.

### LED Behaviour

| Switch Press | LED Operation |
|--------------|---------------|
| 1st | Blink at 0.5 Hz |
| 2nd | Blink at 1 Hz |
| 3rd | Blink at 2 Hz |
| 4th | LED OFF |
| 5th | Repeat from first state |

### Features

- External Interrupt (EXTI) for button press
- Timer-based LED blinking
- Low power optimization using Sleep Mode
- State-machine implementation

### Power Optimization

The microcontroller enters Sleep Mode whenever it is idle and wakes only on:

- Push button interrupt
- Timer interrupt

This minimizes power consumption.

---

# Question 2 - Sensor Data Simulation

## Objective

Develop a C program that simulates sensor data generation.

### Functionality

- Every 1 second:
  - Generate 0–5 random bytes.
  - Store them in a global buffer.

- Every 10 seconds:
  - Check the buffer.
  - If at least 50 bytes are available:
    - Print only the latest 50 bytes in hexadecimal format.
    - Remove the printed bytes from the buffer.
  - Otherwise, continue collecting data.

### Features

- Random sensor data generation
- Global shared buffer
- Periodic processing
- Hexadecimal output
- Portable C code compatible with online compilers

---

# Assumptions

## Question 1

- STM32 HAL Library is used.
- One push button and one LED are connected.
- Switch uses EXTI interrupt.
- Timer is used for LED timing.
- Software debouncing is assumed.

## Question 2

- Buffer size is fixed at 1000 bytes.
- Random data is generated using `rand()`.
- One iteration represents one second using `sleep()`.
- The program runs continuously.
- The buffer behaves as a FIFO queue.

---

# Build and Run

## STM32 Project

- Open the project using STM32CubeIDE.
- Build the project.
- Flash it to the NUCLEO-G070RB board.
- Press the user button to observe LED blinking modes.

---

## C Program

The sensor simulation can be executed using any standard C compiler.

### Online Compiler

https://www.programiz.com/c-programming/online-compiler

or compile locally using GCC:

```bash
gcc main.c -o sensor_sim
./sensor_sim
```

---

# Expected Output

Example:

```
Generated 4 bytes
Generated 3 bytes
Generated 5 bytes

Only 39 bytes available. Not printing.

...

Latest 50 Bytes

3A 4F A1 09 FF 6B ...

50 bytes deleted.
Remaining Bytes = 12
```

---

# Time Complexity

| Operation | Complexity |
|-----------|------------|
| Generate Data | O(n), where n ≤ 5 |
| Print 50 Bytes | O(50) |
| Buffer Access | O(1) |

---

# Possible Improvements

- Replace the linear buffer with a circular (ring) buffer.
- Use hardware timers instead of `sleep()`.
- Use mutexes or semaphores for thread safety.
- Add logging and unit tests.
- Implement the program using an RTOS for real embedded applications.

---

# Author

**Name:** Your Name

**Assignment:** Embedded Systems Programming Assignment

**Target Board:** STM32 NUCLEO-G070RB

**Language:** C

**IDE:** STM32CubeIDE (Q1)

**Compiler:** GCC / Online C Compiler (Q2)
