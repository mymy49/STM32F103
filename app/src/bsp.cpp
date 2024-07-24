/*
 * Copyright (c) 2023 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <bsp.h>
#include <yss/instance.h>

void initializeBoard(void)
{
	using namespace define::gpio;

	// USART3 초기화
	gpioB.setAsAltFunc(10, altfunc::PB10_USART3_TX);
	// STM32F1 시리즈는 UART의 RX를 Alternate Function으로 설정하면 안됨

	usart3.enableClock();
	usart3.initialize(115200, 128);
	usart3.enableInterrupt();

	// UART4 초기화
	gpioC.setAsAltFunc(10, altfunc::PC10_UART4_TX);
	// STM32F1 시리즈는 UART의 RX를 Alternate Function으로 설정하면 안됨

	uart4.enableClock();
	uart4.initialize(115200, 128);
	uart4.enableInterrupt();

	// ADC 초기화
	using namespace define::adc;

	gpioA.setAsAnalog(3);

	adc1.enableClock();
	adc1.initialize();
	adc1.add(3, lpfLv::LV12, bit::BIT16);
	adc1.enableInterrupt();
}

