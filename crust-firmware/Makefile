# $NetBSD: Makefile,v 1.2 2018/09/29 16:26:53 tnn Exp $

VERSION=	20190427
GITHUB_TAG=	0d214325cf80fe54339e421a1a9f139fbb7fcd86
GITHUB_PROJECT=	crust

PKGNAME=	crust-firmware-${VERSION}
DISTNAME=	${PKGNAME}
MASTER_SITES=	${MASTER_SITE_GITHUB:=crust-firmware/}
CATEGORIES=	sysutils
EXTRACT_SUFX=	.zip

MAINTAINER=	port-arm@NetBSD.org
HOMEPAGE=	https://github.com/crust-firmware/crust/
COMMENT=	SCP firmware for sunxi SoCs
LICENSE=	modified-bsd

USE_TOOLS+=	gmake yacc flex

BUILD_DEPENDS+=	cross-or1k-none-elf-gcc-[0-9]*:../../cross/or1k-none-elf-gcc

MAKE_FLAGS+=	CROSS_COMPILE=${PREFIX}/cross-or1k-none-elf/bin/or1k-none-elf-

do-configure:
	cd ${WRKSRC} && ${GMAKE} defconfig

	
do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/crust-firmware/
	${INSTALL_DATA} ${WRKSRC}/build/scp/scp.bin \
	    ${DESTDIR}${PREFIX}/share/crust-firmware/


.include "../../mk/bsd.prefs.mk"
# XXX kludge. pkgsrc passes down run path flags in LDFLAGS but the
# cross ld(1) doesn't understand -R. If we pass down -L instead it
# will be safely ignored.
COMPILER_RPATH_FLAG=-L
	
.include "../../mk/bsd.pkg.mk"
