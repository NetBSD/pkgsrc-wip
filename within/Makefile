# $NetBSD$

DISTNAME=	within-1.1.3
CATEGORIES=	sysutils parallel
MASTER_SITES=	${MASTER_SITE_GITHUB:=sjmulder/}

MAINTAINER=	ik@sjmulder.nl
HOMEPAGE=	https://github.com/sjmulder/within
COMMENT=	Run a command in other directories
LICENSE=	gnu-agpl-v3

INSTALL_MAKE_FLAGS+=	MANPREFIX=${PREFIX}/${PKGMANDIR}
TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
