/*
 * Copyright (c) 2018-2019 Maxime Villard, All rights reserved.
 *
 * NetBSD Virtual Machine Monitor (NVMM) accelerator support.
 *
 * This work is licensed under the terms of the GNU GPL, version 2 or later.
 * See the COPYING file in the top-level directory.
 */

#ifndef QEMU_NVMM_H
#define QEMU_NVMM_H

#include "config-host.h"
#include "qemu-common.h"

int nvmm_init_vcpu(CPUState *);
int nvmm_vcpu_exec(CPUState *);
void nvmm_destroy_vcpu(CPUState *);

void nvmm_cpu_synchronize_state(CPUState *);
void nvmm_cpu_synchronize_post_reset(CPUState *);
void nvmm_cpu_synchronize_post_init(CPUState *);
void nvmm_cpu_synchronize_pre_loadvm(CPUState *);

#ifdef CONFIG_NVMM

int nvmm_enabled(void);

#else /* CONFIG_NVMM */

#define nvmm_enabled() (0)

#endif /* CONFIG_NVMM */

#endif /* CONFIG_NVMM */
