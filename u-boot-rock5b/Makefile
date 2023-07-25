# $NetBSD$

UBOOT_VERSION=		2023.04rc3
UBOOT_TARGET=		rock5b
UBOOT_CONFIG=		rock5b-rk3588_defconfig
UBOOT_BIN=		rksd_loader.img

UBOOT_INSTALLBOOT_PLIST=	installboot.plist

# Collabora's mainlining branch
MASTER_SITES=		https://gitlab.collabora.com/hardware-enablement/rockchip-3588/u-boot/-/archive/${UBOOT_TAG}/
UBOOT_TAG=		a8e0c4a17c197cc85922a292f16365733e75de64
DISTNAME=		u-boot-${UBOOT_TAG}
EXTRACT_SUFX=		.tar.bz2
EXTRACT_ONLY=		${DISTNAME}${EXTRACT_SUFX}

DISTFILES+=		rk3588_ddr_lp4_2112MHz_lp5_2736MHz_v1.08.bin
SITES.rk3588_ddr_lp4_2112MHz_lp5_2736MHz_v1.08.bin=	https://github.com/radxa/rkbin/raw/master/bin/rk35/

DISTFILES+=		rk3588_bl31_v1.34.elf
SITES.rk3588_bl31_v1.34.elf=	https://github.com/radxa/rkbin/raw/master/bin/rk35/

TOOL_DEPENDS+=		${PYPKGPREFIX}-pyelftools-[0-9]*:../../devel/py-pyelftools

DISTINFO_FILE=		${.CURDIR}/distinfo

MAKE_ENV+=		ROCKCHIP_TPL=${DISTDIR}/rk3588_ddr_lp4_2112MHz_lp5_2736MHz_v1.08.bin
MAKE_ENV+=		BL31=${DISTDIR}/rk3588_bl31_v1.34.elf

# u-boot.itb goes at block offset 16384
# 16384 - 64 = 16320 to create one image containing both files
post-build:
	${CP} ${WRKSRC}/idbloader.img ${WRKSRC}/rksd_loader.img
	dd if=${WRKSRC}/u-boot.itb conv=notrunc seek=16320 of=${WRKSRC}/rksd_loader.img

.include "../../sysutils/u-boot/u-boot-arm64.mk"
.include "../../mk/bsd.pkg.mk"
