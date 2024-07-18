
#ifndef CUSTOM_MODULES_H
#define CUSTOM_MODULES_H

#define INPUT 0
#define OUTPUT 1

bool pinMode(GPIO_PIN pin, int mode);
void InOutChange(GPIO_PIN pin, int mode);
bool pinSet(GPIO_PIN pin);
bool pinClear(GPIO_PIN pin);

#endif // CUSTOM_MODULES_H
