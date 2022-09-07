/*
 * TLV320AIC23B Stereo Audio CODEC I2C Driver
 *
 * Patrick Dunleavy | 7/13/2022
 *
 */

#ifndef TLV320AIC23B_I2C_DRIVER_H
#define TLV320AIC23B_I2C_DRIVER_H

#include "stm32f4xx_hal.h" // Uses STM32CubeIDE I2C HAL

#define TLV320AIC23B_I2C_ADDR_0		(0x1A << 1)  // If /CS pin = 0
#define TLV320AIC23B_I2C_ADDR_1		(0x1B << 1)  // If /CS pin = 1

// Registers
#define TLV320AIC23B_REG_LLINE_VOLCTRL			0x00
#define TLV320AIC23B_REG_RLINE_VOLCTRL			0x01
#define TLV320AIC23B_REG_LHP_VOLCTRL			0x02
#define TLV320AIC23B_REG_RHP_VOLCTRL			0x03
#define TLV320AIC23B_REG_ANALOG_PATHCTRL		0x04
#define TLV320AIC23B_REG_DIGI_PATHCTRL			0x05
#define TLV320AIC23B_REG_PWRDOWN_CTRL			0x06
#define TLV320AIC23B_REG_DIGI_INTERFACE_FORMAT	0x07
#define TLV320AIC23B_REG_SAMP_RATE_CTRL			0x08
#define TLV320AIC23B_REG_DIGI_INTERFACE_ACTIV	0x09
#define TLV320AIC23B_REG_RESET					0x0F

// Struct
typedef struct {
	I2C_HandleTypeDef *i2cHandle;

	} TLV320AIC23B;

// Function Declarations
void TLV320AIC23B_init(TLV320AIC23B *dev, I2C_HandleTypeDef *i2cHandle);
void TLV320AIC23B_write(TLV320AIC23B *dev, uint8_t address, uint8_t reg, uint16_t data);

#endif
