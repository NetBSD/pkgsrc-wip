# $NetBSD$
#

# use date of commit as has no version only a tag.

DISTNAME=	SSVEntitySystem
PKGNAME=	${DISTNAME}-20130714
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=SuperV1234/}
GITHUB_TAG=	8123beabe3bc8ffe91cb94e6ba061254f3bba18b

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/SuperV1234/SSVEntitySystem
COMMENT=	C++14 simple entity/component system for realtime games
LICENSE=	afl-3.0

USE_LANGUAGES=	c c++14
USE_CMAKE=	yes

CMAKE_ARGS+=	-DBUILD_SHARED_LIB:BOOL=OFF
CMAKE_ARGS+=	-DMODULE_PATH=${BUILDLINK_DIR}/lib/cmake

INSTALLATION_DIRS+=	include/${PKGBASE} lib/cmake

post-install:
	${INSTALL_DATA} ${WRKSRC}/cmake/modules/Find${PKGBASE}.cmake \
		${DESTDIR}${PREFIX}/lib/cmake/

.include "../../wip/SSVUtils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
