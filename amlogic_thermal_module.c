/*
 * amlogic_thermal.c - Samsung amlogic thermal (Thermal Management Unit)
 *
 *  Copyright (C) 2011 Samsung Electronics
 *  Donggeun Kim <dg77.kim@samsung.com>
 *  Amit Daniel Kachhap <amit.kachhap@linaro.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#include <linux/module.h>
#include <linux/err.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/platform_device.h>
#include <linux/interrupt.h>
#include <linux/clk.h>
#include <linux/workqueue.h>
#include <linux/sysfs.h>
#include <linux/kobject.h>
#include <linux/io.h>
#include <linux/mutex.h>
#include <linux/thermal.h>
#include <linux/cpufreq.h>
#include <linux/cpu_cooling.h>
#include <linux/of.h>
#include <linux/amlogic/saradc.h>
#include <plat/cpu.h>
#include <linux/random.h>
#include <linux/gpu_cooling.h>
#include <linux/cpucore_cooling.h>
#include <linux/gpucore_cooling.h>
#include <linux/thermal_core.h>
#include <mach/thermal.h>
extern struct platform_driver amlogic_thermal_driver; 

static int __init amlogic_thermal_driver_init(void) 
{ 
	return platform_driver_register(&(amlogic_thermal_driver)); 
} 
late_initcall(amlogic_thermal_driver_init); 
static void __exit amlogic_thermal_driver_exit(void) 
{ 
	platform_driver_unregister(&(amlogic_thermal_driver) ); 
} 
module_exit(amlogic_thermal_driver_exit);

MODULE_DESCRIPTION("amlogic thermal Driver");
MODULE_AUTHOR("Amlogic SH platform team");
MODULE_ALIAS("platform:amlogic-thermal");
MODULE_LICENSE("GPL");

