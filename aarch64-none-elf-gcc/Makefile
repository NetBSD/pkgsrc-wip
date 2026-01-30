# $NetBSD: Makefile,v 1.19 2022/01/16 21:10:17 tnn Exp $

TARGET=			aarch64-none-elf

MAINTAINER=		port-arm@NetBSD.org
COMMENT=		GCC for bare metal AArch64 ELF

MKPIE_SUPPORTED=	no # relocation errors on netbsd-9 aarch64

.include "../common-gnu-toolchain/gcc.mk"
.include "../../mk/bsd.pkg.mk"
