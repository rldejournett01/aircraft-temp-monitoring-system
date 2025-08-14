# Verification Plan & Results

## Strategy

- **Requirement-based testing**: Each HLR/LLR has at least one test case.
- **Unit tests** (host-based): Validate alert logic, sensor range, logging format.
- **Integration test**: Short controller run to validate end-to-end behavior.

## Test Cases

| ID   | Requirement(s)   | Description                                               | Procedure / Evidence                       |
|------|------------------|-----------------------------------------------------------|--------------------------------------------|
| TC-1 | LLR-2            | Sensor values fall within [20.0, 30.0] for default seed  | `tests/test_temp.cpp::TestSensorRange`     |
| TC-2 | LLR-3            | Alert when temp > threshold                               | `tests/test_temp.cpp::TestAlertLogic`      |
| TC-3 | LLR-4            | Log format includes timestamp, temp, and status          | `tests/test_temp.cpp::TestLogFormat`       |
| TC-4 | HLR-1, LLR-5     | Controller respects period within ±10% (best-effort)     | `tests/test_temp.cpp::TestPeriodControl`   |
| TC-5 | HLR-2            | Alert path triggers at least once when configured low     | `tests/test_temp.cpp::TestEndToEndAlert`   |
| TC-6 | LLR-7            | CLI rejects invalid params                                | Manual: run `--threshold -1` (non-zero)    |

## How to Run

```bash
mkdir -p build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . -j
ctest --output-on-failure
```

## Results

- See `build/Testing/Temporary/LastTest.log` after running `ctest` for detailed output.
