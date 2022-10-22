#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<uint8_t> encrypt(vector<uint8_t> message, vector<uint8_t> key)
{
    if (message.size() != key.size())
    {
        return {};
    }
    vector<uint8_t> encrypted;
    for (int i = 0; i < message.size(); i++)
    {
        encrypted.push_back(message[i] ^ key[i]);
    }
    return encrypted;
}

vector<uint8_t> decrypt(vector<uint8_t> message, vector<uint8_t> key)
{
    if (message.size() != key.size())
    {
        return {};
    }
    vector<uint8_t> decrypted;
    for (int i = 0; i < message.size(); i++)
    {
        decrypted.push_back(message[i] ^ key[i]);
    }
    return decrypted;
}

vector<uint8_t> get_key(vector<uint8_t> message, vector<uint8_t> crypt)
{
    if (message.size() != crypt.size())
    {
        return {};
    }
    vector<uint8_t> key;
    for (int i = 0; i < message.size(); i++)
    {
        key.push_back(message[i] ^ crypt[i]);
    }
    return key;
}

void print_bytes(vector<uint8_t> message)
{
    for (const auto &e : message)
    {
        cout << hex << unsigned(e) << " ";
    }
    cout << endl;
}

int main()
{
    vector<uint8_t> key{0x05, 0x0C, 0x17, 0x7F, 0x0E, 0x4E, 0x37, 0xD2, 0x94, 0x10, 0x09, 0x2E, 0x22, 0x57, 0xFF, 0xC8, 0x0B, 0xB2, 0x70, 0x54};
    vector<uint8_t> key2{0x05, 0x0C, 0x17, 0x7F, 0x0E, 0x4E, 0x37, 0xD2, 0x94, 0x10, 0x09, 0x2E, 0x22, 0x55, 0xF4, 0xD3, 0x07, 0xBB, 0xBC, 0x54};
    vector<uint8_t> message{0xD8, 0xF2, 0xE8, 0xF0, 0xEB, 0xE8, 0xF6, 0x20, 0x2D, 0x20, 0xC2, 0xFB, 0x20, 0xC3, 0xE5, 0xF0, 0xEE, 0xE9, 0x21, 0x21};

    vector<uint8_t> crypt = encrypt(message, key);
    cout << "Original Message: " << endl;
    print_bytes(message);
    cout << "Crypted message: " << endl;
    print_bytes(crypt);
    cout << "Original key: " << endl;
    print_bytes(key);
    cout << "Get key: " << endl;
    print_bytes(get_key(message, crypt));
    cout << "Decrypted with key2: " << endl;
    print_bytes(decrypt(crypt, key2));
    return 0;
}
