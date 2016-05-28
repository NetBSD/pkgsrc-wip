# $NetBSD: Makefile,v 1.6 2012/10/03 18:15:31 asau Exp $

DISTNAME=		net-tools-1.60
CATEGORIES=		net sysutils
MASTER_SITES=		http://www.tazenda.demon.co.uk/phil/net-tools/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
#HOMEPAGE
COMMENT=		Network configuration and status tools for Linux


USE_TOOLS+=		gmake
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
