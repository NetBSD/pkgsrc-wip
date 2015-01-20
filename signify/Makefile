# $NetBSD: Makefile,v 1.5 2015/01/20 14:52:10 yrmt Exp $

GHCOMMIT=	ce5f56307017d36267fab4bf86a073a852b05989
DISTNAME=	${GHCOMMIT}
PKGNAME=	signify-0.1
CATEGORIES=	security
MASTER_SITES=	https://github.com/yrmt/signify/archive/

MAINTAINER=	youri.mout@gmail.com
HOMEPAGE=	http://github.com/yrmt/signify
COMMENT=	Cryptographically sign and verify files, from OpenBSD
LICENSE=	isc

WRKSRC=		${WRKDIR}/signify-${GHCOMMIT}

GNU_CONFIGURE=	yes

.include "../../mk/bsd.pkg.mk"
