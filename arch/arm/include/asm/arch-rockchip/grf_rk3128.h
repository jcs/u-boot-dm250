/*
 * (C) Copyright 2017 Rockchip Electronics Co., Ltd
 *
 * SPDX-License-Identifier:     GPL-2.0+
 */
#ifndef _ASM_ARCH_GRF_RK3128_H
#define _ASM_ARCH_GRF_RK3128_H

#include <common.h>

struct rk3128_grf {
	unsigned int reserved[0x2a];
	unsigned int gpio0a_iomux;
	unsigned int gpio0b_iomux;
	unsigned int gpio0c_iomux;
	unsigned int gpio0d_iomux;
	unsigned int gpio1a_iomux;
	unsigned int gpio1b_iomux;
	unsigned int gpio1c_iomux;
	unsigned int gpio1d_iomux;
	unsigned int gpio2a_iomux;
	unsigned int gpio2b_iomux;
	unsigned int gpio2c_iomux;
	unsigned int gpio2d_iomux;
	unsigned int gpio3a_iomux;
	unsigned int gpio3b_iomux;
	unsigned int gpio3c_iomux;
	unsigned int gpio3d_iomux;
	unsigned int gpio2c_iomux2;
	unsigned int grf_cif_iomux;
	unsigned int grf_cif_iomux1;
	unsigned int reserved1[(0x118 - 0xf0) / 4 - 1];
	unsigned int gpio0l_pull;
	unsigned int gpio0h_pull;
	unsigned int gpio1l_pull;
	unsigned int gpio1h_pull;
	unsigned int gpio2l_pull;
	unsigned int gpio2h_pull;
	unsigned int gpio3l_pull;
	unsigned int gpio3h_pull;
	unsigned int reserved2;
	unsigned int soc_con0;
	unsigned int soc_con1;
	unsigned int soc_con2;
	unsigned int soc_status0;
	unsigned int reserved3[6];
	unsigned int mac_con0;
	unsigned int mac_con1;
	unsigned int reserved4[4];
	unsigned int uoc0_con0;
	unsigned int reserved5;
	unsigned int uoc1_con1;
	unsigned int uoc1_con2;
	unsigned int uoc1_con3;
	unsigned int uoc1_con4;
	unsigned int uoc1_con5;
	unsigned int reserved6;
	unsigned int ddrc_stat;
	unsigned int reserved9;
	unsigned int soc_status1;
	unsigned int cpu_con0;
	unsigned int cpu_con1;
	unsigned int cpu_con2;
	unsigned int cpu_con3;
	unsigned int reserved10;
	unsigned int reserved11;
	unsigned int cpu_status0;
	unsigned int cpu_status1;
	unsigned int os_reg[8];
	unsigned int reserved12[(0x280 - 0x1e4) / 4 - 1];
	unsigned int usbphy0_con[8];
	unsigned int usbphy1_con[8];
	unsigned int uoc_status0;
	unsigned int reserved13[(0x300 - 0x2c0) / 4 - 1];
	unsigned int chip_tag;
	unsigned int sdmmc_det_cnt;
};
check_member(rk3128_grf, sdmmc_det_cnt, 0x304);

struct rk3128_pmu {
	unsigned int wakeup_cfg;
	unsigned int pwrdn_con;
	unsigned int pwrdn_st;
	unsigned int idle_req;
	unsigned int idle_st;
	unsigned int pwrmode_con;
	unsigned int pwr_state;
	unsigned int osc_cnt;
	unsigned int core_pwrdwn_cnt;
	unsigned int core_pwrup_cnt;
	unsigned int sft_con;
	unsigned int ddr_sref_st;
	unsigned int int_con;
	unsigned int int_st;
	unsigned int sys_reg[4];
};
check_member(rk3128_pmu, int_st, 0x34);

/* GRF_GPIO0A_IOMUX */
#define GRF_GPIO0A_IOMUX	0x00a8
enum {
	GPIO0A7_SHIFT		= 14,
	GPIO0A7_MASK		= 3 << GPIO0A7_SHIFT,
	GPIO0A7_GPIO		= 0,
	GPIO0A7_I2C3_SDA,

