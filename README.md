* This project uses [SFML](https://www.sfml-dev.org/) library

* The gif files are recorded using [ScreenToGif](https://www.screentogif.com/)

# TO COMPILE THE CODE
 * To compile the code ,
    1. Go this [link](https://www.sfml-dev.org/download/sfml/2.5.1/) and download the SFML library according to your compiler.
    * For Example,
        I use mingw compiler with i686 archictecture (x84 or 32 bit).
        ![exampleForMINGW-64.gif](resources/Videos/exampleForMINGW.gif)
    2. Once all the files are in place , compile the `story.cpp` file with the following command. `g++ -std=c++17 story.cpp -lsfml-system -lsfml-audio -I"resources/externalDependencies/include" -L"resources/externalDependencies/lib" -o ./BUILD/game`
    3. The executable file will be created in BUILD folder.
    4. double click on the executable to run the game.
    
# TODO:
 * Main menu integration
 * Include Animation
 * Some bug fixes 