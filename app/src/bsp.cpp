/*
 * Copyright (c) 2023 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <bsp.h>
#include <yss.h>

void callback_linkup(bool link);

W5100S w5100s;
WiznetSocket socket0;

void initializeBoard(void)
{
	using namespace define::gpio;

	// LED 초기화
	Led::initialize();

	// SPI2 초기화
	gpioB.setAsAltFunc(13, Gpio::PB13_SPI2_SCK, Gpio::OSPEED_FAST);
	gpioB.setAsAltFunc(14, Gpio::PB14_SPI2_MISO, Gpio::OSPEED_FAST);
	gpioB.setAsAltFunc(15, Gpio::PB15_SPI2_MOSI, Gpio::OSPEED_FAST);

	spi2.enableClock();
	spi2.initializeAsMain();
	spi2.enableInterrupt();

	// W5100S 초기화
	gpioD.setAsOutput(7);
	gpioD.setAsOutput(8);
	gpioD.setAsInput(9);

	W5100S::config_t w5100sConfig =
	{
		spi2, //drv::Spi &peri;
		{&gpioD, 8},				//config::gpio::Set RSTn;
		{&gpioD, 9},				//config::gpio::Set INTn;
		{&gpioD, 7},				//config::gpio::Set CSn;
		false,						//bool PPPoE;
		false,						//bool pingBlock;
		5000,						//unsigned short retransmissionTime;
		8,							//unsigned char retransmissionCount;
		{							//unsigned int txSocketBufferSize[4];
			W5100S::BUF_SIZE_2KB, 
			W5100S::BUF_SIZE_2KB, 
			W5100S::BUF_SIZE_2KB, 
			W5100S::BUF_SIZE_2KB
		},	
		{							//unsigned int rxSocketBufferSize[4];
			W5100S::BUF_SIZE_2KB, 
			W5100S::BUF_SIZE_2KB, 
			W5100S::BUF_SIZE_2KB, 
			W5100S::BUF_SIZE_2KB
		},	
	};
	
	w5100s.lock();
	w5100s.setCallbackLinkup(callback_linkup, 512);

	if(w5100s.initialize(w5100sConfig))
	{
		const W5100S::IpConfig ipconfig = 
		{
			{0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC},	//unsigned char macAddress[6];
			{192, 168, 0, 1},						//unsigned char gatewayAddress[4];
			{255, 255, 255, 0},						//unsigned char subnetMask[4];
			{192, 168, 0, 100}						//unsigned char ipAddress[4];
		};

		w5100s.setIpConfig(ipconfig);
	}

	w5100s.unlock();
	
	// 소켓 초기화
	socket0.lock();
	socket0.initialize(w5100s, 0, 4096);
	socket0.unlock();
}

void callback_linkup(bool link)
{

}

