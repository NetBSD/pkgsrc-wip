# $NetBSD: Makefile,v 1.4 2012/10/07 20:11:10 asau Exp $
#

DISTNAME=	xombrero-1.3.1
#PKGNAME=	xombrero-1.3.1
CATEGORIES=	www
MASTER_SITES=	https://opensource.conformal.com/snapshots/xombrero/

MAINTAINER=	charles.rapenne@gmail.com
HOMEPAGE=	https://opensource.conformal.com/wiki/xombrero
COMMENT=	Light webkit browser with vi style
LICENSE=	isc
FETCH_USING=	curl
EXTRACT_SUFX=	.tgz

ONLY_FOR_PLATFORM= DragonFly-*-* NetBSD-*-*

NO_CONFIGURE= yes
USE_TOOLS+= perl

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "DragonFly"
BUILD_DIRS= dragonfly
.endif

.if ${OPSYS} == "NetBSD"
BUILD_DIRS= netbsd
.endif


# the path for the default config file is
# hardcoded as /usr/local/ in xombrero.h
post-extract:
	cd ${WRKSRC} && \
	sed -e "s#\\/usr\\/local#${PREFIX}#" xombrero.h \
	> xombrero.h.new && mv xombrero.h.new xombrero.h

.include "../../security/gnutls/buildlink3.mk"
.include "../../www/webkit-gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
