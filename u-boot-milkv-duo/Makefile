# $NetBSD$

DISTNAME=	${GITHUB_PROJECT}-2021.10_64mb
MASTER_SITES=	${MASTER_SITE_GITHUB:=milkv-duo/}
GITHUB_PROJECT=	milkv-duo-u-boot
GITHUB_TAG=	refs/tags/v${DISTNAME:S/${GITHUB_PROJECT}-//}
EXTRACT_SUFX=	.tar.gz
DISTINFO_FILE=	${.CURDIR}/distinfo
PATCHDIR=	${.CURDIR}/patches

UBOOT_TARGET=		milkv-duo
UBOOT_VERSION=		2021.10
UBOOT_CONFIG=		cvitek_cv1800b_milkv_duo_sd_defconfig
UBOOT_BIN=		u-boot.bin

WRKSRC=		${WRKDIR}/${DISTNAME}

post-install:
	${INSTALL_DATA} ${WRKSRC}/arch/riscv/dts/cv1800b_milkv_duo_sd.dtb \
		${DESTDIR}${PREFIX}/share/u-boot/${UBOOT_TARGET}
	${INSTALL_DATA} ${WRKSRC}/include/cvi_board_memmap.h \
		${DESTDIR}${PREFIX}/share/u-boot/${UBOOT_TARGET}

.include "../../sysutils/u-boot/u-boot-riscv64.mk"
.include "../../mk/bsd.pkg.mk"
