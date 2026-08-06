# Phase 2 Completition Report - 1D Spring

## 1. Phase Overview

Phase 2 established the basic numerical and software structure for the future tire model.

Phase 2 was completed on []

## 2. Learning Objectives Completed

During this phase, I practiced and applied the following C++ concepts:

I also reviewed the following physics and numerical methods:

## 3. Project Structure

At the completion of Phase 2, the project contains the following important files:

``` text
TireSim/
├── CMakeLists.txt
├── README.md
├── docs/
│   └── CSVs
│       └── Phase 1
│           └── *Generated CSV Files from Phase 1*
│       └── Phase 2
│           └── *Generated CSV Files from Phase 2*
│   └── phase-1.md
│   └── phase-2.md
├── include/
│   └── tiresim/
│       ├── SimulationState.hpp
│       ├── Particle1D.hpp
│       ├── Spring1D.hpp
│       └── CsvWriter.hpp
├── src/
│   ├── main.cpp
│   ├── Particle1D.cpp
│   ├── Spring1D.cpp
│   └── CsvWriter.cpp
└── tests/
```

## 4. Software Design

### SimulationState

```SimulationState``` stores the motion state of the particle at one point in time.

It contains:

- Time
- Position
- Velocity
- Acceleration

These values are grouped because they describe the particle’s current motion state.

Mass and net force are not stored in SimulationState because they describe the particle and its interactions rather than only its instantaneous motion.

### Particle1D

```Particle1D``` represents a particle restricted to one-dimensional motion.

Its responsibilities include:

- Storing mass
- Storing net force
- Storing particle kinetic energy
- Storing the current simulation state
- Rejecting invalid mass values
- Calculating acceleration
- Updating velocity
- Updating position
- Updating simulation time
- Providing controlled access to its values

The internal data is private so outside code cannot place the particle into an invalid or inconsistent state.

### Spring1D

```Spring1D``` represents a spring restricted to one-dimensional motion, bound by an anchor point and an attached particle.

Its responsibilities include:

- Storing spring stiffness
- Setting spring anchor point

### CsvWriter

```CsvWriter``` handles simulation data output.

Its responsibilities include:

- Opening the output file
- Detecting file-opening errors
- Writing column headings
- Writing one simulation state per row

The particle does not write its own CSV data. This keeps the physics model separate from the output system.

### main.cpp

```main.cpp``` currently acts as the simulation controller.

It is responsible for:

- Defining the test conditions
- Creating the particle
- Creating the spring
- Setting inital conditions
- Selecting the timestep
- Selecting the simulation duration
- Running the simulation loop
- Sending state data to the terminal or CSV writer

This responsibility may later be moved into a dedicated simulation class.

## 5. Physics Model

## 6. Numerical Integration

The simulation uses semi-implicit Euler integration.

During each update, the program performs the following operations:

1. Calculate acceleration from net force and mass.
2. Update velocity using the acceleration and timestep.
3. Update position using the new velocity.
4. Advance simulation time.

Velocity is updated before position. This distinguishes semi-implicit Euler from basic explicit Euler.

The numerical method approximates continuous motion through a sequence of discrete updates. As a result, the simulated position may differ slightly from the analytical position.
