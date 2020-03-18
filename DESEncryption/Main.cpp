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

        bool found = fileString.find(extensionString);
        char * newFileName = NULL;

        if (!found) {
            char subbuff[5];
            memcpy(subbuff, &file[10], 4);
            subbuff[4] = '\0';
        }
        else{
            // Determine new size
            int newSize = strlen(file) + strlen(encryptedExtension) + 1;

            // Allocate new buffer
            newFileName = (char*)malloc(newSize);

            // do the copy and concat
            strcpy_s(newFileName, strlen(file), file);
            strcat_s(newFileName, strlen(encryptedExtension), encryptedExtension); // or strncat
        }

        std::rename(file, newFileName);
    }


    return 0;
}