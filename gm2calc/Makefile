# $NetBSD$

DISTNAME=	gm2calc-1.7.1
GITHUB_PROJECT=	GM2Calc
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=GM2Calc/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://gm2calc.hepforge.org/
COMMENT=	Calculation of the anomalous magnetic moment of the muon
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/GM2Calc-1.7.1

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	cmake/gm2calc.pc.in

# C++ compiler (g++ >= 4.6.3 or clang++ >= 3.4)
# MESSAGE(FATAL_ERROR "GCC 4.6+ is required.")
GCC_REQD+=	4.6

CMAKE_ARGS+=	-Mathematica=off

DEPENDS+=	doxygen>=1.8.20:../../devel/doxygen

BUILDLINK_API_DEPENDS.boost-headers+=   boost-headers-1.75.*
.include "../../devel/boost-headers/buildlink3.mk"
BUILDLINK_API_DEPENDS.eigen3+=  eigen3>=3.1.2
.include "../../math/eigen3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
