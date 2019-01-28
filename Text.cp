#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

#include "Text.h"

using namespace std;

namespace sict {
    
    Text::Text() {
    
        m_str = nullptr;
    }
    
    Text::Text(std::string filename) {
        
        std::ifstream file(filename);
        std::string temp_buffer;
        std::string temp_lineNumber;
        size_t i = 0;
        
        while(std::getline(file, temp_buffer)) { ++m_nStr; }
        
        m_str = new std::string[m_nStr];
        
        while(std::getline(file, temp_lineNumber)) { m_str[i] = temp_lineNumber; };
        
        file.close();
        
    }
    
    Text::Text(const Text& l_str) {
        
        *this = l_str;
    }
    
    
    Text::Text(Text&& r_str) {
        
        *this = std::move(r_str);
    }
    
    
    
    Text& Text::operator=(const Text& l_str) {
       
        m_str->append(*l_str.m_str);
       
        return *this;
    }

    
    
    Text& Text::operator=(Text&& r_str) {
       
            clearStr();
            m_str = r_str.m_str;
            r_str.m_str = nullptr;
        
        return *this;
    }
    
    
    std::size_t Text::size()const {
        
        // return m_str->size();
        return m_nStr;
    }
    
    void Text::clearStr() {
        
        delete [] m_str;
        m_str = nullptr;
    }
    
    
    Text::~Text() {
        
        delete [] m_str;
        m_str = nullptr;
    }
    

}

    



