# $NetBSD: Makefile,v 1.1.1.1 2007/02/09 19:11:01 jakllsch Exp $
#

DISTNAME=	libhdhomerun_20070204
PKGNAME=	${DISTNAME:S/libhdhomerun_/hdhomerun_config-/}
CATEGORIES=	multimedia
MASTER_SITES=	http://www.silicondust.com/hdhomerun/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jakllsch@kollasch.net
HOMEPAGE=	http://www.silicondust.com/hdhomerun/
COMMENT=	SiliconDust HDHomeRun utility

WRKSRC=		${WRKDIR}/libhdhomerun
BUILD_TARGET=	hdhomerun_config
USE_LANGUAGES+=	c

INSTALLATION_DIRS=      bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hdhomerun_config ${PREFIX}/bin/hdhomerun_config

.include "../../mk/bsd.pkg.mk"
