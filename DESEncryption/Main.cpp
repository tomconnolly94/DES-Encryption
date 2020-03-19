// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "DESEncryptionEngine.h"
#include "FIleInterface.h"

int main(int argc, char* argv[]) {

    DESEncryptionEngine desEncryptionEngine;
    std::string encryptionKey = "dhysjfmx"; //must be 8 characters long
    char encryptedExtension[] = ".encrypted";

    for (int argIndex = 1; argIndex < argc; ++argIndex) {

        char* file = argv[argIndex];
        std::string fileContent = FileInterface::ReadFileAsBits(file);
        std::string output = desEncryptionEngine.RunEncryptionEngine(encryptionKey, fileContent);
        FileInterface::WriteBitsToFile(output, file);
        
        std::string fileString(file);
        std::string extensionString(encryptedExtension);

        std::size_t found = fileString.find(extensionString);
        std::string newFileName;

        if (found != std::string::npos) {
            newFileName = fileString.substr(0, fileString.size() - extensionString.size());
        }
        else{
            newFileName = fileString + extensionString;
        }

        const char* newFileNamePointer = newFileName.c_str();

        std::rename(file, newFileNamePointer);
    }


    return 0;
}