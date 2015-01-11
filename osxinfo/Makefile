# $NetBSD: Makefile,v 1.2 2015/01/11 22:17:01 yrmt Exp $

PKGNAME=	osxinfo-0.1
CATEGORIES=	misc
GHCOMMIT=	56b6a5eed42948340037bad222694b0df5eee117
DISTNAME=	${GHCOMMIT}
MASTER_SITES=	https://github.com/yrmt/osxinfo/archive/

MAINTAINER=	youri.mout@gmail.com
HOMEPAGE=	http://github.com/yrmt/osxinfo
COMMENT=	Small Mac OS X Info Program
LICENSE=	isc

ONLY_FOR_PLATFORM= Darwin-*-*

DIST_SUBDIR=	osxinfo
WRKSRC=		${WRKDIR}/osxinfo-${GHCOMMIT}

.include "../../mk/bsd.pkg.mk"
