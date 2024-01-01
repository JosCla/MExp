# MExp
MExp is a simplified calculator remake of [A Monster's Expedition](https://www.monsterexpedition.com/), an open-world puzzling adventure by Draknek & Friends. Push, roll, and tumble logs to traverse the world and navigate from puzzle to puzzle!

## Building the Project
Send all .8xp files from the **src** folder to your calculator, then open the [Axe Parser Compiler](https://www.ticalc.org/archives/files/fileinfo/456/45659.html), and compile MEXP to an Application.

## Repository Information
The main folders hold the following:
- **doc**: General documentation for the game. The top-level text files are commented versions of the game's source code files.
    - **format**: Describes the game's memory layout.
    - **functionality-guides**: Guides on how a few of the game's more complicated systems function.
- **src**: The actual source files for the game, for editing on the calculator.
- **test**: Unit tests to ensure the code's correct functioning.
    - Each folder contains one test. To run the test, send the .8xp file and MEXPWORL.8xv from the test folder to the calculator, compile the .8xp file to an Application, and run the TEST Application.
        - A '1' represents a passing test, and a '0' represents a failing test.
        - See the .txt file in the test folder for details on what each test is testing.
- **maps**: The game's maps.
    - All of MExp's main maps can be found in **final**.
    - Want to create your own maps? See [MExpMapper](https://github.com/JosCla/MExpMapper) for a simple mapping tool on your calculator.
- **screenshots**: Various screenshots of the game taken throughout development!
