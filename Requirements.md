# Homework Assignment 1: Personalized C++ Program with Arrays, Functions, and Dynamic Memory

## Assignment Overview

Create a complete C++ program based on a creative theme of your choice. Your program must use the required programming techniques below in a single, coherent scenario. Everyone must meet the same technical requirements, but your theme, prompts, names, calculations, menu wording, and output design should be your own.

The program must compile, run, and produce output that makes sense for the chosen theme.

## Common Program Standards

- Compile with C++17 or greater in a Linux environment.
- Include a source-file header and a Program Greeting.
- Place function prototypes above `main()` and function definitions below `main()`.
- Keep `main()` as the program coordinator; give each function one clear job.
- Do not use global variables. Constants may be local or named constants where appropriate.
- Do not use `<vector>`, `<array>`, maps, stacks, queues, or any library container or data-structure class. Build the required array and dynamic-memory structures yourself with ordinary arrays, pointers, and functions.
- The program must produce logically consistent output and must not duplicate required features merely to check a box.

## Technical Requirements: 10 Required Tasks

### Task 1: Establish a Personalized Program

Your program must:

- **1.1.** Choose one unifying theme that gives every required feature a natural purpose.
- **1.2.** Begin with a source-file header containing your name, assignment name, and a two- to three-sentence program description.
- **1.3.** Display a distinct Program Greeting at the very start of execution with your name, program title or theme, and a brief description.
- **1.4.** Use personalized prompts, variable names, function names, and output wording connected to your theme.
- **1.5.** Keep all required elements integrated into one meaningful program rather than presenting unrelated demonstrations.

### Task 2: Build a Validated Numeric Menu

Your program must:

- **2.1.** Display a numeric menu with at least three meaningful action choices and a separate quit choice.
- **2.2.** Store the user’s menu choice in an integer variable.
- **2.3.** Accept only valid menu options.
- **2.4.** Display a helpful error message when the choice is invalid.
- **2.5.** Re-prompt until the user enters a valid menu option.

### Task 3: Create and Use a One-Dimensional Array

Your program must:

- **3.1.** Declare a built-in one-dimensional array with a theme-appropriate data type.
- **3.2.** Store at least five related values in the array.
- **3.3.** Use an index-based loop to visit the array elements.
- **3.4.** Use the array in at least one meaningful calculation, search, comparison, or report.
- **3.5.** Display a labeled result that shows what the array processing means in your theme.

### Task 4: Collect and Validate Program Input

Your program must:

- **4.1.** Prompt the user for at least two kinds of program input.
- **4.2.** Validate a numeric or otherwise restricted input before using it.
- **4.3.** Check at least two theme-appropriate error conditions.
- **4.4.** Display a specific message for each rejected condition.
- **4.5.** Re-prompt until the input passes the required checks.

### Task 5: Use Function Overloading

Your program must:

- **5.1.** Create at least two functions with the same name.
- **5.2.** Make the overloaded functions differ by parameter type, parameter count, or both.
- **5.3.** Make both overloads perform related operations in the chosen theme.
- **5.4.** Call both overloaded versions from the running program.
- **5.5.** Give each overload a clear contract and a useful name shared by both versions.

### Task 6: Display a Bordered Results Table

Your program must:

- **6.1.** Display processed information in a table or report with a visible top border and bottom border.
- **6.2.** Include a visible left border and right border.
- **6.3.** Include labeled headings or categories.
- **6.4.** Use `setw` or another formatting technique to align the content.
- **6.5.** Display at least three meaningful values or rows connected to the theme.

### Task 7: Ask Whether to Run Again

Your program must:

- **7.1.** Display the completed bordered results before asking whether to run again.
- **7.2.** Prompt the user for a clearly defined yes/no or numeric repeat choice.
- **7.3.** Validate the repeat response.
- **7.4.** Repeat the appropriate program process when the user chooses another run.
- **7.5.** End cleanly when the user chooses to quit.

### Task 8: Manage Dynamic Memory with a Pointer

Your program must:

- **8.1.** Allocate dynamic memory with a pointer using `new`.
- **8.2.** Store theme-appropriate values in the dynamically allocated memory.
- **8.3.** Access the dynamic data through the pointer.
- **8.4.** Use the dynamic data in a meaningful operation or displayed result.
- **8.5.** Release the memory with the matching `delete` or `delete[]` when finished.

### Task 9: Create a Singleton-Style Random Number Function

Your program must:

- **9.1.** Create a programmer-defined function that returns a random number appropriate to the theme.
- **9.2.** Place initialization code inside that function so it runs only on the first call.
- **9.3.** Use a static local variable or equivalent function-local state to remember initialization.
- **9.4.** Call the function more than once during program execution.
- **9.5.** Make later calls return random values without repeating the initialization step.

### Task 10: Organize the Program Safely

Your program must:

- **10.1.** Create helper functions for the menu actions; the quit choice does not need a helper function.
- **10.2.** Keep data local and pass it through parameters and return values.
- **10.3.** Avoid `<vector>`, `<array>`, maps, stacks, queues, and similar library data structures.
- **10.4.** Add only theme-appropriate features from material covered in the most recent week of class.
- **10.5.** Test the program with realistic input, invalid input, repeated runs, and memory cleanup.
