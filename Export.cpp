//
// Created by desuex on 26.05.2020.
//

#include "Export.h"

void Export::openFileToSave(const std::string &filename) {
    file.open(filename, std::ofstream::out | std::ofstream::trunc);
//    file.open(filename, std::ios_base::app);
}

void Export::putTabs() {

    for (int i = 0; i < tabs; i++) {
        file << "\t";
    }
}

void Export::Close() {
    file.close();

}

void Export::writeLine(const std::string &key, const std::string &value) {
    putTabs();
    std::string str = value;
    str.erase(std::find_if(str.rbegin(), str.rend(), [](int character) {
        return '\0' != character;
    }).base(), str.end());
    file << key << "=" << str << std::endl;
}

void Export::writeLine(const std::string &key, const uint16_t &value) {
    putTabs();
    file << key << "=" << value << std::endl;
}

void Export::writeLine(const std::string &key, const uint32_t &value) {
    putTabs();
    file << key << "=" << value << std::endl;
}

void Export::writeLineHex(const std::string &key, const uint32_t &value) {
    putTabs();
    file << key << "=" << std::hex << value << std::endl;
}

void Export::writeLine(const std::string &key, float value) {
    putTabs();
    file << key << "=" << value << std::endl;
}

void Export::openObject(const std::string &name) {
    putTabs();
    file << name << " {" << std::endl;
    tabs++;
}

void Export::openObject(int num) {
    putTabs();
    file << std::dec << num << " {" << std::endl;
    tabs++;
}

void Export::closeObject() {
    if (tabs > 0) {
        tabs--;
    }
    putTabs();
    file << "}" << std::endl;

}

void Export::writeLine(const std::string &key, int value) {
    putTabs();
    file << key << "=" << std::dec << value << std::endl;
}

void Export::writeLine(const std::string &key, bool value) {
    putTabs();
    file << key << "=" << (value ? "True" : "False") << std::endl;
}
