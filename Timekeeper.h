//
//
//
//
//


#ifndef SICT_TIMEKEEPR_H
#define SICT_TIMEKEEPR_H


namespace sict {
    
    const int MAX_OBJECTS = 10;
    
    
    class Timekeeper {
        
        static size_t m_recordCount;
        
        std::chrono::steady_clock::time_point m_timeStart;
        std::chrono::steady_clock::time_point m_timeEnd;
        
        struct {
            
            const char* m_msg;
            const char* m_timeUnits;
        
            std::chrono::steady_clock::duration m_timeDuration;
            
        } m_records[MAX_OBJECTS];
        
    public:
        
        Timekeeper();
        void copyString();
        void clearString();
        void start();
        void stop();
        void recordEvent(const char* eventDescription);
        std::ostream& report(std::ostream& os);
        ~Timekeeper() {};
        
    };
    
// namespace end
}


#endif


