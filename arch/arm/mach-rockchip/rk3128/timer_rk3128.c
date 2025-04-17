/*
 * (C) Copyright 2015 Rockchip Electronics Co., Ltd
 *
 * SPDX-License-Identifier:     GPL-2.0+
 */

#include <asm/arch/timer_rk3128.h>
#include <asm/io.h>
#include <common.h>
#include <linux/types.h>

unsigned long timer_read_counter(void)
{
	uint64_t timebase_h, timebase_l;

	timebase_l = readl(CONFIG_ROCKCHIP_STIMER_BASE + TIMER_CURRENT_VALUE0);
	timebase_h = readl(CONFIG_ROCKCHIP_STIMER_BASE + TIMER_CURRENT_VALUE1);

	return timebase_h << 32 | timebase_l;
}

void rk3128_timer_init(void)
{
	writel(TIMER_DISABLE, CONFIG_ROCKCHIP_STIMER_BASE + TIMER_CONTROL_REG);
	writel(0xffffffff, CONFIG_ROCKCHIP_STIMER_BASE + TIMER_LOAD_COUNT0);
	writel(0xffffffff, CONFIG_ROCKCHIP_STIMER_BASE + TIMER_LOAD_COUNT1);
	writel(TIMER_ENABLE | TIMER_MODE_FREE_RUNNING,
		CONFIG_ROCKCHIP_STIMER_BASE + TIMER_CONTROL_REG);
}
