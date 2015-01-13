# $NetBSD: Makefile,v 1.3 2015/01/13 00:48:53 yrmt Exp $

PKGNAME=	signify-0.1
CATEGORIES=	security
GHCOMMIT=	ce5f56307017d36267fab4bf86a073a852b05989
DISTNAME=	${GHCOMMIT}
MASTER_SITES=	https://github.com/yrmt/signify/archive/
FETCH_USING=	curl

MAINTAINER=	youri.mout@gmail.com
HOMEPAGE=	http://github.com/yrmt/signify
COMMENT=	Cryptographically sign and verify files, from OpenBSD
LICENSE=	isc

DIST_SUBDIR=	signify
WRKSRC=		${WRKDIR}/signify-${GHCOMMIT}

GNU_CONFIGURE=	yes

.include "../../mk/bsd.pkg.mk"
