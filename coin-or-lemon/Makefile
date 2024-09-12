# $NetBSD$

DISTNAME=	lemon-1.3.1
PKGNAME=	coin-or-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	http://lemon.cs.elte.hu/pub/sources/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lemon.cs.elte.hu/trac/lemon
COMMENT=	Library for Efficient Modeling and Optimization in Networks
LICENSE=	boost-license

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
CXXFLAGS+=	-fpermissive
GCC_REQD+=	13

REPLACE_SH=	tools/lemon-0.x-to-1.x.sh

PKGCONFIG_OVERRIDE+=	lemon/lemon.pc.in

CMAKE_CONFIGURE_ARGS+=	-DLEMON_ENABLE_SOPLEX=NO
CMAKE_CONFIGURE_ARGS+=	-DLEMON_ENABLE_ILOG=NO
CMAKE_CONFIGURE_ARGS+=	-DLEMON_ENABLE_GLPK=NO
CMAKE_CONFIGURE_ARGS+=	-DLEMON_ENABLE_COIN=YES

.include "../../math/coinmp/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
