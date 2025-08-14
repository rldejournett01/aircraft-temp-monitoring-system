# Aircraft Cabin Temperature Monitoring System (DO-178C-Style Project)

A small, self-contained C++ project that demonstrates **DO-178C-style software lifecycle artifacts** for a simple embedded-like system: monitoring a cabin temperature sensor once per second and triggering an alert if a configurable threshold is exceeded.

> ⚠️ This repository **does not claim compliance** with DO-178C. It is an educational, lightweight demonstration that mirrors the **structure** and **artifacts** you would expect in a DO-178C-governed project (requirements, design, implementation, verification, and traceability).

---

## Goals

- Show how to structure artifacts to reflect **DO-178C objectives**.
- Keep scope small enough to **implement and review in an afternoon**.
- Provide a clean coding style and simple verification strategy that a reviewer can follow.
