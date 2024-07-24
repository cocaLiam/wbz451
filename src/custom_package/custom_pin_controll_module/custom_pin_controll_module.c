#include "custom_package/custom_package.h"
#include "definitions.h"


// 이곳은 핀에 대한 값을 설정해주는 모듈 
// 설정이되어야 할 값은 핀의 출력방향 (In이냐 OUT) / AN or Digital이냐 / 핀번호에 대한 값

static bool Pin_Status = false;
static bool Port_Status = true;

void Pin_init(void){
    Pin_mode(PB3,OUTPUT);
}

int Pin_verification(GPIO_PIN pin)
{
    if(0U<=pin && pin<30){
        return pin;
    }
    else return -1;
}

void Port_direction(GPIO_PIN pin, int mode){

    if(mode == OUTPUT){
        GPIO_PinOutputEnable(pin);
        Port_Status = false;
    }else if(mode == INPUT){
        GPIO_PinInputEnable(pin);
        Port_Status = true;
    }printf("%s Pin is %s\r\n", getPinName(pin) , getDirectionString(mode));

}

bool Pin_mode(GPIO_PIN pin, char mode){
    if(pin == -1){
        perror("Wrong Port");
        return -1;
    }
    else{
        Port_direction(pin,mode);
        return true;
    }
}


bool Pin_read(GPIO_PIN pin){
    if(GPIO_PinRead(pin) == 1){
        Pin_Status = true;
        return true;
    }else {
        Pin_Status  = false;
        return false;
    }
}

void Pin_set(GPIO_PIN pin){
    if (Port_Status == 0){
        GPIO_PinSet(pin);
    }
}

void Pin_clr(GPIO_PIN pin){
    if (Pin_read(pin) == 1){
        GPIO_PinClear(pin);
    }
}

void Pin_toggle(GPIO_PIN pin){
    if (Port_Status == 0){
        GPIO_PinToggle(pin);
    }
}

const char* getPinName(GPIO_PIN pin) {
    switch (pin) {
        case GPIO_PIN_RA0:  return "PA0";
        case GPIO_PIN_RA1:  return "PA1";
        case GPIO_PIN_RA2:  return "PA2";
        case GPIO_PIN_RA3:  return "PA3";
        case GPIO_PIN_RA4:  return "PA4";
        case GPIO_PIN_RA5:  return "PA5";
        case GPIO_PIN_RA6:  return "PA6";
        case GPIO_PIN_RA7:  return "PA7";
        case GPIO_PIN_RA8:  return "PA8";
        case GPIO_PIN_RA9:  return "PA9";
        case GPIO_PIN_RA10: return "PA10";
        case GPIO_PIN_RA11: return "PA11";
        case GPIO_PIN_RA12: return "PA12";
        case GPIO_PIN_RA13: return "PA13";
        case GPIO_PIN_RA14: return "PA14";
        case GPIO_PIN_RB0:  return "PB0";
        case GPIO_PIN_RB1:  return "PB1";
        case GPIO_PIN_RB2:  return "PB2";
        case GPIO_PIN_RB3:  return "PB3";
        case GPIO_PIN_RB4:  return "PB4";
        case GPIO_PIN_RB5:  return "PB5";
        case GPIO_PIN_RB6:  return "PB6";
        case GPIO_PIN_RB7:  return "PB7";
        case GPIO_PIN_RB8:  return "PB8";
        case GPIO_PIN_RB9:  return "PB9";
        case GPIO_PIN_RB10: return "PB10";
        case GPIO_PIN_RB11: return "PB11";
        case GPIO_PIN_RB12: return "PB12";
        case GPIO_PIN_RB13: return "PB13";
        default:            return "Unknown";
    }
}

const char* getDirectionString(int mode) {
    switch (mode) {
        case OUTPUT: return "OUTPUT";
        case INPUT:  return "INPUT";
        default:     return "Unknown";
    }
}