#ifndef __SHT40_REGISTER_H_
#define __SHT40_REGISTER_H_

///////////////////////////////////////////////////////////
//
// 文件功能：SHT40相关寄存器和命令
// 版本：V1.0
// 作者：墨蔚（MW）
// 修改时间：2024/08/03
//
///////////////////////////////////////////////////////////

/* SHT40器件地址 */
#define SHT40_Address					0x44
#define SHT40_Write						SHT40_Address << 1
#define SHT40_Read						(SHT40_Address << 1) | 0x01

/* 温湿度测量（高/中/低精度） */
#define SHT40_HP_Measure			0xFD
#define SHT40_MP_Measure			0xF6
#define SHT40_LP_Measue				0xE0

/* 读取序列号 */
#define SHT40_SerialNumber		0x89

/* 软件复位 */
#define SHT40_SoftReset				0x94

/* 开启加热器（第一个数表示mW，第二个数/10表示加热时常秒） */
#define SHT40_Heater_200_10		0x39
#define SHT40_Heater_200_1		0x32
#define SHT40_Heater_110_10		0x2F
#define SHT40_Heater_110_1		0x24
#define SHT40_Heater_20_10		0x1E
#define SHT40_Heater_20_1			0x15

#endif
