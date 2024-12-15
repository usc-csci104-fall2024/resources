# CS104 HW4 Test Suite

### Using the Tests
1. Copy this directory into your `pa4` folder
2. Open a terminal and cd into `hw4_tests`
3. Initialize the test suite by running `cmake .`
4. Run the tests by typing `make grade`.  To run the tests again, you only need to execute this command, not any others.

### Grade Output
Running `make grade` will generate a couple of outputs:
1. In the root directory: A formatted Markdown grade report called `GR4_hw-username.md`. This is nearly equivalent to your Issues report.
2. In the `compile-logs` directory: Logs of the compilation output for each problem
3. In the `results` directory: Files listing the results of each test in a standard format, for input to other grading systems
4. In the `test-output` directory: Files containing the output each test printed.  To figure out why a test failed, start here!
