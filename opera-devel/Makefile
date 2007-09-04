# $NetBSD: Makefile,v 1.21 2007/09/04 17:00:46 ghen Exp $

DISTNAME=		opera-9.50alpha1
CATEGORIES=		www
MASTER_SITES=		http://snapshot.opera.com/${OPERA_DIR}/
DISTFILES=		opera-${OPERA_DIST_VERSION}${OPERA_ARCH}${EXTRACT_SUFX}

MAINTAINER=		ghen@NetBSD.org
HOMEPAGE=		http://snapshot.opera.com/
COMMENT=		Small, fast and customizable WWW client

LICENSE=		opera-850-license

EMUL_PLATFORMS=		freebsd-i386
EMUL_PLATFORMS+=	linux-i386

.include "../../mk/bsd.prefs.mk"

USE_LANGUAGES=		# empty
BUILD_DIRS=		# empty

OPERA_LANG=		en
OPERA_VER_DATE=		20070903
OPERA_PKG_VERSION=	9.50
OPERA_PKG_VERSION_DIR=	1567

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

PLIST_SUBST+=		OPERA_VER_DATE=${OPERA_VER_DATE:Q}
PLIST_SUBST+=		OPERA_PKG_VERSION=${OPERA_PKG_VERSION:C/u.*//}

.if ${EMUL_PLATFORM} == "linux-i386"
.  include "Makefile.rpm"
.else
.  include "Makefile.plain"
.endif

.include "../../mk/bsd.pkg.mk"
