/*
 * (C) Copyright 2015 Rockchip Electronics Co., Ltd
 *
 * SPDX-License-Identifier:     GPL-2.0+
 */

#ifndef __ASM_ARCH_TIMER_RK3128_H
#define __ASM_ARCH_TIMER_RK3128_H

#define TIMER_LOAD_COUNT0		0x00
#define TIMER_LOAD_COUNT1		0x04
#define TIMER_CURRENT_VALUE0		0x08
#define TIMER_CURRENT_VALUE1		0x0c
#define TIMER_CONTROL_REG		0x10
#define TIMER_INT_STATUS		0x18

#define TIMER_DISABLE			(0 << 0)
#define TIMER_ENABLE			(1 << 0)
#define TIMER_MODE_FREE_RUNNING		(0 << 1)
#define TIMER_MODE_USER_DEFINED_COUNT	(1 << 1)
#define TIMER_INT_MASK			(0 << 2)
#define TIMER_INT_UNMASK		(1 << 2)

void rk3128_timer_init(void);

#endif

