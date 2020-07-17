/***************************************************
Copyright (c) 2019 Luis Llamas
(www.luisllamas.es)
Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License
 ****************************************************/

#include <Arduino.h>
#include "BTS7960.h"

LIB_Driver_TEC::LIB_Driver_TEC(uint8_t PIN_EN, uint8_t PIN_L_PWM, uint8_t PIN_R_PWM){
	_PIN_EN = PIN_EN;
	_PIN_R_PWM = PIN_R_PWM;
	_PIN_L_PWM = PIN_L_PWM;

	pinMode(_PIN_EN, OUTPUT);
	pinMode(_PIN_R_PWM, OUTPUT);
	pinMode(_PIN_L_PWM, OUTPUT);

	digitalWrite(_PIN_EN, LOW);
	analogWrite(_PIN_R_PWM, 0);
	analogWrite(_PIN_L_PWM, 0);
}

void LIB_Driver_TEC::HeatingCooling(uint8_t heating_or_cooling, uint8_t persen_pwm){
	uint8_t _pwm = persen_pwm*255/100;
	if(heating_or_cooling){
		analogWrite(_PIN_L_PWM, 0);
		// delayMicroseconds(100);
		analogWrite(_PIN_R_PWM, _pwm);
	}
	else{
		analogWrite(_PIN_R_PWM, 0);
		// delayMicroseconds(100);
		analogWrite(_PIN_L_PWM, _pwm);
	}
}

void LIB_Driver_TEC::Enable(){
	digitalWrite(_PIN_EN, HIGH);
	analogWrite(_PIN_L_PWM, 0);
	analogWrite(_PIN_R_PWM, 0);
}

void LIB_Driver_TEC::Disable(){
	digitalWrite(_PIN_EN, LOW);
	analogWrite(_PIN_L_PWM, 0);
	analogWrite(_PIN_R_PWM, 0);
}