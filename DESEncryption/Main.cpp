// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "DESEncryptionEngine.h"
#include "FIleInterface.h"

int main(int argc, char* argv[]) {

    DESEncryptionEngine desEncryptionEngine;
    std::string encryptionKey = "dhysjfmx"; //must be 8 characters long
    std::string encryptedExtension = ".encrypted";

    for (int argIndex = 1; argIndex < argc; ++argIndex) {

        char* file = argv[argIndex];
        bool encrypting = true;
        std::string fileString(file);
        std::size_t found = fileString.find(encryptedExtension);

        if (true || found != std::string::npos) {
            encrypting = false;
        }

        std::string fileContent = FileInterface::ReadFileAsBits(file);
        std::string output = desEncryptionEngine.RunEncryptionEngine(encryptionKey, fileContent, encrypting);
        FileInterface::WriteBitsToFile(output, file);
        

        std::string newFileName;

        if (encrypting) {
            newFileName = fileString + encryptedExtension;
        }
        else{
            newFileName = fileString.substr(0, fileString.size() - encryptedExtension.size());
        }

        const char* newFileNamePointer = newFileName.c_str();
        //std::rename(file, newFileNamePointer);
    }
    return 0;
}