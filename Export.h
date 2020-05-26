//
// Created by desuex on 26.05.2020.
//

#ifndef ABWORLD_EXPORT_H
#define ABWORLD_EXPORT_H

#include <string>
#include<iostream>
#include<fstream>

class Export {
private:
    std::ofstream file;
    int tabs = 0;
    void putTabs();

public:
    void openFileToSave(const std::string &filename);
    void writeLine(const std::string& key, const std::string& value);
    void writeLine(const std::string& key, int value);
    void writeLine(const std::string& key, const std::uint16_t& value);
    void writeLine(const std::string& key, const std::uint32_t& value);
    void writeLine(const std::string &key, float value);
    void writeLine(const std::string &key, bool value);
    void writeLineHex(const std::string& key, const std::uint32_t& value);
    void openObject(const std::string& name);
    void openObject(int num);
    void closeObject();
    void Close();
};


#endif //ABWORLD_EXPORT_H