	GPIO0A6_SHIFT		= 12,
	GPIO0A6_MASK		= 3 << GPIO0A6_SHIFT,
	GPIO0A6_GPIO		= 0,
	GPIO0A6_I2C3_SCL,

	GPIO0A3_SHIFT		= 6,
	GPIO0A3_MASK		= 3 << GPIO0A3_SHIFT,
	GPIO0A3_GPIO		= 0,
	GPIO0A3_I2C1_SDA,

	GPIO0A2_SHIFT		= 4,
	GPIO0A2_MASK		= 1 << GPIO0A2_SHIFT,
	GPIO0A2_GPIO		= 0,
	GPIO0A2_I2C1_SCL,

	GPIO0A1_SHIFT		= 2,
	GPIO0A1_MASK		= 1 << GPIO0A1_SHIFT,
	GPIO0A1_GPIO		= 0,
	GPIO0A1_I2C0_SDA,

	GPIO0A0_SHIFT		= 0,
	GPIO0A0_MASK		= 1 << GPIO0A0_SHIFT,
	GPIO0A0_GPIO		= 0,
	GPIO0A0_I2C0_SCL,
};

/* GRF_GPIO0B_IOMUX */
#define GRF_GPIO0B_IOMUX	0x00ac
enum {
	GPIO0B6_SHIFT		= 12,
	GPIO0B6_MASK		= 3 << GPIO0B6_SHIFT,
	GPIO0B6_GPIO		= 0,
	GPIO0B6_I2S_SDI,
	GPIO0B6_SPI_CSN0,

	GPIO0B5_SHIFT		= 10,
	GPIO0B5_MASK		= 3 << GPIO0B5_SHIFT,
	GPIO0B5_GPIO		= 0,
	GPIO0B5_I2S_SDO,
	GPIO0B5_SPI_RXD,

	GPIO0B4_SHIFT		= 8,
	GPIO0B4_MASK		= 1 << GPIO0B4_SHIFT,
	GPIO0B4_GPIO		= 0,
	GPIO0B4_I2S_LRCKTX,

	GPIO0B3_SHIFT		= 6,
	GPIO0B3_MASK		= 3 << GPIO0B3_SHIFT,
	GPIO0B3_GPIO		= 0,
	GPIO0B3_I2S_LRCKRX,
	GPIO0B3_SPI_TXD,

	GPIO0B1_SHIFT		= 2,
	GPIO0B1_MASK		= 3,
	GPIO0B1_GPIO		= 0,
	GPIO0B1_I2S_SCLK,
	GPIO0B1_SPI_CLK,

	GPIO0B0_SHIFT		= 0,
	GPIO0B0_MASK		= 3,
	GPIO0B0_GPIO		= 0,
	GPIO0B0_I2S1_MCLK,
};

/* GRF_GPIO0D_IOMUX */
#define GRF_GPIO0D_IOMUX	0x00b4
enum {
	GPIO0D4_SHIFT		= 8,
	GPIO0D4_MASK		= 1 << GPIO0D4_SHIFT,
	GPIO0D4_GPIO		= 0,
	GPIO0D4_PWM2,

	GPIO0D3_SHIFT		= 6,
	GPIO0D3_MASK		= 1 << GPIO0D3_SHIFT,
	GPIO0D3_GPIO		= 0,
	GPIO0D3_PWM1,

	GPIO0D2_SHIFT		= 4,
	GPIO0D2_MASK		= 1 << GPIO0D2_SHIFT,
	GPIO0D2_GPIO		= 0,
	GPIO0D2_PWM0,

	GPIO0D1_SHIFT		= 2,
	GPIO0D1_MASK		= 1 << GPIO0D1_SHIFT,
	GPIO0D1_GPIO		= 0,
	GPIO0D1_UART2_CTSN,

	GPIO0D0_SHIFT		= 0,
	GPIO0D0_MASK		= 3 << GPIO0D0_SHIFT,
	GPIO0D0_GPIO		= 0,
	GPIO0D0_UART2_RTSN,
	GPIO0D0_PMIC_SLEEP,
};

