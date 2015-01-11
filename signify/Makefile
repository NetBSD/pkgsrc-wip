# $NetBSD: Makefile,v 1.1 2015/01/11 23:24:19 yrmt Exp $

PKGNAME=	signify-0.1
CATEGORIES=	security
GHCOMMIT=	d5cd8fea8131606e53337c1ade62052d104cc41f
DISTNAME=	${GHCOMMIT}
MASTER_SITES=	https://github.com/yrmt/signify/archive/

MAINTAINER=	youri.mout@gmail.com
HOMEPAGE=	http://github.com/yrmt/signify
COMMENT=	Cryptographically sign and verify files, from OpenBSD
LICENSE=	isc

DIST_SUBDIR=	signify
WRKSRC=		${WRKDIR}/signify-${GHCOMMIT}

.include "../../mk/bsd.pkg.mk"
