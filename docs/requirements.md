# Software Requirements Specification (SRS)

> Scope: Educational demonstration of DO-178C-style artifacts for a simple cabin temperature monitor.

## Definitions
- **HLR**: High-Level Requirement
- **LLR**: Low-Level Requirement

---

## High-Level Requirements

- **HLR-1 (Sampling):** The system shall read temperature sensor data at a configured periodic rate (default 1000 ms).
- **HLR-2 (Alerting):** The system shall trigger a high-temperature alert when the measured temperature strictly exceeds a configured threshold (default 27.0 °C).
- **HLR-3 (Logging):** The system shall log each measured temperature and any generated alerts.
- **HLR-4 (Config Data):** The system shall accept configuration parameters at startup (threshold, sampling period, and number of iterations).

---

## Low-Level Requirements

- **LLR-1 (Sensor Interface):** Provide a sensor interface that returns a floating-point temperature in degrees Celsius.
- **LLR-2 (Deterministic Simulation):** In the absence of real hardware, the sensor shall support a deterministic simulation mode using a seeded pseudo-random generator with a nominal range [20.0°C, 30.0°C].
- **LLR-3 (Alert Condition):** The alert condition shall be `temp > threshold`.
- **LLR-4 (Logging Format):** Each log entry shall contain an ISO-8601 timestamp, the measured temperature, and the alert status (“ALERT”/“OK”).
- **LLR-5 (Controller Period):** The controller shall attempt to maintain the configured period within ±10% when running on a non-real-time OS.
- **LLR-6 (Shutdown):** The program shall exit with code 0 after processing the configured number of iterations; non-zero on fatal error.
- **LLR-7 (Input Validation):** The program shall validate CLI inputs and reject invalid values with a non-zero exit code and a diagnostic message.
