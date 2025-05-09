# $NetBSD$

UBOOT_TARGET=		omap4-panda
UBOOT_CONFIG=		omap4_panda_defconfig
UBOOT_BIN=		MLO u-boot.img

UBOOT_VERSION=		2021.01

UBOOT_INSTALLBOOT_PLIST=	installboot.plist

post-patch:
	cd ${WRKSRC}; \
	for f in ${.CURDIR}/patches/patch-*; do \
		${PATCH} -p0 < $$f; \
	done
	${ECHO} 'CONFIG_DM_ETH=n' >> ${WRKSRC}/configs/${UBOOT_CONFIG}
	${ECHO} 'CONFIG_DM_USB=n' >> ${WRKSRC}/configs/${UBOOT_CONFIG}
	${ECHO} 'CONFIG_TWL6030_POWER=y' >> ${WRKSRC}/configs/${UBOOT_CONFIG}

.include "../../sysutils/u-boot/u-boot-arm.mk"
.include "../../mk/bsd.pkg.mk"
