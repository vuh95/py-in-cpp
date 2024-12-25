#include <Python.h>
#include <stdio.h>

int main() {
    Py_Initialize();

    FILE* pythonFile = fopen("your_script.py", "r");
    if (pythonFile == NULL) {
        perror("Error opening file");
        return 1;
    }

    int result = PyRun_SimpleFile(pythonFile, "your_script.py");
    if (result != 0) {
        fprintf(stderr, "Execution of Python script failed\n");
    }

    fclose(pythonFile);
    Py_Finalize();

    return 0;
}