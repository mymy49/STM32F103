/*
 * Copyright (c) 2023 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_CONFIG__H_
#define YSS_CONFIG__H_

// ####################### 외부 크리스탈 클럭 주파수 설정 #######################
// 아래 HSE_CLOCK_FREQ가 정의 되어 있으면 HSE 클럭을 소스로 PLL 설정이 이뤄집니다.
// 정의되어 있지 않으면 HSI 클럭을 소스로 PLL 설정이 이뤄집니다.
//#define HSE_CLOCK_FREQ 8000000

// ####################### 스케줄러 설정 #######################
// runtime 함수를 지원할 PWM 장치 설정 (RUNTIME_TIM2 ~ RUNTIME_TIM14)
// RUNTIME_TIM1, RUNTIME_TIM6, RUNTIME_TIM7, RUNTIME_TIM8, RUNTIME_TIM10, RUNTIME_TIM13은 사용이 불가능 합니다.
#define YSS_TIMER			RUNTIME_TIM2

// 쓰레드당 할당 받는 Systick Clock의 수
#define THREAD_GIVEN_CLOCK	20000

// 최대 등록 가능한 쓰레드의 수
#define MAX_THREAD			10

// 쓰레드의 스택을 0xAA 패턴으로 채우기 (true, false)
#define FILL_THREAD_STACK	false

// ####################### GUI 설정 #######################
// GUI library Enable (true, false)
#define USE_GUI				false

// ####################### KEY 설정 #######################
// 최대 KEY 생성 가능 갯수 설정 (0 ~ ), 0일 경우 기능 꺼짐
#define NUM_OF_YSS_KEY		0

// ###################### 주변 장치 활성화 ######################
// 활성화 시킬 장치에 대해 false -> true로 변경하여 활성화 한다.
//
// 주의 
// 1. TIMER와 PWM은 실제 동일한 장치지만 OS 구조상 별도의 장치로 표현한다. 그러므로 동일한 번호의 PWM과 TIMER는 동시에 활성화 되지 못한다.

// ADC 활성화
#define ADC1_ENABLE			false
#define ADC2_ENABLE			false
#define ADC3_ENABLE			false

// CAN 활성화
#define CAN1_ENABLE			false

// CRC32 활성화
#define CRC32_ENABLE		false

// DAC 활성화
#define DAC1_ENABLE			false

// I2C 활성화
#define I2C1_ENABLE			false
#define I2C2_ENABLE			false

// I2S 활성화
#define I2S2_ENABLE			false
#define I2S3_ENABLE			false

// PWM 활성화
#define PWM1_ENABLE			false
#define PWM2_ENABLE			false
#define PWM3_ENABLE			false
#define PWM4_ENABLE			false
#define PWM5_ENABLE			false
#define PWM8_ENABLE			false

// SPI 활성화
#define SPI1_ENABLE			false
#define SPI2_ENABLE			false
#define SPI3_ENABLE			false

// TIMER 활성화
#define TIM1_ENABLE			false
#define TIM2_ENABLE			false
#define TIM3_ENABLE			false
#define TIM4_ENABLE			false
#define TIM5_ENABLE			false
#define TIM6_ENABLE			true
#define TIM7_ENABLE			false
#define TIM8_ENABLE			false

// UART 활성화
#define USART1_ENABLE		false
#define USART2_ENABLE		false
#define USART3_ENABLE		false
#define UART4_ENABLE		false
#define UART5_ENABLE		false

#endif

