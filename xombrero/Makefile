# $NetBSD: Makefile,v 1.10 2013/11/15 20:11:30 asau Exp $
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

MAKE_JOBS_SAFE=	no

USE_BSD_MAKEFILE=	yes
USE_TOOLS+= perl pkg-config

SUBST_CLASSES+=			fix-prefix
SUBST_STAGE.fix-prefix=		pre-configure
SUBST_MESSAGE.fix-prefix=	Fixing PREFIX.
SUBST_FILES.fix-prefix=		xombrero.h
SUBST_SED.fix-prefix=		-e 's,/usr/local,${PREFIX},g'

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "DragonFly"
BUILD_DIRS= dragonfly
.endif

.if ${OPSYS} == "NetBSD"
BUILD_DIRS= netbsd
.endif

.include "../../security/gnutls/buildlink3.mk"
.include "../../www/webkit-gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
