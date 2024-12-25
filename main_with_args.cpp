#include <Python.h>
#include <stdio.h>

int main() {
    // Initialize Python Interpreter
    Py_Initialize();

    // Import sys module
    PyObject* sysModule = PyImport_ImportModule("sys");
    if (sysModule == NULL) {
        PyErr_Print();
        Py_Finalize();
        return 1;
    }

    // Get the argv list from sys module
    PyObject* sysDict = PyModule_GetDict(sysModule);
    PyObject* argvList = PyDict_GetItemString(sysDict, "argv");

    // Clear existing arguments to start fresh
    PyList_SetSlice(argvList, 0, PyList_Size(argvList), NULL);

    // Append script name and arguments
    PyList_Append(argvList, PyUnicode_FromString("your_script.py"));  // Script name
    PyList_Append(argvList, PyUnicode_FromString("--arg"));        // Argument
    PyList_Append(argvList, PyUnicode_FromString("some_value")); // Value for the argument

    // Open the Python file
    FILE* pythonFile = fopen("your_script.py", "r");
    if (pythonFile == NULL) {
        perror("Error opening file");
        Py_Finalize();
        return 1;
    }

    // Run the Python script
    int result = PyRun_SimpleFile(pythonFile, "your_script.py");
    if (result != 0) {
        fprintf(stderr, "Execution of Python script failed\n");
    }

    // Close the file
    fclose(pythonFile);

    // Clean up Python resources
    Py_DECREF(sysModule);
    Py_Finalize();

    return 0;
}