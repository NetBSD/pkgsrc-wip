# $NetBSD$

PKGNAME=	u-boot-full-2016.05
DISTNAME=	u-boot-2016.05
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.denx.de/pub/u-boot/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joe.davis512@gmail.com
HOMEPAGE=	ftp://ftp.denx.de/pub/u-boot/
COMMENT=	Das U-Boot -- the Universal Boot Loader
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake pkg-config

USE_LANGUAGES=	c c++

# Require the linux device tree compiler
BUILD_DEPENDS=	dtc>=1.4.1:../../wip/dtc
AUTO_MKDIRS=	yes

.include "../../mk/bsd.prefs.mk"

post-patch:
.if ${OPSYS} == "NetBSD"
	cp ${FILESDIR}/stdarg.h ${WRKSRC}/include/
	cp ${FILESDIR}/stddef.h ${WRKSRC}/include/
	cp ${FILESDIR}/stdbool.h ${WRKSRC}/include/
.endif

do-configure:
.if defined(UBOOT_TARGET)
	cd ${WRKSRC} && gmake ${UBOOT_TARGET}_defconfig
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tools/mkimage ${DESTDIR}${PREFIX}/bin/u-boot-mkimage
	${INSTALL_PROGRAM} ${WRKSRC}/tools/fdtgrep ${DESTDIR}${PREFIX}/bin/u-boot-fdtgrep
	${INSTALL_PROGRAM} ${WRKSRC}/tools/mkenvimage ${DESTDIR}${PREFIX}/bin/u-boot-mkenvimage
	${INSTALL_PROGRAM} ${WRKSRC}/tools/dumpimage ${DESTDIR}${PREFIX}/bin/u-boot-dumpimage
	${INSTALL_SCRIPT} ${WRKSRC}/tools/netconsole ${DESTDIR}${PREFIX}/bin/u-boot-netconsole

.include "../../mk/bsd.pkg.mk"
