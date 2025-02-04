# Encryption-Decryption Tool

## Overview
This is a C++-based encryption and decryption tool that securely encrypts any file using a provided key. The encrypted file can only be decrypted with the same key, ensuring data security.

## Features
Supports all file types (text, audio, video, compressed, etc.)
XOR-based encryption for secure data transformation
File conversion steps: Binary → Hexadecimal → XOR Encryption
Header files (.h) for modularity
Separate class files for better code organization

## How It Works

### Encryption:
Convert the file into binary
Convert binary to hexadecimal
Apply XOR operation with the given key
Store the encrypted content

### Decryption:
Use the same key to reverse the process
Convert hexadecimal back to binary
Restore the original file

## Future Enhancements
Implement AES encryption for stronger security
Add GUI support for user-friendly operation
Support for multi-threading for faster processing

License
This project is open-source and available under the MIT License.

Contributions and suggestions are welcome!
