# $NetBSD$

DISTNAME=	nq-0.4
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=leahneukirchen/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	dressupgeekout@gmail.com
HOMEPAGE=	https://github.com/leahneukirchen/nq
COMMENT=	Command line queueing utility
LICENSE=	public-domain

TEST_TARGET=		check
# TEST_DEPENDS: perl's prove(1)

INSTALL_MAKE_FLAGS+=	PREFIX=${PREFIX}
INSTALL_MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.pkg.mk"
