# $NetBSD: Makefile,v 1.8 2008/07/08 20:36:02 jakllsch Exp $
#

DISTNAME=	libhdhomerun_20080430
PKGNAME=	${DISTNAME:S/libhdhomerun_/hdhomerun_config-/}
CATEGORIES=	multimedia
MASTER_SITES=	http://download.silicondust.com/hdhomerun/
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
