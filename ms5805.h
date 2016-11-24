/**
 * \file ms5805.h
 *
 * \brief MS5805 Temperature sensor driver header file
 *
 * Copyright (c) 2016 Measurement Specialties. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 *
 * \asf_license_stop
 *
 */

#ifndef MS5805_H_INCLUDED
#define MS5805_H_INCLUDED

#include <stdint.h>
#include <stdbool.h>
#include <math.h>

enum ms5805_resolution_osr {
	ms5805_resolution_osr_256 = 0,
	ms5805_resolution_osr_512,
	ms5805_resolution_osr_1024,
	ms5805_resolution_osr_2048,
	ms5805_resolution_osr_4096,
	ms5805_resolution_osr_8192
};

enum ms5805_status {
	ms5805_status_ok,
	ms5805_status_no_i2c_acknowledge,
	ms5805_status_i2c_transfer_error,
	ms5805_status_crc_error
};
	
// Functions

/**
 * \brief Configures the SERCOM I2C master to be used with the ms5805 device.
 */
void ms5805_init(void);

/**
 * \brief Check whether MS5805 device is connected
 *
 * \return bool : status of MS5805
 *       - true : Device is present
 *       - false : Device is not acknowledging I2C address
  */
bool ms5805_is_connected(void);

/**
 * \brief Reset the MS5805 device
 *
 * \return ms5805_status : status of MS5805
 *       - ms5805_status_ok : I2C transfer completed successfully
 *       - ms5805_status_i2c_transfer_error : Problem with i2c transfer
 *       - ms5805_status_no_i2c_acknowledge : I2C did not acknowledge
 */
enum ms5805_status ms5805_reset(void);

/**
 * \brief Set  ADC resolution.
 *
 * \param[in] ms5805_resolution_osr : Resolution requested
 *
 */
void ms5805_set_resolution(enum ms5805_resolution_osr );

/**
 * \brief Reads the temperature and pressure ADC value and compute the compensated values.
 *
 * \param[out] float* : Celsius Degree temperature value
 * \param[out] float* : mbar pressure value
 *
 * \return ms5805_status : status of MS5805
 *       - ms5805_status_ok : I2C transfer completed successfully
 *       - ms5805_status_i2c_transfer_error : Problem with i2c transfer
 *       - ms5805_status_no_i2c_acknowledge : I2C did not acknowledge
 *       - ms5805_status_crc_error : CRC check error on on the PROM coefficients
 */
enum ms5805_status ms5805_read_temperature_and_pressure(float *, float *);

#endif /* MS5805_H_INCLUDED */