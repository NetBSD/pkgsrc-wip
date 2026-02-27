# $NetBSD: Makefile,v 1.2 2021/08/12 07:25:57 wiz Exp $

UBOOT_TARGET=		licheepi-zero
UBOOT_CONFIG=		LicheePi_Zero_defconfig
UBOOT_BIN=		u-boot-sunxi-with-spl.bin
UBOOT_LCD_MODE=		800x480 # or 480x272

UBOOT_INSTALLBOOT_PLIST=	installboot.plist

post-patch:
	cd ${WRKSRC}; \
	for f in ${.CURDIR}/patches/patch-*; do \
		${PATCH} -p0 < $$f; \
	done
	${CP} ${FILESDIR}/sun8i-v3s-licheepi-zero-lcd-${UBOOT_LCD_MODE}.dts ${WRKSRC}/arch/arm/dts/sun8i-v3s-licheepi-zero-lcd.dts
	${ECHO} 'CONFIG_DM_REGULATOR=y' >> ${WRKSRC}/configs/${UBOOT_CONFIG}
	${ECHO} 'CONFIG_DM_PWM=y' >> ${WRKSRC}/configs/${UBOOT_CONFIG}
	${ECHO} 'CONFIG_PWM_SUNXI=y' >> ${WRKSRC}/configs/${UBOOT_CONFIG}

.include "../../sysutils/u-boot/u-boot-arm.mk"
.include "../../mk/bsd.pkg.mk"
