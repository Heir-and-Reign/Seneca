//
//
//
//
//

#ifndef SICT_TEXT_H
#define SICT_TEXT_H


namespace sict {


    class Text {
    
        std::string* m_str;
        size_t m_nStr;
    
    public:
    
        Text();
        Text(std::string fileName);
        Text(const Text& l_str);
        Text(Text&& r_str);
        Text& operator=(const Text& l_str);
        Text& operator=(Text&& r_str);
        size_t size() const;
        void clearStr();
        ~Text();
        
    // class end
    };

// namespace end
}


#endif


