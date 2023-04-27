# $NetBSD$

GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	raptor-0.8.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=skynettx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/skynettx/raptor/
COMMENT=	Source port for Raptor Call Of The Shadows
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/doc/raptor
INSTALLATION_DIRS+=	share/examples/raptor
INSTALL_TARGET=		${BUILD_TARGET}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${CMAKE_BUILD_DIR}/bin/raptor ${DESTDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/raptor/
	${INSTALL_DATA} ${WRKSRC}/SETUP* ${DESTDIR}${PREFIX}/share/examples/raptor/

.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
