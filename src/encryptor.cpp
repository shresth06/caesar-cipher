#include <iostream>
#include <cctype>
#include <string>

char shiftChar(char c, int key);
std::string encrypt(std::string text, int key);

int main()
{
    std::string plaintext;
    int key;

    // Get the plaintext input from the user
    std::cout << "Enter the plaintext: ";
    std::getline(std::cin, plaintext);

    // Get the key (shift amount) from the user
    std::cout << "Enter the key (shift amount): ";
    std::cin >> key;

    // Encrypt the plaintext
    std::string ciphertext = encrypt(plaintext, key);

    // Display the encrypted text
    std::cout << "Encrypted text: " << ciphertext << std::endl;

    return 0;
}

// Function to shift a character by a specified key
char shiftChar(char c, int key)
{
    // Do not shift non-alphabetic characters
    if (!isalpha(c))
    {
        return c;
    }

    // Handle upper and lower case characters separately
    if (isupper(c))
    {
        // Shift uppercase character within the range of 'A' to 'Z'
        return (char)(((c - 'A' + key) % 26 + 26) % 26 + 'A');
    }
    else
    {
        // Shift lowercase character within the range of 'a' to 'z'
        return (char)(((c - 'a' + key) % 26 + 26) % 26 + 'a');
    }
}

// Function to encrypt a given text using a Caesar cipher with the specified key
std::string encrypt(std::string text, int key)
{
    std::string cipherText;

    // Iterate through each character in the input text
    for (char c : text)
    {
        // Shift the character and append it to the encrypted text
        cipherText += shiftChar(c, key);
    }

    return cipherText;
}
