/*
 * Copyright (c) 2018-2019 Maxime Villard, All rights reserved.
 *
 * NetBSD Virtual Machine Monitor (NVMM) accelerator stub.
 *
 * This work is licensed under the terms of the GNU GPL, version 2 or later.
 * See the COPYING file in the top-level directory.
 */

#include "qemu/osdep.h"
#include "qemu-common.h"
#include "cpu.h"
#include "sysemu/nvmm.h"

int nvmm_init_vcpu(CPUState *cpu)
{
    return -1;
}

int nvmm_vcpu_exec(CPUState *cpu)
{
    return -1;
}

void nvmm_destroy_vcpu(CPUState *cpu)
{
}

void nvmm_cpu_synchronize_state(CPUState *cpu)
{
}

void nvmm_cpu_synchronize_post_reset(CPUState *cpu)
{
}

void nvmm_cpu_synchronize_post_init(CPUState *cpu)
{
}

void nvmm_cpu_synchronize_pre_loadvm(CPUState *cpu)
{
}
