# $NetBSD: Makefile,v 1.2 2003/08/29 10:31:23 thomasklausner Exp $

DISTNAME=		net-tools-1.60
CATEGORIES=		net sysutils
MASTER_SITES=		http://www.tazenda.demon.co.uk/phil/net-tools/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
#HOMEPAGE
COMMENT=		Network configuration and status tools for Linux

USE_GMAKE=		YES
# build uses linux/if_ether.h for example
ONLY_FOR_PLATFORM=	Linux-*-*

do-configure:
	cd ${WRKSRC} && yes "" | ${GMAKE} BASEDIR=${PREFIX} config

do-build:
	cd ${WRKSRC} && yes "" | ${GMAKE} BASEDIR=${PREFIX}

do-install:
# XXX "make install" backs up files; use "make update"
	cd ${WRKSRC} && ${GMAKE} BASEDIR=${PREFIX} update

.include "../../mk/bsd.pkg.mk"
