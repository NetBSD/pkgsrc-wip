# $NetBSD: Makefile,v 1.2 2008/04/13 12:24:19 noud4 Exp $
#

DISTNAME=	u-boot-1.3.2
PKGNAME=	u-boot-mkimage-1.3.2
CATEGORIES=	wip
MASTER_SITES=	ftp://ftp.denx.de/pub/u-boot/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	noud4@home.nl
HOMEPAGE=	http://www.denx.de/wiki/UBoot
COMMENT=	The mkimage utility of the u-boot bootloader

USE_TOOLS=	make

do-patch:
	${CP} ${FILESDIR}/BSDmakefile ${WRKSRC}/tools

do-build:
	cd ${WRKSRC}/tools && make -f BSDmakefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tools/mkimage ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
