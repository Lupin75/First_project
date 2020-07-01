* This project uses [SFML](https://www.sfml-dev.org/) library

* The gif files are recorded using [ScreenToGif](https://www.screentogif.com/)

# TO COMPILE THE CODE
 * To compile the code ,
    1. Go this [link to SFML website](https://www.sfml-dev.org/download/sfml/2.5.1/) and download the SFML library according to your compiler.
    * For Example,
        I use mingw compiler with i686 archictecture (x84 or 32 bit).
        1. copy the files in sfml/bin folder to $(this_repo)/bin folder
        2. copy the files in sfml/include to $(this_repo)/resources/library/include
        3. copy the files in sfml/lib to $(this_repo)/resources/library/lib
![example_for_MINGW.gif](resources/Videos/example_for_MINGW.gif)
    2. Once all the files are in place, compile the story.cpp file with the following command. `g++ -std=c++17 story.cpp -lsfml-system -lsfml-audio -I"resources/library/include" -L"resources/library/lib" -o ./bin/game`
    3. The executable file will be created in bin folder.
    4. double click on the executable to run the game.
    
# TODO:
 * Main menu integration
 * Include Animation
 * Some bug fixes 