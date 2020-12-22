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

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALL_MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.pkg.mk"
