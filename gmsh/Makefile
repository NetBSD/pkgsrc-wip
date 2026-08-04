# $NetBSD$

PKGNAME=	gmsh-4.15.2
DISTNAME=	${PKGNAME}-source
CATEGORIES=	math
MASTER_SITES=	https://gmsh.info/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gmsh.info/src/
COMMENT=	Three-dimensional finite element mesh generator
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++ fortran

USE_CC_FEATURES=	c99
USE_CXX_FEATURES=	c++14

PKGCONFIG_OVERRIDE+=	contrib/eigen/eigen3.pc.in

.include "../../devel/cmake/build.mk"
.include "../../x11/fltk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
