#ifndef __SHT40_REGISTER_H_
#define __SHT40_REGISTER_H_

///////////////////////////////////////////////////////////
//
// �ļ����ܣ�SHT40��ؼĴ���������
// �汾��V1.0
// ���ߣ�īε��MW��
// �޸�ʱ�䣺2024/08/03
//
///////////////////////////////////////////////////////////

/* SHT40������ַ */
#define SHT40_Address					0x44
#define SHT40_Write						SHT40_Address << 1
#define SHT40_Read						(SHT40_Address << 1) | 0x01

/* ��ʪ�Ȳ�������/��/�;��ȣ� */
#define SHT40_HP_Measure			0xFD
#define SHT40_MP_Measure			0xF6
#define SHT40_LP_Measue				0xE0

/* ��ȡ���к� */
#define SHT40_SerialNumber		0x89

/* �����λ */
#define SHT40_SoftReset				0x94

/* ��������������һ������ʾmW���ڶ�����/10��ʾ����ʱ���룩 */
#define SHT40_Heater_200_10		0x39
#define SHT40_Heater_200_1		0x32
#define SHT40_Heater_110_10		0x2F
#define SHT40_Heater_110_1		0x24
#define SHT40_Heater_20_10		0x1E
#define SHT40_Heater_20_1			0x15

#endif
