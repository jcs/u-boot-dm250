/*
 * (C) Copyright 2015 Rockchip Electronics Co., Ltd
 *
 * SPDX-License-Identifier:     GPL-2.0+
 */

#ifndef __ASM_ARCH_TIMER_H
#define __ASM_ARCH_TIMER_H

struct rk_timer {
	u32 timer_load_count0;
	u32 timer_load_count1;
	u32 timer_curr_value0;
	u32 timer_curr_value1;
	u32 timer_ctrl_reg;
	u32 timer_int_status;
};

#endif
