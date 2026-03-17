# Recursive Dream

A C++ project demonstrating recursion, file I/O, dynamic memory management, and object-oriented programming.

## Project Structure

- `main.cpp`: Entry point. Creates a Character, loads commands, and starts the recursive dream sequence.
- `Character.h` / `CharacterImp.cpp`: Handles command loading, printing, and recursion logic.
- `Dream.h` / `DreamImp.cpp`: Manages dream levels and dynamic memory allocation.
- `commands.txt`: List of commands used by the Character.

## Features
- Reads commands from a file and prints them in reverse order.
- Demonstrates recursion with Fibonacci and file reading.
- Uses dynamic memory allocation and custom destructors.
- Clean, well-commented code for easy understanding.

## How to Build & Run

1. Compile:
   ```sh
   g++ -std=c++17 -o recursive-dream main.cpp CharacterImp.cpp DreamImp.cpp
   ```
2. Run:
   ```sh
   ./recursive-dream
   ```

## Example Output
```
The following are the commands received:
theearlybirdcatchestheworminthemorning
continuouslearningfuelscareergrowthandsuccess
complexproblemsrequireinnovativesolutions
...
Calling startDreaming() function from main..
Start of Dream level: 1
         Dynamically allocating 1 elements.
...
End of Dream level: 1
```

---

For questions or improvements, feel free to open an issue or pull request.
