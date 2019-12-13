/*
  Copyright (c) 2014-2015 Arduino LLC.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "variant.h"
#include "Arduino.h"

/*
 * Pins descriptions
 */
const PinDescription g_APinDescription[]=
{
  // 0..13 - Digital pins
  // ----------------------
  // 0/1 - SERCOM/UART (Serial1)
  { PORTB, 23, PIO_SERCOM_ALT, (PIN_ATTR_DIGITAL                             ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // RX:   SERCOM5/PAD[3]
  { PORTB, 22, PIO_SERCOM_ALT, (PIN_ATTR_DIGITAL                             ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // TX:   SERCOM5/PAD[2]

  // 2..7
  // Digital Low
  { PORTB, 10, PIO_DIGITAL,  (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER    ), No_ADC_Channel, PWM5_CH0,   TC5_CH0,      EXTERNAL_INT_10   },
  { PORTB, 11, PIO_DIGITAL,  (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER    ), No_ADC_Channel, PWM5_CH1,   TC5_CH1,      EXTERNAL_INT_11   },
  { PORTA,  7, PIO_DIGITAL,  (PIN_ATTR_DIGITAL                                ), ADC_Channel7,   NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },
  { PORTA,  5, PIO_DIGITAL,  (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER    ), ADC_Channel5,   PWM0_CH1,   TCC0_CH1,     EXTERNAL_INT_NONE },
  { PORTA,  4, PIO_DIGITAL,  (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER    ), ADC_Channel4,   PWM0_CH0,   TCC0_CH0,     EXTERNAL_INT_NONE },
  { PORTA,  6, PIO_DIGITAL,  (PIN_ATTR_DIGITAL                                ), ADC_Channel6,   NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },

  // 8..12
  // Digital High
  { PORTA, 18, PIO_DIGITAL, (PIN_ATTR_DIGITAL                                ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },
  { PORTA, 20, PIO_DIGITAL, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER_ALT), No_ADC_Channel, PWM0_CH6,   TCC0_CH6,     EXTERNAL_INT_4    },
  { PORTA, 21, PIO_DIGITAL, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER_ALT), No_ADC_Channel, PWM0_CH7,   TCC0_CH7,     EXTERNAL_INT_5    },
  { PORTA, 16, PIO_SERCOM,  (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER    ), No_ADC_Channel, PWM2_CH0,   TCC2_CH0,     EXTERNAL_INT_0    }, // MOSI: SERCOM1/PAD[0]
  { PORTA, 19, PIO_SERCOM,  (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER    ), No_ADC_Channel, PWM3_CH1,   TC3_CH1,      EXTERNAL_INT_NONE }, // MISO: SERCOM1/PAD[3]

  // 13 (LED)
  { PORTA, 17, PIO_SERCOM,  (PIN_ATTR_DIGITAL                                ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_1    }, // SCK:  SERCOM1/PAD[1]

   // 14..21 - Analog pins
  // --------------------
  { PORTA,  2, PIO_ANALOG,  (PIN_ATTR_DIGITAL|PIN_ATTR_ANALOG /*DAC*/        ), ADC_Channel0,   NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },
  { PORTB,  2, PIO_ANALOG,  (PIN_ATTR_DIGITAL                                ), ADC_Channel10,  NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_2    },
  { PORTA, 11, PIO_ANALOG,  (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER    ), ADC_Channel19,  PWM1_CH1,   TCC1_CH1,     EXTERNAL_INT_NONE },
  { PORTA, 10, PIO_ANALOG,  (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER    ), ADC_Channel18,  PWM1_CH0,   TCC1_CH0,     EXTERNAL_INT_NONE },
  
  //{ PORTA,  8, PIO_SERCOM,  (PIN_ATTR_DIGITAL                                ), ADC_Channel16,  NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NMI  }, // SDA:SERCOM0/PAD[0] CW03
  { PORTB,  8, PIO_SERCOM_ALT,  (PIN_ATTR_DIGITAL|PIN_ATTR_ANALOG            ), ADC_Channel2,   NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },
  
  { PORTB,  9, PIO_DIGITAL,  (PIN_ATTR_PWM|PIN_ATTR_TIMER                    ), ADC_Channel3,   PWM4_CH1,   TC4_CH1,      EXTERNAL_INT_9    },
  { PORTA,  9, PIO_SERCOM,  (PIN_ATTR_DIGITAL                                ), ADC_Channel17,  NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // SCL:SERCOM0/PAD[1]  
  { PORTB,  3, PIO_ANALOG,  (PIN_ATTR_DIGITAL                                ), ADC_Channel11,  NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_3    },

  /* NINA PINS */
  /*
 +------------+------------------+--------+-----------------+--------+-----------------------+---------+---------+--------+--------+----------+----------+
 | Pin number |  MKR  Board pin  |  PIN   | Notes           | Peri.A |     Peripheral B      | Perip.C | Perip.D | Peri.E | Peri.F | Periph.G | Periph.H |
 |            |                  |        |                 |   EIC  | ADC |  AC | PTC | DAC | SERCOMx | SERCOMx |  TCCx  |  TCCx  |    COM   | AC/GLCK  |
 |            |                  |        |                 |(EXTINT)|(AIN)|(AIN)|     |     | (x/PAD) | (x/PAD) | (x/WO) | (x/WO) |          |          |
 +------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 |            | WiFi SPI         |        |                 |        |     |     |     |     |         |         |        |        |          |          |
 | 22         |                  |  PA12  | NINA_MOSI       |   12   |     |     |     |     |  *2/00  |   4/00  | TCC2/0 | TCC0/6 |          | AC/CMP0  |
 | 23         |                  |  PA13  | NINA_MISO       |   13   |     |     |     |     |  *2/01  |   4/01  | TCC2/1 | TCC0/7 |          | AC/CMP1  |
 | 24         |                  |  PA14  | NINA_CS         |   14   |     |     |     |     |   2/02  |   4/02  |  TC3/0 | TCC0/4 |          | GCLK_IO0 |
 | 25         |                  |  PA15  | NINA_SCK        |   15   |     |     |     |     |  *2/03  |   4/03  |  TC3/1 | TCC0/5 |          | GCLK_IO1 |
 | 26         |                  |  PA27  | NINA_GPIO0      |  *15   |     |     |     |     |         |         |        |        |          | GCLK_IO0 |
 | 27         |                  |  PB08  | NINA_RESETN     |   08   |  02 |     | Y14 |     |         |   4/00  |  TC4/0 |        |          |          |
 | 28         |                  |  PA28  | NINA_ACK        |   01   |     |     |     |     |         |   1/01  | TCC2/1 |        |          |          |
+------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
*/
  // 22..28
  { PORTA, 12, PIO_SERCOM, (PIN_ATTR_NONE                                ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // MOSI: SERCOM4/PAD[0]
  { PORTA, 13, PIO_SERCOM, (PIN_ATTR_NONE                                ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // SCK:  SERCOM4/PAD[1]
  { PORTA, 14, PIO_DIGITAL,(PIN_ATTR_NONE                                ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // SS:   as GPIO
  { PORTA, 15, PIO_SERCOM, (PIN_ATTR_NONE                                ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // MISO: SERCOM4/PAD[3]
  { PORTA, 27, PIO_DIGITAL,(PIN_ATTR_NONE                                ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_15 },
  
  //{ PORTB,  8, PIO_SERCOM_ALT,  (PIN_ATTR_DIGITAL|PIN_ATTR_ANALOG        ), ADC_Channel2,   NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },
  { PORTA,  8, PIO_DIGITAL,(PIN_ATTR_DIGITAL                             ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // Nano-IoT
  //{ PORTA,  6, PIO_DIGITAL,(PIN_ATTR_DIGITAL                             ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // Nano-IoT
  
  { PORTA, 28, PIO_DIGITAL,(PIN_ATTR_DIGITAL                             ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },

  /* SerialNINA 29..30 */
  { PORTA, 22, PIO_SERCOM, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER    ), No_ADC_Channel, PWM4_CH0,   TC4_CH0,      EXTERNAL_INT_6    },
  { PORTA, 23, PIO_SERCOM, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER    ), No_ADC_Channel, PWM4_CH1,   TC4_CH1,      EXTERNAL_INT_7    },

  // 31..32 - USB
  // --------------------  
  { PORTA, 24, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // USB/DM
  { PORTA, 25, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // USB/DP

} ;

extern "C" {
    unsigned int PINCOUNT_fn() {
        return (sizeof(g_APinDescription) / sizeof(g_APinDescription[0]));
    }
}

const void* g_apTCInstances[TCC_INST_NUM+TC_INST_NUM]={ TCC0, TCC1, TCC2, TC3, TC4, TC5 } ;

void initVariant() {
  // NINA - SPI boot
  pinMode(NINA_GPIO0, OUTPUT);
  digitalWrite(NINA_GPIO0, HIGH);

  // disable NINA
  pinMode(NINA_RESETN, OUTPUT);
  digitalWrite(NINA_RESETN, HIGH);
}

// Multi-serial objects instantiation
SERCOM sercom0( SERCOM0 ) ;
SERCOM sercom1( SERCOM1 ) ;
SERCOM sercom2( SERCOM2 ) ;
SERCOM sercom3( SERCOM3 ) ;
SERCOM sercom4( SERCOM4 ) ;
SERCOM sercom5( SERCOM5 ) ;

Uart Serial1( &sercom5, PIN_SERIAL1_RX, PIN_SERIAL1_TX, PAD_SERIAL1_RX, PAD_SERIAL1_TX ) ;

void SERCOM5_Handler()
{
  Serial1.IrqHandler();
}

Uart Serial2(&sercom3, PIN_SERIAL2_RX, PIN_SERIAL2_TX, PAD_SERIAL2_RX, PAD_SERIAL2_TX);

void SERCOM3_Handler()
{
  Serial2.IrqHandler();
}

Uart SerialHCI(&sercom2, PIN_SERIALHCI_RX, PIN_SERIALHCI_TX, PAD_SERIALHCI_RX, PAD_SERIALHCI_TX, PIN_SERIALHCI_RTS, PIN_SERIALHCI_CTS);

void SERCOM2_Handler()
{
  SerialHCI.IrqHandler();
}
