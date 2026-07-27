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

    // Prevent accidental copying (Rule of Three safety)
    SmartSensorFilter(const SmartSensorFilter&) = delete;
    SmartSensorFilter& operator=(const SmartSensorFilter&) = delete;

  public:
    SmartSensorFilter(int windowSize = 10);
    ~SmartSensorFilter();
    void begin();
    int update(int rawValue);
};

#endif
