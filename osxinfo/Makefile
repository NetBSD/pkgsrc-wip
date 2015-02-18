# $NetBSD: Makefile,v 1.3 2015/02/18 16:54:49 yrmt Exp $

PKGNAME=	osxinfo-0.1
CATEGORIES=	misc
GHCOMMIT=	1ddf9b35cfaa4accbf43347332b6b8298a829233
DISTNAME=	${GHCOMMIT}
MASTER_SITES=	https://github.com/yrmt/osxinfo/archive/

MAINTAINER=	youri.mout@gmail.com
HOMEPAGE=	http://github.com/yrmt/osxinfo
COMMENT=	Small Mac OS X Info Program
LICENSE=	isc

ONLY_FOR_PLATFORM= Darwin-*-*

SUBST_CLASSES+=	path
SUBST_STAGE.path=	pre-build
SUBST_MESSAGE.path=	Adjusting path.
SUBST_FILES.path=	Makefile
SUBST_SED.path=		-e "s|/var|${VARBASE}|g"

DIST_SUBDIR=	osxinfo
WRKSRC=		${WRKDIR}/osxinfo-${GHCOMMIT}

.include "../../mk/bsd.pkg.mk"
