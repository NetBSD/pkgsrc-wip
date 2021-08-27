# $NetBSD: Makefile,v 1.2 2013/08/14 01:33:35 outpaddling Exp $
#

DISTNAME=	libpare-1.1.1.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=outpaddling/}
GITHUB_TAG=	0eaa30a88f9d235c89f2b2d5fbf48c742c5a4a80

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/outpaddling/libpare
COMMENT=	Pointer Array Regular Expressions
LICENSE=	2-clause-bsd

MAKE_ENV=	MANDIR=${PREFIX}/${PKGMANDIR}

pre-build:
	cd ${WRKSRC} && make depend LOCALBASE=${LOCALBASE}

.include "../../mk/bsd.pkg.mk"
