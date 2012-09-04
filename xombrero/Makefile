# $NetBSD: Makefile,v 1.1 2012/09/04 09:42:59 zplay Exp $
#

DISTNAME=	xombrero-XOMBRERO_1_3_0-4-g323af97
PKGNAME=	xombrero-1.3.0
CATEGORIES=	www
MASTER_SITES=	http://www.zcraft.fr/data/

MAINTAINER=	charles.rapenne@gmail.com
HOMEPAGE=	https://opensource.conformal.com/wiki/xombrero
COMMENT=	Light webkit browser with vi style
LICENSE=	isc

ONLY_FOR_PLATFORM= DragonFly-*-*

PKG_DESTDIR_SUPPORT=	user-destdir
NO_CONFIGURE= yes
USE_TOOLS+= perl

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "DragonFly"
BUILD_DIRS= dragonfly
.endif

# the path for the default config file is
# hardcoded as /usr/local/ in xombrero.h
post-extract:
	cd ${WRKDIR}/${DISTNAME} && \
	sed -e "s#\\/usr\\/local#${PREFIX}#" xombrero.h \
	> xombrero.h.new && mv xombrero.h.new xombrero.h

.include "../../security/gnutls/buildlink3.mk"
.include "../../www/webkit-gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
