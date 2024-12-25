# Python-C++ Integration: Running Python Scripts

### Overview

Running a Python script from C++ using the Python/C API, specifically with `PyRun_SimpleFile`.

### Files

- **`main.cpp`**: :
  - Initializes Python.
  - Executes a Python script.

- **`main_with_args.cpp`**: :
  - Initializes Python.
  - Sets up arguments for `sys.argv`.
  - Executes a Python script with argument.

### How to Use

1. **Compile the C++ Code**:
   - Ensure Python development headers are installed (`python3-dev` or similar).
   - Compile using:

     ```bash
     g++ -o run_python_script main.cpp -I/usr/include/python3.x -lpython3.x
     ```

     ```bash
     g++ -o run_python_script main_with_args.cpp -I/usr/include/python3.x -lpython3.x
     ```
     Replace `3.x` with your Python version.

2. **Run the Program**:
   - Execute the compiled C++ program:
     ```bash
     ./run_python_script
     ```

