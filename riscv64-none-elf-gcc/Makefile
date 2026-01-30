# $NetBSD: Makefile,v 1.3 2024/05/13 23:08:56 gutteridge Exp $

TARGET=			riscv64-none-elf

MAINTAINER=		port-riscv@NetBSD.org
COMMENT=		GCC for bare metal RISC-V 32/64 bit little-endian ELF

CHECK_PORTABILITY_SKIP+=	contrib/*
CHECK_PORTABILITY_SKIP+=	gcc/config/nvptx/gen-opt.sh

.include "../common-gnu-toolchain/gcc.mk"
.include "../../mk/bsd.pkg.mk"
