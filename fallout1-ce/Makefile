# $NetBSD$

GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	fallout1-ce-1.0.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=alexbatalov/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/alexbatalov/fallout1-ce/
COMMENT=	Re-implementation of Fallout for modern operating systems
#LICENSE=	# TODO: (see mk/license.mk) # Sustainable Use License 1.0

USE_LANGUAGES=	c c++

INSTALLATION_DIRS+=	bin
INSTALL_TARGET=		${BUILD_TARGET}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${CMAKE_BUILD_DIR}/fallout-ce ${DESTDIR}${PREFIX}/bin/

.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