/* GRF_GPIO1A_IOMUX */
#define GRF_GPIO1A_IOMUX	0x00b8
enum {
	GPIO1A5_SHIFT		= 10,
	GPIO1A5_MASK		= 3 << GPIO1A5_SHIFT,
	GPIO1A5_GPIO		= 0,
	GPIO1A5_I2S_SDI,
	GPIO1A5_SDMMC_DATA3,

	GPIO1A4_SHIFT		= 8,
	GPIO1A4_MASK		= 3 << GPIO1A4_SHIFT,
	GPIO1A4_GPIO		= 0,
	GPIO1A4_I2S_SD0,
	GPIO1A4_SDMMC_DATA2,

	GPIO1A3_SHIFT		= 6,
	GPIO1A3_MASK		= 1 << GPIO1A3_SHIFT,
	GPIO1A3_GPIO		= 0,
	GPIO1A3_I2S_LRCKTX,

	GPIO1A2_SHIFT		= 4,
	GPIO1A2_MASK		= 3 << GPIO1A2_SHIFT,
	GPIO1A2_GPIO		= 0,
	GPIO1A2_I2S_LRCKRX,
	GPIO1A2_SDMMC_DATA1,

	GPIO1A1_SHIFT		= 2,
	GPIO1A1_MASK		= 3 << GPIO1A1_SHIFT,
	GPIO1A1_GPIO		= 0,
	GPIO1A1_I2S_SCLK,
	GPIO1A1_SDMMC_DATA0,
	GPIO1A1_PMIC_SLEEP,

	GPIO1A0_SHIFT		= 0,
	GPIO1A0_MASK		= 3,
	GPIO1A0_GPIO		= 0,
	GPIO1A0_I2S_MCLK,
	GPIO1A0_SDMMC_CLKOUT,
	GPIO1A0_XIN32K,

};

/* GRF_GPIO1B_IOMUX */
#define GRF_GPIO1B_IOMUX	0x00bc
enum {
	GPIO1B7_SHIFT		= 14,
	GPIO1B7_MASK		= 1 << GPIO1B7_SHIFT,
	GPIO1B7_GPIO		= 0,
	GPIO1B7_MMC0_CMD,

	GPIO1B6_SHIFT		= 12,
	GPIO1B6_MASK		= 1 << GPIO1B6_SHIFT,
	GPIO1B6_GPIO		= 0,
	GPIO1B6_MMC_PWREN,

	GPIO1B2_SHIFT		= 4,
	GPIO1B2_MASK		= 3 << GPIO1B2_SHIFT,
	GPIO1B2_GPIO		= 0,
	GPIO1B2_SPI_RXD,
	GPIO1B2_UART1_SIN,

	GPIO1B1_SHIFT		= 2,
	GPIO1B1_MASK		= 3 << GPIO1B1_SHIFT,
	GPIO1B1_GPIO		= 0,
	GPIO1B1_SPI_TXD,
	GPIO1B1_UART1_SOUT,

	GPIO1B0_SHIFT		= 0,
	GPIO1B0_MASK		= 3 << GPIO1B0_SHIFT,
	GPIO1B0_GPIO		= 0,
	GPIO1B0_SPI_CLK,
	GPIO1B0_UART1_CTSN
};

/* GRF_GPIO1C_IOMUX */
#define GRF_GPIO1C_IOMUX	0x00c0
enum {
	GPIO1C6_SHIFT		= 12,
	GPIO1C6_MASK		= 3 << GPIO1C6_SHIFT,
	GPIO1C6_GPIO		= 0,
	GPIO1C6_NAND_CS2,
	GPIO1C6_EMMC_CMD,

	GPIO1C5_SHIFT		= 10,
	GPIO1C5_MASK		= 3 << GPIO1C5_SHIFT,
	GPIO1C5_GPIO		= 0,
	GPIO1C5_MMC0_D3,
	GPIO1C5_JTAG_TMS,

