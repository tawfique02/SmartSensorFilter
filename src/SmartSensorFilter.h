#ifndef SMART_SENSOR_FILTER_H
#define SMART_SENSOR_FILTER_H

#include <Arduino.h>

class SmartSensorFilter {
  private:
    int _windowSize;      
    int* _readings;      
    int _readIndex;       
    long _total;         
    int _average;         

  public:
    SmartSensorFilter(int windowSize = 10); // Default window size = 10
    ~SmartSensorFilter();
    void begin();
    int update(int rawValue);
};

#endif
