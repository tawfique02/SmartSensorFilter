#include "SmartSensorFilter.h"

SmartSensorFilter::SmartSensorFilter(int windowSize) {
  _windowSize = windowSize;
  _readings = new int[_windowSize];
  _readIndex = 0;
  _total = 0;
  _average = 0;
}

SmartSensorFilter::~SmartSensorFilter() {
  delete[] _readings;
}

void SmartSensorFilter::begin() {
  for (int i = 0; i < _windowSize; i++) {
    _readings[i] = 0;
  }
}

int SmartSensorFilter::update(int rawValue) {
  _total = _total - _readings[_readIndex];
  _readings[_readIndex] = rawValue;
  _total = _total + _readings[_readIndex];
  _readIndex = _readIndex + 1;

  if (_readIndex >= _windowSize) {
    _readIndex = 0;
  }

  _average = _total / _windowSize;
  return _average;
}