	GPIO1C4_SHIFT		= 8,
	GPIO1C4_MASK		= 3 << GPIO1C4_SHIFT,
	GPIO1C4_GPIO		= 0,
	GPIO1C4_MMC0_D2,
	GPIO1C4_JTAG_TCK,

	GPIO1C3_SHIFT		= 6,
	GPIO1C3_MASK		= 3 << GPIO1C3_SHIFT,
	GPIO1C3_GPIO		= 0,
	GPIO1C3_MMC0_D1,
	GPIO1C3_UART2_RX,

	GPIO1C2_SHIFT		= 4,
	GPIO1C2_MASK		= 3 << GPIO1C2_SHIFT ,
	GPIO1C2_GPIO		= 0,
	GPIO1C2_MMC0_D0,
	GPIO1C2_UART2_TX,

	GPIO1C1_SHIFT		= 2,
	GPIO1C1_MASK		= 1 << GPIO1C1_SHIFT,
	GPIO1C1_GPIO		= 0,
	GPIO1C1_MMC0_DETN,

	GPIO1C0_SHIFT		= 0,
	GPIO1C0_MASK		= 1 << GPIO1C0_SHIFT,
	GPIO1C0_GPIO		= 0,
	GPIO1C0_MMC0_CLKOUT,
};

/* GRF_GPIO1D_IOMUX */
#define GRF_GPIO1D_IOMUX	0x00c4
enum {
	GPIO1D7_SHIFT		= 14,
	GPIO1D7_MASK		= 3 << GPIO1D7_SHIFT,
	GPIO1D7_GPIO		= 0,
	GPIO1D7_NAND_D7,
	GPIO1D7_EMMC_D7,
	GPIO1D7_SPI_CSN1,

	GPIO1D6_SHIFT		= 12,
	GPIO1D6_MASK		= 3 << GPIO1D6_SHIFT,
	GPIO1D6_GPIO		= 0,
	GPIO1D6_NAND_D6,
	GPIO1D6_EMMC_D6,
	GPIO1D6_SPI_CSN0,

	GPIO1D5_SHIFT		= 10,
	GPIO1D5_MASK		= 3 << GPIO1D5_SHIFT,
	GPIO1D5_GPIO		= 0,
	GPIO1D5_NAND_D5,
	GPIO1D5_EMMC_D5,
	GPIO1D5_SPI_TXD1,

	GPIO1D4_SHIFT		= 8,
	GPIO1D4_MASK		= 3 << GPIO1D4_SHIFT,
	GPIO1D4_GPIO		= 0,
	GPIO1D4_NAND_D4,
	GPIO1D4_EMMC_D4,
	GPIO1D4_SPI_RXD1,

	GPIO1D3_SHIFT		= 6,
	GPIO1D3_MASK		= 3 << GPIO1D3_SHIFT,
	GPIO1D3_GPIO		= 0,
	GPIO1D3_NAND_D3,
	GPIO1D3_EMMC_D3,
	GPIO1D3_SFC_SIO3,

	GPIO1D2_SHIFT		= 4,
	GPIO1D2_MASK		= 3 << GPIO1D2_SHIFT,
	GPIO1D2_GPIO		= 0,
	GPIO1D2_NAND_D2,
	GPIO1D2_EMMC_D2,
	GPIO1D2_SFC_SIO2,

	GPIO1D1_SHIFT		= 2,
	GPIO1D1_MASK		= 3 << GPIO1D1_SHIFT,
	GPIO1D1_GPIO		= 0,
	GPIO1D1_NAND_D1,
	GPIO1D1_EMMC_D1,
	GPIO1D1_SFC_SIO1,

	GPIO1D0_SHIFT		= 0,
	GPIO1D0_MASK		= 3 << GPIO1D0_SHIFT,
	GPIO1D0_GPIO		= 0,
	GPIO1D0_NAND_D0,
	GPIO1D0_EMMC_D0,
	GPIO1D0_SFC_SIO0,
};

/* GRF_GPIO2A_IOMUX */
#define GRF_GPIO2A_IOMUX	0x00c8
enum {
	GPIO2A7_SHIFT		= 14,
	GPIO2A7_MASK		= 3 << GPIO2A7_SHIFT,
	GPIO2A7_GPIO		= 0,
	GPIO2A7_NAND_DQS,
	GPIO2A7_EMMC_CLKOUT,

