# 🚁 Drone Field Analysis System
**TC1030 — Object-Oriented Programming**  
**Tecnológico de Monterrey, Campus Querétaro**  
**Author:** Valeria Jiménez

## Problem Description
This program simulates a drone equipped with a camera scanner that analyzes
agricultural field zones. It calculates which zones need irrigation or 
fertilization and assigns a priority level (1–5) to each recommendation,
helping farmers optimize their fields efficiently.

## How to Build
```bash
g++ -std=c++14 -Wall main_example_values.cpp -o drone
```

## How to Run
```bash
drone.exe       # Windows
./drone         # Linux/Mac
```

## Expected Output
Zone Z-01 [Moisture:20 Nutrients:45]
Zone Z-02 [Moisture:75 Nutrients:15]
Different zones!
[SCAN] Zone Z-01 | Moisture: 20 | Nutrients: 45
[SCAN] Zone Z-02 | Moisture: 75 | Nutrients: 15
--- Recommendations ---
Irrigating zone Z-01 with 50.0 liters
Applying 12.5 kg of fertilizer to zone Z-02
--- Details ---
Zone: Z-01  Priority: 3/5
Zone: Z-02  Priority: 2/5

## Class Overview
| Class | Concept Demonstrated |
|---|---|
| `FieldZone` | Encapsulation, invariants (0–100 range) |
| `Recommendation` | Abstract base class, virtual destructor |
| `IrrigationRec` | Inheritance, runtime polymorphism |
| `FertilizerRec` | Inheritance, runtime polymorphism |
| `CameraScanner` | Encapsulation, composition part |
| `Drone` | Composition (owns CameraScanner) |
| `FieldManager` | Smart pointers, aggregation |

## OOP Concepts Checklist
- **Encapsulation:** Private fields with validated setters in `FieldZone` and `Recommendation`
- **Inheritance:** `IrrigationRec` and `FertilizerRec` extend abstract `Recommendation`
- **Polymorphism:** `FieldManager` holds `vector<unique_ptr<Recommendation>>` and calls `apply()` virtually
- **Composition:** `Drone` owns a `CameraScanner` by value
- **Exception Handling:** Invalid values throw `std::invalid_argument`
- **Smart Pointers:** `unique_ptr` for all heap-allocated recommendations
- **RAII:** No raw `new/delete` in ownership positions

## Ownership — Rule of Zero
All classes use the **Rule of Zero**: every resource is owned through RAII 
wrappers (`std::string`, `std::vector`, `std::unique_ptr`). No manual 
destructor, copy constructor, or assignment operator was needed because 
the standard library handles memory automatically and correctly.
