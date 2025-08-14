# Configuration Data

| Parameter     | Type   | Default | Range / Constraint                  | Description                         |
|---------------|--------|---------|-------------------------------------|-------------------------------------|
| `threshold`   | float  | 27.0    | 0.0–100.0                           | °C threshold for high-temp alert    |
| `period_ms`   | int    | 1000    | 50–10000                            | Sampling period in milliseconds     |
| `iterations`  | int    | 0       | 0–1,000,000                         | Number of cycles; 0 means infinite  |
| `seed`        | uint32 | 12345   | any 32-bit value                    | Seed for deterministic simulation   |

> Treat these as **configuration data** (DO-178C concept). They are inputs that affect behavior without changing the code.
