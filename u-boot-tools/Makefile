# $NetBSD$

UBOOT_VERSION=	2023.07
DISTNAME=	u-boot-${UBOOT_VERSION}
PKGNAME=	u-boot-tools-${UBOOT_VERSION:S/-/./}
CATEGORIES=	sysutils
MASTER_SITES?=	ftp://ftp.denx.de/pub/u-boot/
EXTRACT_SUFX?=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.denx.de/wiki/U-Boot
COMMENT=	Das U-Boot, the Universal Boot Loader (tools)
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c
USE_TOOLS+=	gmake

BUILD_TARGET=	defconfig tools-only
MAKE_ENV+=	HOSTLDLIBS=-L${PREFIX}/lib

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL} ${WRKSRC}/tools/dumpimage ${DESTDIR}${PREFIX}/bin/u-boot-dumpimage
	${INSTALL} ${WRKSRC}/tools/mkimage ${DESTDIR}${PREFIX}/bin/u-boot-mkimage
	${INSTALL_DATA} ${WRKSRC}/doc/dumpimage.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/u-boot-dumpimage.1
	${INSTALL_DATA} ${WRKSRC}/doc/mkimage.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/u-boot-mkimage.1

do-test:
	${WRKSRC}/tools/dumpimage -h
	${WRKSRC}/tools/mkimage -h

.include "../../devel/libuuid/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
