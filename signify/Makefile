# $NetBSD: Makefile,v 1.6 2015/02/15 21:07:04 yrmt Exp $

GHCOMMIT=	9170b4391945da17fd2ac2e251b54b3400668192
DISTNAME=	${GHCOMMIT}
PKGNAME=	signify-0.1.0.20150215
CATEGORIES=	security
MASTER_SITES=	https://github.com/yrmt/signify/archive/

MAINTAINER=	youri.mout@gmail.com
HOMEPAGE=	https://github.com/yrmt/signify
COMMENT=	Cryptographically sign and verify files, from OpenBSD
LICENSE=	isc

WRKSRC=		${WRKDIR}/signify-${GHCOMMIT}

GNU_CONFIGURE=	yes

.include "../../mk/bsd.pkg.mk"
