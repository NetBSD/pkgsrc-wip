# $NetBSD: Makefile,v 1.7 2013/11/15 19:16:38 asau Exp $
#

DISTNAME=	xombrero-1.3.1
#PKGNAME=	xombrero-1.3.1
CATEGORIES=	www
MASTER_SITES=	https://opensource.conformal.com/snapshots/xombrero/
EXTRACT_SUFX=	.tgz

MAINTAINER=	charles.rapenne@gmail.com
HOMEPAGE=	https://opensource.conformal.com/wiki/xombrero
COMMENT=	Light webkit browser with vi style
LICENSE=	isc

ONLY_FOR_PLATFORM= DragonFly-*-* NetBSD-*-*

FETCH_USING=	curl

USE_TOOLS+= perl pkg-config

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "DragonFly"
BUILD_DIRS= dragonfly
.endif

.if ${OPSYS} == "NetBSD"
BUILD_DIRS= netbsd
.endif


# the path for the default config file is
# hardcoded as /usr/local/ in xombrero.h
do-configure:
	cd ${WRKSRC} && \
	sed -e "s#\\/usr\\/local#${PREFIX}#" xombrero.h \
	> xombrero.h.new && mv xombrero.h.new xombrero.h

.include "../../security/gnutls/buildlink3.mk"
.include "../../www/webkit-gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
