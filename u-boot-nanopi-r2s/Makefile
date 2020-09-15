# $NetBSD: Makefile,v 1.1 2020/06/30 14:40:05 thorpej Exp $

UBOOT_TARGET=		nanopi-r2s
UBOOT_CONFIG=		nanopi-r2s-rk3328_defconfig
UBOOT_BIN=		u-boot-rockchip.bin

UBOOT_INSTALLBOOT_PLIST=	installboot.plist

UBOOT_VERSION=		2020.07
MASTER_SITES=		${MASTER_SITE_GITHUB:=blocktrron/}
GITHUB_PROJECT=		uboot-nanopi-r2s
GITHUB_TAG=		b8c2aded187e23779a9f565d3577cd46027f0946

DISTINFO_FILE=		${.CURDIR}/../../wip/u-boot-nanopi-r2s/distinfo
PATCHDIR=		${.CURDIR}/../../wip/u-boot-nanopi-r2s/patches
DISTFILES=		${DEFAULT_DISTFILES}
EXTRACT_SUFX=		.tar.gz # keep

# This could be moved to u-boot.mk as long as we don't have support for
# any imx8 boards.
CHECK_PORTABILITY_SKIP+=        tools/imx8m_image.sh

# Switch to EL1 before booting kernel (required for 32-bit support)
PKG_DEFAULT_OPTIONS+=	el1

post-extract:
	${CP} ${PREFIX}/share/arm-trusted-firmware/rk3328/bl31.elf ${WRKSRC}

.include "../../sysutils/arm-trusted-firmware-rk3328/buildlink3.mk"
.include "../../sysutils/u-boot/u-boot-arm64.mk"
