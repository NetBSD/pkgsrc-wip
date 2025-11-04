# $NetBSD$

UBOOT_TARGET=	imx23-olinuxino
UBOOT_CONFIG=	mx23_olinuxino_defconfig
UBOOT_BIN=	u-boot.sb
BUILD_TARGET=	u-boot.sb

UBOOT_VERSION=	2024.10

UBOOT_INSTALLBOOT_PLIST=	installboot.plist

PKGREVISION=		1

# the u-boot package doesn't depend on openssl, but the .sb-generators need it
.include "../../security/openssl/buildlink3.mk"

.include "../../sysutils/u-boot/u-boot-arm.mk"
.include "../../mk/bsd.pkg.mk"
