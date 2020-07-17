#include "src/BTS7960/BTS7960.h"

#define TEC_HEATING 0
#define TEC_COOLING 1
LIB_Driver_TEC _tec(11,9,10);

void setup() {
  // put your setup code here, to run once:
  _tec.Enable();
}

void loop() {
  // put your main code here, to run repeatedly:
  _tec.HeatingCooling(TEC_HEATING, 1); // (mode, percent)

}
