# Phase 1 Completition Report - 1D Motion

## 1. Phase Overview

Phase 1 established the basic numerical and software structure for the future tire model.

The goal of this phase was to create and validate a simple 1D Particle Sim that can:

- Store the state of a moving object.
- Store particle properties such as mass and force.
- Calculate acceleration using Newton's Second Law.
- Advance motion using a fixed timestep.
- Record simulation results to a CSV.
- Compare numerical results with analytical predictions.

Phase 1 was completed on 7/31/2026

## 2. Learning Objectives Completed

During this phase, I practiced and applied the following C++ concepts:

- Structures
- Classes
- Public and private access
- Constructors
- Member functions
- Header and source file separation
- Const member functions
- References
- Exceptions
- Fixed-timestep loops
- Compile-time constants using ```constexpr```
- File output using CSV files

I also reviewed the following physics and numerical methods:

- Position
- Velocity
- Acceleration
- Mass
- Force
- Newton’s second law
- Constant-acceleration equations
- Semi-implicit Euler integration
- Numerical error
- Timestep convergence

## 3. Project Structure

At the completion of Phase 1, the project contains the following important files:

``` text
TireSim/
├── CMakeLists.txt
├── README.md
├── docs/
│   └── Code Tasks/
│       └── Phase 1 Code Tasks.cpp
│   └── CSVs
│       └── Phase 1
│           └── *Generated CSV Files from Phase 1*
│   └── phase-1.md
├── include/
│   └── tiresim/
│       ├── SimulationState.hpp
│       ├── Particle1D.hpp
│       └── CsvWriter.hpp
├── src/
│   ├── main.cpp
│   ├── Particle1D.cpp
│   └── CsvWriter.cpp
├── output/
└── tests/
```

Not every folder must contain completed files yet. This structure provides room for future simulation components and tests.

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
- Storing the current simulation state
- Rejecting invalid mass values
- Calculating acceleration
- Updating velocity
- Updating position
- Updating simulation time
- Providing controlled access to its values

The internal data is private so outside code cannot place the particle into an invalid or inconsistent state.

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
- Setting the net force
- Selecting the timestep
- Selecting the simulation duration
- Running the simulation loop
- Sending state data to the terminal or CSV writer

This responsibility may later be moved into a dedicated simulation class.

## 5. Physics Model

The particle uses Newton’s second law to calculate acceleration from net force and mass.

The current model assumes:

- Motion occurs along one axis.
- Mass remains constant.
- Net force is supplied directly to the particle.
- The particle behaves as a point mass.
- No rotational motion is included.
- No deformation is included.

The current test cases primarily use constant net force.

## 6. Numerical Integration

The simulation uses semi-implicit Euler integration.

During each update, the program performs the following operations:

1. Calculate acceleration from net force and mass.
2. Update velocity using the acceleration and timestep.
3. Update position using the new velocity.
4. Advance simulation time.

Velocity is updated before position. This distinguishes semi-implicit Euler from basic explicit Euler.

The numerical method approximates continuous motion through a sequence of discrete updates. As a result, the simulated position may differ slightly from the analytical position.
