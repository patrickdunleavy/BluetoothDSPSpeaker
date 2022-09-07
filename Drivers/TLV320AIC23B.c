/*
 * TLV320AIC23B Stereo Audio CODEC I2C Driver
 *
 * Patrick Dunleavy | 7/13/2022
 *
 */
#include "TLV320AIC23B.h"


void TLV320AIC23B_init(TLV320AIC23B *dev, I2C_HandleTypeDef *i2cHandle)
{
	// Struct Parameters
	dev->i2cHandle = i2cHandle;
	// Reset Codec
	TLV320AIC23B_write(dev, TLV320AIC23B_I2C_ADDR_0, TLV320AIC23B_REG_RESET, 0x0000);
	// Power Control | Turn Mic input off
	TLV320AIC23B_write(dev, TLV320AIC23B_I2C_ADDR_0, TLV320AIC23B_REG_PWRDOWN_CTRL, 0x0002);
	// Digital Interface | Slave mode, DAC L/R Swap off, I2S timing, 16 bit input length, I2S data format
	TLV320AIC23B_write(dev, TLV320AIC23B_I2C_ADDR_0, TLV320AIC23B_REG_DIGI_INTERFACE_FORMAT, 0x0012);
	// Left Input Line Volume | L/R Simultaneous volume update, 0dB input gain
	TLV320AIC23B_write(dev, TLV320AIC23B_I2C_ADDR_0, TLV320AIC23B_REG_LLINE_VOLCTRL, 0x0097);
	// Right Input Line Volume | R/L Simultaneous volume update, 0dB input gain
	TLV320AIC23B_write(dev, TLV320AIC23B_I2C_ADDR_0, TLV320AIC23B_REG_RLINE_VOLCTRL, 0x0097);
	// Analog Audio Path | DAC SELECT???, No bypass, Line input for ADC, Mic mute
	TLV320AIC23B_write(dev, TLV320AIC23B_I2C_ADDR_0, TLV320AIC23B_REG_ANALOG_PATHCTRL, 0x0012);
	// Digital Audio Path
	TLV320AIC23B_write(dev, TLV320AIC23B_I2C_ADDR_0, TLV320AIC23B_REG_DIGI_PATHCTRL, 0x0000);
	// Sample Rate | 48 kHz, USB mode (12 MHz clock)
	TLV320AIC23B_write(dev, TLV320AIC23B_I2C_ADDR_0, TLV320AIC23B_REG_SAMP_RATE_CTRL, 0x0001);
	// Activating Digital Interface
	TLV320AIC23B_write(dev, TLV320AIC23B_I2C_ADDR_0, TLV320AIC23B_REG_DIGI_INTERFACE_ACTIV, 0x0001);

}
void TLV320AIC23B_write(TLV320AIC23B *dev, uint8_t address, uint8_t reg, uint16_t data)
{

	uint8_t dataH = data >> 8;
	uint8_t dataL = (uint8_t) (data & 0x00FF);

	// HAL_I2C_Mem_Write(hi2c, DevAddress, MemAddress, MemAddSize, pData, Size, Timeout)
	HAL_I2C_Mem_Write(dev->i2cHandle, address, ((reg<<1) | dataH), 1, &dataL, 1, 50);
}


