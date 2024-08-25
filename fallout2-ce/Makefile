# $NetBSD$

GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	fallout2-ce-1.2.0
DISTFILES=	${DEFAULT_DISTFILES} fpattern-1.9.tar.gz 
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=alexbatalov/}
SITES.fpattern-1.9.tar.gz= \
		-https://github.com/Loadmaster/fpattern/archive/refs/tags/v1.9.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/alexbatalov/fallout2-ce/
COMMENT=	Re-implementation of Fallout 2 for modern operating systems
#LICENSE=	# TODO: (see mk/license.mk) # Sustainable Use License 1.0

USE_LANGUAGES=	c c++

INSTALLATION_DIRS+=	bin
INSTALL_TARGET=		${BUILD_TARGET}

CMAKE_CONFIGURE_ARGS+=	-Dfpattern_SOURCE_DIR=${WRKDIR}/fpattern-1.9

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${CMAKE_BUILD_DIR}/fallout2-ce ${DESTDIR}${PREFIX}/bin/

.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
