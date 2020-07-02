* This project uses [SFML](https://www.sfml-dev.org/) library

* The gif files are recorded using [ScreenToGif](https://www.screentogif.com/)

# TO COMPILE THE CODE
 * To compile the code ,
    1. Go this [link to SFML website](https://www.sfml-dev.org/download/sfml/2.5.1/) and download the SFML library according to your compiler.
    * For Example(Not recommended),
        I use mingw compiler with i686 archictecture (x84 or 32 bit).
        1. copy the files in sfml/bin folder to $(this_repo)/bin folder
        2. copy the files in sfml/include to $(this_repo)/resources/library/include
        3. copy the files in sfml/lib to $(this_repo)/resources/library/lib
        ![example_for_MINGW.gif](resources/Videos/example_for_MINGW.gif)
        or 
        (Recommended)
    * We recommend you to compile SFML yourselves.
        1. First you need to download CMake
        Just follow the default installer
        2. Then go to this [link to SFML website](https://www.sfml-dev.org/download/sfml/2.5.1/) and download the SFML library source code (in All section).
        3. Extract the zip folder.
        4. Open CMake and do the following:
            1. Use browse code and select the 'SFML-2.5.1' folder.
            2. Use browse build and create a 'build' folder inside the 'SFML-2.5.1' folder and choose the 'build' folder.
            3. Click 'configure' and choose option 'MinGW Makefiles' and click 'finish'.
            4. After you see a text highlighted in red in middle section and "Configuration done" in the bottom section press 'Configure' again and then 'Generate'.
        5. Open terminal in the build folder and type in terminal: 
            mingw32-make
        6. Once make process is completed open 'lib' in 'build' and copy the bottom five files all starting with sfml:
            sfml-audio-2.dll
            sfml-graphics-2.dll
            sfml-network-2.dll
            sfml-system-2.dll
            sfml-window-2.dll
        and paste it in First_project\bin
            Check that the following file are there after the process ends
                resources -(folder)
                sfml-audio-2.dll
                sfml-graphics-2.dll
                sfml-network-2.dll
                sfml-system-2.dll
                sfml-window-2.dll
        7. Go back to ~\SFML-2.5.1\BUILD and copy 'lib' folder to '~\First_project\resources\library' and paste or replace the 'lib' folder
           Go inside 'lib' and delete these:
            sfml-audio-2.dll
            sfml-graphics-2.dll
            sfml-network-2.dll
            sfml-system-2.dll
            sfml-window-2.dll
        8. Go back to ~\SFML-2.5.1 and copy 'include' folder to '~\First_project\resources\library' and paste or replace the 'include' folder
        9. Go to '~\SFML-2.5.1\extlibs\bin' and according to your compiler version go into either 'x86' or 'x64' and copy 'openal32.dll' into '~\First_project\bin'


         

    2. Once all the files are in place, compile the story.cpp file with the following command. `g++ -std=c++17 story.cpp -lsfml-system -lsfml-audio -I"resources/library/include" -L"resources/library/lib" -o ./bin/game`
     or by using the commands compile.bat and run.bat
    3. The executable file will be created in bin folder.
    4. double click on the executable to run the game.
    
# TODO:
 * Main menu integration
 * Include Animation
 * Some bug fixes 