# $NetBSD$

DISTNAME=	rawgl-0.2.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=cyxx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cyxx/rawgl/
COMMENT=	Re-implementation of the engine used in the game Another World
#LICENSE=	# TODO: (see mk/license.mk)

GIT_REPOSITORIES=	rawgl
GIT_REPO.rawgl=		git://github.com/cyxx/rawgl.git
WRKSRC=			${WRKDIR}/rawgl/

USE_LANGUAGES=	c++

BUILD_TARGET=		rawgl

INSTALLATION_DIRS=	bin share/doc/rawgl

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rawgl ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README.md \
		${DESTDIR}${PREFIX}/share/doc/rawgl

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
