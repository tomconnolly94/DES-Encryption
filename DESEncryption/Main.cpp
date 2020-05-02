// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "DESEncryptionEngine.h"
#include "FileInterface.h"

int main(int argc, char* argv[]) {

    DESEncryptionEngine desEncryptionEngine;
    std::string encryptionKey = "dhysjfmx"; //must be 8 characters long
    std::string encryptedExtension = ".encrypted";

    if (argc < 2) {
        std::cout << "No file provided in the command line, please provide a file to be encrypted." << std::endl;
    }

    for (int argIndex = 1; argIndex < argc; ++argIndex) {

        char* file = argv[argIndex];

        //ensure file exists
        struct stat buffer;
        if (!(stat(file, &buffer) == 0)) {
            std::cout << "File does not exist, please enter a valid file." << std::endl;
            return 1;
        }

        bool encrypting = true;
        std::string fileString(file);
        std::size_t found = fileString.find(encryptedExtension);

        if (found != std::string::npos) {
            encrypting = false;
        }

        //read file, encrypt and write back to file
        std::string origFileContent = FileInterface::ReadFileAsBits(file);
        std::string output = desEncryptionEngine.RunEncryptionEngine(encryptionKey, origFileContent, encrypting);
        FileInterface::WriteBitsToFile(output, file);

        std::string newFileName;

        if (encrypting) {
            newFileName = fileString + encryptedExtension;
        }
        else{
            newFileName = fileString.substr(0, fileString.size() - encryptedExtension.size());
        }

        const char* newFileNamePointer = newFileName.c_str();
        std::rename(file, newFileNamePointer);
    }
    return 0;
}