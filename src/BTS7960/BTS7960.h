#ifndef LIB_Driver_TEC_h
#define LIB_Driver_TEC_h

class LIB_Driver_TEC
{
  public:
	  //LIB_Driver_TEC(uint8_t EN, uint8_t L_PWM, uint8_t R_PWM) : LIB_Driver_TEC(EN, 0, L_PWM, R_PWM) {}
    LIB_Driver_TEC(uint8_t PIN_EN, uint8_t PIN_L_PWM, uint8_t PIN_R_PWM);
    void HeatingCooling(uint8_t heating_or_cooling, uint8_t persen_pwm);
    void Enable();
    void Disable();

  private:
    uint8_t _PIN_EN;
    uint8_t _PIN_L_PWM;
    uint8_t _PIN_R_PWM;
};
#endif
