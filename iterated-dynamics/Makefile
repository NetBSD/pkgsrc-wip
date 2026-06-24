# $NetBSD$

DISTNAME=	iterated-dynamics-1.4.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=LegalizeAdulthood/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/LegalizeAdulthood/iterated-dynamics/
COMMENT=	Fractal renderer with support for many fractal types
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	cpuid-[0-9]*:../../sysutils/cpuid

USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DBUILD_TESTING=OFF
# suggested by documentation, but:
# CMake Error: Unknown argument --workflow
#CMAKE_CONFIGURE_ARGS+=	--workflow --preset default

.include "../../devel/cmake/build.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/googletest/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../textproc/fmtlib/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
