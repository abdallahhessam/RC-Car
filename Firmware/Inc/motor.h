<<<<<<< HEAD
#include "main.h"

#include "mcal.h"

struct MotorType
{
	uint8_t in1_pin{0};
	uint8_t in2_pin{0};
	uint8_t ENA_pin{0};

	GPIO_TypeDef * in1_port;
	GPIO_TypeDef * in2_port;
	GPIO_TypeDef * ENA_port;

};

MotorType motor1_config
{
	5,
	1,
	6,
	GPIOA,
	GPIOB,
	GPIOA
};

MotorType motor2_config
{
	4,
	0,
	0,
	GPIOA,
	GPIOA,
	GPIOB
};

class Motor
{
public:
	Motor(MotorType cfg) : m_cfg(cfg)
	{
//		cfg.in1_port ->CRL  =(3<<cfg.in1_pin*Bits_for_cfg);
//		cfg.in2_port ->CRL  =(3<<cfg.in2_pin*Bits_for_cfg);
//		cfg.ENA_port ->CRL |=(3<<cfg.ENA_pin*Bits_for_cfg);
//
//		cfg.in1_port ->CRL =(3<<cfg.in1_pin*Bits_for_cfg);
//		cfg.in2_port ->CRL |=(3<<cfg.in2_pin*Bits_for_cfg);
//		cfg.ENA_port ->CRL |=(3<<cfg.ENA_pin*Bits_for_cfg);

	}

	void Motor_CW()
	{
		m_cfg.in1_port->ODR |=   (1<<m_cfg.in1_pin);
		m_cfg.in2_port->ODR &=~ (1<<m_cfg.in2_pin);
		m_cfg.ENA_port->ODR |=   (1<<m_cfg.ENA_pin);
	}

	void Motor_CCW()
	{
		m_cfg.in1_port->ODR &=~ (1<<m_cfg.in1_pin);
		m_cfg.in2_port->ODR |=   (1<<m_cfg.in2_pin);
		m_cfg.ENA_port->ODR |=   (1<<m_cfg.ENA_pin);
	}

	void Motor_Stop()
	{
		m_cfg.in1_port->ODR &=~ (1<<m_cfg.in1_pin);
		m_cfg.in2_port->ODR &=~ (1<<m_cfg.in2_pin);
		m_cfg.ENA_port->ODR &=~ (1<<m_cfg.ENA_pin);
	}

	~Motor()
{
	Motor_Stop();
}

private:
	MotorType m_cfg;
};


class Robot
{
public:
	Robot(Motor m1, Motor m2) : motor1(m1), motor2(m2)
	{
		motor1.Motor_Stop();
		motor2.Motor_Stop();
	}
	void Forward()
	{
		motor1.Motor_CW();
		motor2.Motor_CCW();
	}
	void Backward()
	{
		motor1.Motor_CCW();
		motor2.Motor_CW();
	}
	void Right()
	{
		motor1.Motor_Stop();
		motor2.Motor_CCW();
	}
	void Left()
	{
		motor1.Motor_CW();
		motor2.Motor_Stop();
	}
	void Stop()
	{
		motor1.Motor_Stop();
		motor2.Motor_Stop();
	}
private:
	Motor motor1;
	Motor motor2;
};
=======
#include "main.h"

#include "mcal.h"

struct MotorType
{
	uint8_t in1_pin{0};
	uint8_t in2_pin{0};
	uint8_t ENA_pin{0};

	GPIO_TypeDef * in1_port;
	GPIO_TypeDef * in2_port;
	GPIO_TypeDef * ENA_port;

};

MotorType motor1_config
{
	5,
	1,
	6,
	GPIOA,
	GPIOB,
	GPIOA
};

MotorType motor2_config
{
	4,
	0,
	0,
	GPIOA,
	GPIOA,
	GPIOB
};

class Motor
{
public:
	Motor(MotorType cfg) : m_cfg(cfg)
	{
//		cfg.in1_port ->CRL  =(3<<cfg.in1_pin*Bits_for_cfg);
//		cfg.in2_port ->CRL  =(3<<cfg.in2_pin*Bits_for_cfg);
//		cfg.ENA_port ->CRL |=(3<<cfg.ENA_pin*Bits_for_cfg);
//
//		cfg.in1_port ->CRL =(3<<cfg.in1_pin*Bits_for_cfg);
//		cfg.in2_port ->CRL |=(3<<cfg.in2_pin*Bits_for_cfg);
//		cfg.ENA_port ->CRL |=(3<<cfg.ENA_pin*Bits_for_cfg);

	}

	void Motor_CW()
	{
		m_cfg.in1_port->ODR |=   (1<<m_cfg.in1_pin);
		m_cfg.in2_port->ODR &=~ (1<<m_cfg.in2_pin);
		m_cfg.ENA_port->ODR |=   (1<<m_cfg.ENA_pin);
	}

	void Motor_CCW()
	{
		m_cfg.in1_port->ODR &=~ (1<<m_cfg.in1_pin);
		m_cfg.in2_port->ODR |=   (1<<m_cfg.in2_pin);
		m_cfg.ENA_port->ODR |=   (1<<m_cfg.ENA_pin);
	}

	void Motor_Stop()
	{
		m_cfg.in1_port->ODR &=~ (1<<m_cfg.in1_pin);
		m_cfg.in2_port->ODR &=~ (1<<m_cfg.in2_pin);
		m_cfg.ENA_port->ODR &=~ (1<<m_cfg.ENA_pin);
	}

	~Motor()
{
	Motor_Stop();
}

private:
	MotorType m_cfg;
};


class Robot
{
public:
	Robot(Motor m1, Motor m2) : motor1(m1), motor2(m2)
	{
		motor1.Motor_Stop();
		motor2.Motor_Stop();
	}
	void Forward()
	{
		motor1.Motor_CW();
		motor2.Motor_CCW();
	}
	void Backward()
	{
		motor1.Motor_CCW();
		motor2.Motor_CW();
	}
	void Right()
	{
		motor1.Motor_Stop();
		motor2.Motor_CCW();
	}
	void Left()
	{
		motor1.Motor_CW();
		motor2.Motor_Stop();
	}
	void Stop()
	{
		motor1.Motor_Stop();
		motor2.Motor_Stop();
	}
private:
	Motor motor1;
	Motor motor2;
};
>>>>>>> 6b07dd5acb39c3e809ce7cee44e40f5818a90db6
