# Bidirectional Traceability Matrix

| Requirement | Design Element         | Code Location                  | Test Case                         |
|-------------|------------------------|--------------------------------|-----------------------------------|
| HLR-1       | Controller periodic    | `controller.cpp`               | TC-4                              |
| HLR-2       | Threshold check, Alert | `controller.cpp`, `alert.cpp`  | TC-2, TC-5                        |
| HLR-3       | Logger                 | `logger.cpp`                   | TC-3                              |
| HLR-4       | CLI/config handling    | `main.cpp`                     | TC-6 (manual)                     |
| LLR-1       | Sensor interface       | `sensor.hpp/cpp`               | TC-1                              |
| LLR-2       | Deterministic sim      | `sensor.cpp`                   | TC-1                              |
| LLR-3       | `temp > threshold`     | `controller.cpp`               | TC-2                              |
| LLR-4       | Log line format        | `logger.cpp`                   | TC-3                              |
| LLR-5       | Period control         | `controller.cpp`               | TC-4                              |
| LLR-6       | Clean shutdown         | `controller.cpp`, `main.cpp`   | TC-5 (implicit), exit code check  |
| LLR-7       | Input validation       | `main.cpp`                     | TC-6 (manual)                     |
