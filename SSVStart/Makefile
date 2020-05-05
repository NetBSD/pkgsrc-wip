# $NetBSD$
#

# use date of commit as has no version only a tag

DISTNAME=	SSVStart
PKGNAME=	${DISTNAME}-20130714
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=SuperV1234/}
GITHUB_TAG=	112229f184f5e4cf88c71fe67b4588806d290f71

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/SuperV1234/SSVStart
COMMENT=	C++14 SFML2.0 application/game development framework
LICENSE=	afl-3.0

USE_LANGUAGES=	c c++14
USE_CMAKE=	yes

CMAKE_ARGS+=	-DBUILD_SHARED_LIB:BOOL=OFF
CMAKE_ARGS+=	-DMODULE_PATH=${BUILDLINK_DIR}/lib/cmake

INSTALLATION_DIRS+=	include/${PKGBASE} lib/cmake

post-install:
	${INSTALL_DATA} ${WRKSRC}/cmake/modules/Find${PKGBASE}.cmake \
		${DESTDIR}${PREFIX}/lib/cmake/

.include "../../wip/sfml+/buildlink3.mk"
.include "../../wip/SSVJsonCpp/buildlink3.mk"
.include "../../wip/SSVUtils/buildlink3.mk"
.include "../../wip/SSVUtilsJson/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
