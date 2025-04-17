/*
 * Copyright (c) 2017 Rockchip Electronics Co., Ltd
 *
 * SPDX-License-Identifier:     GPL-2.0+
 */
#include <asm/io.h>
#include <asm/arch/hardware.h>
#include <asm/arch/bootrom.h>
#include <asm/arch/grf_rk3128.h>
#include <asm/arch/io_rk312x.h>
#include <asm/arch/timer_rk3128.h>
#include <asm/arch/uart_rk32xx.h>

#define READLATENCY_VAL			0x3f
#define BUS_MSCH_QOS_BASE		0x10128014
#define	CPU_AXI_QOS_PRIORITY_BASE	0x1012f188
#define CPU_AXI_QOS_PRIORITY_LEVEL(h, l) \
	((((h) & 3) << 8) | (((h) & 3) << 2) | ((l) & 3))

int arch_cpu_init(void)
{
	uint32_t lcr, rate;

	/*
	 * reconfigure GRF_GPIO1B_IOMUX
	 *
	 * write_enable | uart1_ctsn | uart1_sout | uart1_sin | uart1_rtsn |
	 * mmc0_pwren | mmc0_cmd
	 */
	writel((0xfff << 16) | (1 << 1) | (1 << 3) | (1 << 5) | (1 << 7) |
		(1 << 12) | (1 << 14), RKIO_GRF_PHYS + GRF_GPIO1B_IOMUX);

	/*
	 * reconfigure GRF_GPIO1C_IOMUX
	 *
	 * write_enable | mmc0_clkout | mmc0_detn | mmc0_d0 | mmc0_d1 |
	 * mmc0_d2 | mmc0_d3 | emmc_cmd | emmc_rstnout
	 */

	writel((0xFFF << 16) | (1 << 0) | (1 << 2) | (1 << 4) | (1 << 6) |
		(1 << 8) | (1 << 10) | (1 << 13) | (1 << 15),
		RKIO_GRF_PHYS + GRF_GPIO1C_IOMUX);

	writel(UART_RESET | RCVR_FIFO_REST | XMIT_FIFO_RESET,
		CONFIG_DEBUG_UART_BASE + UART_SRR);

	/* 8n1 */
	lcr = readl(CONFIG_DEBUG_UART_BASE + UART_LCR);
	lcr |= LCR_WLS_8;
	lcr |= PARITY_DISABLED;
	lcr |= ONE_STOP_BIT;

	/* 115200 baud */
	lcr |= LCR_DLA_EN;
	writel(lcr, CONFIG_DEBUG_UART_BASE + UART_LCR);
	rate = UART_CLOCK_FREQ / UART_MODE_X_DIV / 115200;
	writel(rate & 0xFF, CONFIG_DEBUG_UART_BASE + UART_DLL);
	writel((rate >> 8) & 0xff, CONFIG_DEBUG_UART_BASE + UART_DLH);
	lcr = readl(CONFIG_DEBUG_UART_BASE + UART_LCR);
	writel(lcr & ~(LCR_DLA_EN), CONFIG_DEBUG_UART_BASE + UART_LCR);

	/* shadow FIFO enable */
	writel(SHADOW_FIFI_ENABLED, CONFIG_DEBUG_UART_BASE + UART_SFE);
	/* fifo 2 less than */
	writel(RCVR_TRIGGER_TWO_LESS_FIFO, CONFIG_DEBUG_UART_BASE + UART_SRT);
	/* 2 char in tx fifo */
	writel(TX_TRIGGER_TWO_IN_FIFO, CONFIG_DEBUG_UART_BASE + UART_STET);

	writel(0x00, CONFIG_DEBUG_UART_BASE + UART_IER);
	writel(IRDA_SIR_DISABLED, CONFIG_DEBUG_UART_BASE + UART_MCR);


	/* Read latency configure */
	writel(READLATENCY_VAL, BUS_MSCH_QOS_BASE);

	/* Set lcdc cpu axi qos priority level */
	writel(CPU_AXI_QOS_PRIORITY_LEVEL(3, 3), CPU_AXI_QOS_PRIORITY_BASE);

#ifdef CONFIG_ROCKCHIP_RK3126
	/*
	* Disable interrupt, otherwise it always generates wakeup signal. This
	* is an IC hardware issue.
	*/
	writel(0, SDMMC_INTMASK);

	/* raise cif ddr qos priority */
	writel(CPU_AXI_QOS_PRIORITY_LEVEL(3, 3), CPU_AXI_CIF_QOS_PRIORITY_BASE);
#endif

	/* start our timer and install our own timer_read_counter */
	rk3128_timer_init();

	return 0;
}

#ifdef CONFIG_DEBUG_UART_BOARD_INIT
void board_debug_uart_init(void)
{
}
#endif
