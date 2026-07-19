# $NetBSD$

DISTNAME=	2048-c-1.0.3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=mevdschee/}
GITHUB_PROJECT=	2048.c
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://github.com/mevdschee/2048.c
COMMENT=	Console version of the game 2048
LICENSE=	mit

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${PKGVERSION_NOREV}

USE_LANGUAGES=		c
INSTALLATION_DIRS+=	bin

TEST_TARGET=		test

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/2048 ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
