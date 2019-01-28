//
//
//
//
//


#include <iostream>
#include <cstring>
#include <chrono>
#include <ctime>
#include <iomanip>

#include "Timekeeper.h"


using namespace std;
using namespace std::chrono;


namespace sict {
    
    
    // constructor
    Timekeeper::Timekeeper()  { m_recordCount = 0; }
    
    
    void Timekeeper::start() { m_timeStart = std::chrono::steady_clock::now(); }
    
    void Timekeeper::stop() { m_timeEnd = std::chrono::steady_clock::now(); }
    
    
    std::ostream& Timekeeper::report(std::ostream& os) {
        
        os << "\nExecution Times:" << std::endl;
        
        for (size_t i = 0; i < m_recordCount; ++i) {
            os << m_records[i].m_msg
            << std::setw(6)
            << std::chrono::duration_cast<std::chrono::milliseconds>(m_records[i].m_timeDuration).count()
            << " "
            << m_records[i].m_timeUnits
            << std::endl;
        }
        
        return os;
    }
    
    
    void Timekeeper::recordEvent(const char* eventDescription) {
        
            auto timeStart = m_timeStart;
            auto timeEnd = m_timeEnd;
            
            if (m_recordCount < MAX_OBJECTS) {
                
                m_records[m_recordCount].m_msg = eventDescription;
                m_records[m_recordCount].m_timeDuration = timeEnd - timeStart;
                m_recordCount++;
            }
        
        // timeDuration = duration_cast<duration<double>>(timeEnd - timeStart);
        }
 
    
    // namespace end
}