	GPIO2A6_SHIFT		= 12,
	GPIO2A6_MASK		= 1 << GPIO2A6_SHIFT,
	GPIO2A6_GPIO		= 0,
	GPIO2A6_NAND_CS0,

	GPIO2A5_SHIFT		= 10,
	GPIO2A5_MASK		= 3 << GPIO2A5_SHIFT,
	GPIO2A5_GPIO		= 0,
	GPIO2A5_NAND_WP,
	GPIO2A5_EMMC_PWREN,

	GPIO2A4_SHIFT		= 8,
	GPIO2A4_MASK		= 3 << GPIO2A4_SHIFT,
	GPIO2A4_GPIO		= 0,
	GPIO2A4_NAND_RDY,
	GPIO2A4_EMMC_CMD,
	GPIO2A3_SFC_CLK,

	GPIO2A3_SHIFT		= 6,
	GPIO2A3_MASK		= 3 << GPIO2A3_SHIFT,
	GPIO2A3_GPIO		= 0,
	GPIO2A3_NAND_RDN,
	GPIO2A4_SFC_CSN1,

	GPIO2A2_SHIFT		= 4,
	GPIO2A2_MASK		= 3 << GPIO2A2_SHIFT,
	GPIO2A2_GPIO		= 0,
	GPIO2A2_NAND_WRN,
	GPIO2A4_SFC_CSN0,

	GPIO2A1_SHIFT		= 2,
	GPIO2A1_MASK		= 3 << GPIO2A1_SHIFT,
	GPIO2A1_GPIO		= 0,
	GPIO2A1_NAND_CLE,
	GPIO2A1_EMMC_CLKOUT,

	GPIO2A0_SHIFT		= 0,
	GPIO2A0_MASK		= 3 << GPIO2A0_SHIFT,
	GPIO2A0_GPIO		= 0,
	GPIO2A0_NAND_ALE,
	GPIO2A0_SPI_CLK,
};

/* GRF_GPIO2B_IOMUX */
#define GRF_GPIO2B_IOMUX	0x00cc
enum {
	GPIO2B7_SHIFT		= 14,
	GPIO2B7_MASK		= 3 << GPIO2B7_SHIFT,
	GPIO2B7_GPIO		= 0,
	GPIO2B7_LCDC0_D13,
	GPIO2B7_EBC_SDCE5,
	GPIO2B7_GMAC_RXER,

	GPIO2B6_SHIFT		= 12,
	GPIO2B6_MASK		= 3 << GPIO2B6_SHIFT,
	GPIO2B6_GPIO		= 0,
	GPIO2B6_LCDC0_D12,
	GPIO2B6_EBC_SDCE4,
	GPIO2B6_GMAC_CLK,

	GPIO2B5_SHIFT		= 10,
	GPIO2B5_MASK		= 3 << GPIO2B5_SHIFT,
	GPIO2B5_GPIO		= 0,
	GPIO2B5_LCDC0_D11,
	GPIO2B5_EBC_SDCE3,
	GPIO2B5_GMAC_TXEN,

	GPIO2B4_SHIFT		= 8,
	GPIO2B4_MASK		= 3 << GPIO2B4_SHIFT,
	GPIO2B4_GPIO		= 0,
	GPIO2B4_LCDC0_D10,
	GPIO2B4_EBC_SDCE2,
	GPIO2B4_GMAC_MDIO,

	GPIO2B3_SHIFT		= 6,
	GPIO2B3_MASK		= 3 << GPIO2B3_SHIFT,
	GPIO2B3_GPIO		= 0,
	GPIO2B3_LCDC0_DEN,
	GPIO2B3_EBC_GDCLK,
	GPIO2B3_GMAC_RXCLK,

	GPIO2B2_SHIFT		= 4,
	GPIO2B2_MASK		= 3 << GPIO2B2_SHIFT,
	GPIO2B2_GPIO		= 0,
	GPIO2B2_LCDC0_VSYNC,
	GPIO2B2_EBC_SDOE,
	GPIO2B2_GMAC_CRS,

