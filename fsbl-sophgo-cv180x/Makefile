# $NetBSD$

DISTNAME=	${GITHUB_PROJECT}-sophgo-4.1.6
#PKGNAME=	${DISTNAME:S/-/-${CHIP_ARCH}-/}
PKGNAME=	${DISTNAME:C/^([^-]*-[^-]*)-/\1-${CHIP_ARCH}-/}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=sophgo/}
GITHUB_PROJECT=	fsbl
GITHUB_TAG=	refs/tags/v${DISTNAME:S/${GITHUB_PROJECT}-sophgo-//}

MAINTAINER=	port-riscv@NetBSD.org
HOMEPAGE=	https://github.com/sophgo/fsbl/
COMMENT=	First Stage Boot Loader for cv18xx series SoCs
LICENSE=	modified-bsd AND gnu-gpl-v2

USE_TOOLS+=	gmake pkg-config
TOOL_DEPENDS+=	coreutils-[0-9]*:../../sysutils/coreutils
USE_LANGUAGES=	c c++
BUILD_DEPENDS+=	cross-riscv64-none-elf-xuantie-gcc-[0-9]*:../../wip/riscv64-none-elf-xuantie-gcc

REPLACE_PYTHON=		plat/cv180x/chip_conf.py
REPLACE_PYTHON+=	plat/cv180x/fiptool.py

PKGCONFIG_OVERRIDE+=	lib/libtommath/libtommath.pc.in

CHIP_ARCH=	cv180x
MAKE_FLAGS=	ARCH=riscv CHIP_ARCH=${CHIP_ARCH} DDR_CFG=ddr2_1333_x16 \
		MONITOR_PATH=${PREFIX}/share/opensbi/milkv-duo/fw_dynamic.bin \
		LOADER_2ND_PATH=${PREFIX}/share/u-boot/milkv-duo/u-boot.bin \
		CROSS_COMPILE_GLIBC_RISCV64=${PREFIX}/cross-riscv64-none-elf-xuantie/bin/riscv64-none-elf-

#BUILD_TARGET=	b12

WRKSRC=		${WRKDIR}/${DISTNAME:S/-sophgo//}

post-extract:
	${CP} ${PREFIX}/share/u-boot/milkv-duo/cvi_board_memmap.h \
		${WRKSRC}/plat/${CHIP_ARCH}/include

do-build:
	cd ${WRKSRC} && ${SETENV} ${GMAKE} ${MAKE_FLAGS}

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/fsbl/sophgo/${CHIP_ARCH}
	${INSTALL_DATA} ${WRKSRC}/build/${CHIP_ARCH}/fip.bin \
		${DESTDIR}${PREFIX}/share/fsbl/sophgo/${CHIP_ARCH}

.include "../../lang/python/application.mk"
.include "../../wip/opensbi-milkv-duo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
