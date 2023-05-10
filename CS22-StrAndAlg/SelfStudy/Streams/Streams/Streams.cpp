// Streams.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

int main()
{
    // Create and open file. Add text to file. Close.
    std::string message = "I am a large pink rhinocerous with a too-too.\n to-to \n tu-tu \n tooh-tooh";
    std::ofstream rhinoFile("RhinoFile.txt");
    rhinoFile << message << std::endl;
    rhinoFile.close();

    // Re-open file. Add new text to file. Close.
    std::string newMessage = "\n\n\n\n ... You should get that looked at.";
    rhinoFile.open("RhinoFile.txt", std::ios::app);
    rhinoFile << newMessage << std::endl;
    rhinoFile.close();

    // Open file. Read in data. Output data to console.
    std::ifstream inputStreamRhino("RhinoFile.txt");
    if (!inputStreamRhino)
        std::cout << "\nWAAAAAAAh. File did not open?" << std::flush;
    std::string messageFromFile = "";
    while (!inputStreamRhino.eof())
    {
        std::getline(inputStreamRhino, messageFromFile); 
        // getline overwrites the string each call so we have to copy its information 
            // down now befor it gets overwritten on the next getline call
        std::cout << messageFromFile;
        /* new line character is not included when stream is read into string with getline()
            adding it in manually. Since the getline() terminates at the \n, we can add
            a new line character to the end of our std::cout. Alternatively, we can check for
                if (!inputStreamRhino.eof() && !inputStreamRhino.failbit) 
        */
        std::cout << "\n";
    }
    std::cout << std::flush;
    inputStreamRhino.close();


}

