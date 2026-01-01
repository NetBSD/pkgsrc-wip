# $NetBSD$

GITHUB_PROJECT=	libnest2d
GITHUB_TAG=	4.11.0
DISTNAME=	${GITHUB_TAG}
PKGNAME=	${GITHUB_PROJECT}-ultimaker-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=Ultimaker/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Ultimaker/libnest2d/
COMMENT=	2D irregular bin packaging and nesting library written in modern C++
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		cmake_modules/FindClipper.cmake
SUBST_FILES.fix-paths+=		cmake_modules/FindNLopt.cmake
SUBST_SED.fix-paths=		-e "s,@prefix@,${PREFIX},g"

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../wip/nlopt/buildlink3.mk"
.include "../../wip/polyclipping/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
