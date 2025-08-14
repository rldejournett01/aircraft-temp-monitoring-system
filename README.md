# Aircraft Cabin Temperature Monitoring System (DO-178C-Style Project)

A small, self-contained C++ project that demonstrates **DO-178C-style software lifecycle artifacts** for a simple embedded-like system: monitoring a cabin temperature sensor once per second and triggering an alert if a configurable threshold is exceeded.

> ⚠️ This repository **does not claim compliance** with DO-178C. It is an educational, lightweight demonstration that mirrors the **structure** and **artifacts** you would expect in a DO-178C-governed project (requirements, design, implementation, verification, and traceability).

---

## Goals

- Show how to structure artifacts to reflect **DO-178C objectives**.
- Keep scope small enough to **implement and review in an afternoon**.
- Provide a clean coding style and simple verification strategy that a reviewer can follow.
## Repository Structure

```
avionics-temp-monitor/
├─ README.md
├─ CMakeLists.txt
├─ Makefile
├─ docs/
│  ├─ requirements.md
│  ├─ design.md
│  ├─ verification.md
│  ├─ traceability.md
│  └─ configuration.md
├─ src/
│  ├─ sensor.hpp
│  ├─ sensor.cpp
│  ├─ logger.hpp
│  ├─ logger.cpp
│  ├─ alert.hpp
│  ├─ alert.cpp
│  ├─ controller.hpp
│  ├─ controller.cpp
│  └─ main.cpp
└─ tests/
   ├─ test_temp.cpp
   └─ run_tests.sh
```
### Build (with CMake)
```bash
mkdir -p build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . -j
```

### Run
```bash
./avionics-temp-monitor --threshold 27.0 --period_ms 1000 --iterations 10
```

### Run Unit Tests
```bash
cd build
ctest --output-on-failure
# or run the test binary directly
./tests
```

