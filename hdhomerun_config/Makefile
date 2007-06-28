# $NetBSD: Makefile,v 1.4 2007/06/28 18:14:54 jakllsch Exp $
#

DISTNAME=	libhdhomerun_20070620
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
USE_TOOLS+=	gmake

CFLAGS.SunOS+= -lsocket

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hdhomerun_config ${PREFIX}/bin/hdhomerun_config

.include "../../mk/bsd.pkg.mk"
