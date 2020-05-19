# $NetBSD: Makefile,v 1.3 2013/12/16 14:06:40 outpaddling Exp $
#

DISTNAME=	libbacon-1.2.2.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=outpaddling/}
GITHUB_TAG=	2e181aa1d6f39d0b767453b7e5e6bc7b0f301dc3

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/outpaddling/libbacon
COMMENT=	Miscellaneous experimental functions
LICENSE=	2-clause-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}

.include "../../mk/bsd.pkg.mk"
