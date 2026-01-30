# $NetBSD: Makefile,v 1.6 2024/01/31 16:42:51 ryoon Exp $

TARGET=			mipsel-none-elf
GCC_VERSION=		13.2.0

MAINTAINER=		port-mips@NetBSD.org
COMMENT=		GCC for bare metal MIPS 32-bit little-endian ELF

# Relocations result in a linker error.
MKPIE_SUPPORTED=	no

.include "../../wip/common-gnu-toolchain/gcc.mk"
.include "../../mk/bsd.pkg.mk"
