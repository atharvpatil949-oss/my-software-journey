# COEP ENTC Engineering Toolkit

A modular, multi-tool C++ application designed to solve core mathematical and architectural problems in Electronics and Telecommunication Engineering. 

## 🚀 Features & Modules
This toolkit operates through a central terminal router that grants access to five specialized modules:
1. **Resistor Color Code Calculator:** Maps physical band colors to ohmic values using C++ data structures (`std::map`).
2. **Student Mark Tracker:** Analyzes academic performance and distributions using dynamic memory allocation (`std::vector`).
3. **Digital Signal Plotter:** Simulates and plots discrete continuous wave formulas (e.g., $y = A \cdot \sin(2\pi ft)$).
4. **Logic Gate Simulator:** Executes foundational boolean algebra (`&&`, `||`, `!`) to generate binary truth tables.
5. **Number Base Converter:** Safely translates machine-level binary into hex and decimal utilizing advanced error handling (`try-catch`).

## 🏗️ Architecture
This system is built using a professional **Modular Architecture**. 
Rather than a single monolithic file, the application is split into specialized Header (`.h`) and Implementation (`.cpp`) files. The central `main.cpp` acts purely as a routing engine, delegating tasks to the specific modules to ensure scalability and clean code.

## ⚙️ How to Compile & Run
Because this project utilizes a multi-file architecture, all `.cpp` files must be linked during compilation.

**1. Compile the application:**
`g++ main.cpp resistor_calc.cpp mark_tracker.cpp signal_generator.cpp logic_gates.cpp base_converter.cpp -o toolkit`
*(Alternatively, you can use `g++ *.cpp -o toolkit`)*

**2. Run the executable:**
`./toolkit`