# $NetBSD: Makefile,v 1.2 2013/08/14 01:33:35 outpaddling Exp $
#

DISTNAME=	libpare-1.1.1.11
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=outpaddling/}
GITHUB_TAG=	3b1715b82166e505ea98bcfdd713a49714879fe9

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://github.com/outpaddling/libpare
COMMENT=	Pointer Array Regular Expressions
LICENSE=	2-clause-bsd

MAKE_ENV=	MANDIR=${PREFIX}/${PKGMANDIR}

pre-build:
	cd ${WRKSRC} && make depend LOCALBASE=${LOCALBASE}

.include "../../mk/bsd.pkg.mk"
