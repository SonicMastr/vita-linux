/*
 * Device Tree support for PlayStation Vita
 *
 * Copyright (C) 2018 Sergi Granell
 * 
 * Copyright (C) 2023 Jaylon Gowie
 *
 *
 * This file is licensed under the terms of the GNU General Public
 * License version 2.  This program is licensed "as is" without any
 * warranty of any kind, whether express or implied.
 */

#include <linux/init.h>

#include <asm/mach/arch.h>

static long long __init vita_pv_fixup(void)
{
	/** This is a terrible hack, but it needs to be done
	 * 	to fix random bug of kernel_sec_* returning 0x0
	 */

	kernel_sec_start = 0x41000000;
	kernel_sec_end = 0x42200000;

	return 0;
}

static const char *const vita_dt_compat[] = {
	"vita,vita",
	NULL,
};

DT_MACHINE_START(VITA_DT, "PlayStation Vita (Device Tree Support)")
	.dt_compat = vita_dt_compat,
	.l2c_aux_val = 0, .l2c_aux_mask = ~0,
	.pv_fixup = vita_pv_fixup, 
MACHINE_END