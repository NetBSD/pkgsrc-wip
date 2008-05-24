# $NetBSD: Makefile,v 1.7 2008/05/24 15:34:10 tnn2 Exp $
#

DISTNAME=	libhdhomerun_20080305
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
