# $NetBSD: Makefile,v 1.1 2014/06/29 10:55:13 yrmt Exp $

PKGNAME=	osxinfo-0.1
CATEGORIES=	misc
GHCOMMIT=	de74b8960f27844f7b264697d124411f81a1eab6
DISTNAME=	${GHCOMMIT}
MASTER_SITES=	https://github.com/yrmt/osxinfo/archive/

MAINTAINER=	youri.mout@gmail.com
HOMEPAGE=	http://github.com/yrmt/osxinfo
COMMENT=	Small Mac OS X Info Program
LICENSE=	isc

ONLY_FOR_PLATFORM= Darwin-*-*

DIST_SUBDIR=	osxinfo
WRKSRC=		${WRKDIR}/osxinfo-${GHCOMMIT}

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