	GPIO2B1_SHIFT		= 2,
	GPIO2B1_MASK		= 3 << GPIO2B1_SHIFT,
	GPIO2B1_GPIO		= 0,
	GPIO2B1_LCDC0_HSYNC,
	GPIO2B1_EBC_SDLE,
	GPIO2B1_GMAC_TXCLK,

	GPIO2B0_SHIFT		= 0,
	GPIO2B0_MASK		= 3 << GPIO2B0_SHIFT,
	GPIO2B0_GPIO		= 0,
	GPIO2B0_LCDC0_DCLK,
	GPIO2B0_EBC_SDCLK,
	GPIO2B0_GMAC_RXDV,
};

/* GRF_GPIO2C_IOMUX */
#define GRF_GPIO2C_IOMUX	0x00d0
enum {
	GPIO2C3_SHIFT		= 6,
	GPIO2C3_MASK		= 3 << GPIO2C3_SHIFT,
	GPIO2C3_GPIO		= 0,
	GPIO2C3_LCDC0_D17,
	GPIO2C3_EBC_GDPWR0,
	GPIO2C3_GMAC_TXD0,

	GPIO2C2_SHIFT		= 4,
	GPIO2C2_MASK		= 3 << GPIO2C2_SHIFT,
	GPIO2C2_GPIO		= 0,
	GPIO2C2_LCDC0_D16,
	GPIO2C2_EBC_GDSP,
	GPIO2C2_GMAC_TXD1,

	GPIO2C1_SHIFT		= 2,
	GPIO2C1_MASK		= 3 << GPIO2C1_SHIFT,
	GPIO2C1_GPIO		= 0,
	GPIO2C1_LCDC0_D15,
	GPIO2C1_EBC_GDOE,
	GPIO2C1_GMAC_RXD0,

	GPIO2C0_SHIFT		= 0,
	GPIO2C0_MASK		= 3 << GPIO2C0_SHIFT,
	GPIO2C0_GPIO		= 0,
	GPIO2C0_LCDC0_D14,
	GPIO2C0_EBC_VCOM,
	GPIO2C0_GMAC_RXD1,
};

/* GRF_GPIO2D_IOMUX */
#define GRF_GPIO2D_IOMUX	0x00d4
enum {
	GPIO2D6_SHIFT		= 12,
	GPIO2D6_MASK		= 3 << GPIO2D6_SHIFT,
	GPIO2D6_GPIO		= 0,
	GPIO2D6_LCDC0_D22,
	GPIO2D6_GMAC_COL	= 4,

	GPIO2D1_SHIFT		= 2,
	GPIO2D1_MASK		= 3 << GPIO2D1_SHIFT,
	GPIO2D1_GPIO		= 0,
	GPIO2D1_GMAC_MDC	= 3,
};

/* GRF_GPIO2C_IOMUX2 */
#define GRF_GPIO2C_IOMUX2	0x00e8
enum {
	GPIO2C7_SHIFT		= 12,
	GPIO2C7_MASK		= 7 << GPIO2C7_SHIFT,
	GPIO2C7_GPIO		= 0,
	GPIO2C7_GMAC_TXD3	= 4,

	GPIO2C6_SHIFT		= 12,
	GPIO2C6_MASK		= 7 << GPIO2C6_SHIFT,
	GPIO2C6_GPIO		= 0,
	GPIO2C6_GMAC_TXD2	= 4,

	GPIO2C5_SHIFT		= 4,
	GPIO2C5_MASK		= 7 << GPIO2C5_SHIFT,
	GPIO2C5_GPIO		= 0,
	GPIO2C5_I2C2_SCL	= 3,
	GPIO2C5_GMAC_RXD2,

	GPIO2C4_SHIFT		= 0,
	GPIO2C4_MASK		= 7 << GPIO2C4_SHIFT,
	GPIO2C4_GPIO		= 0,
	GPIO2C4_I2C2_SDA	= 3,
	GPIO2C4_GMAC_RXD2,
};
#endif
