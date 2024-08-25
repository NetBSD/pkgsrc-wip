# $NetBSD$

DISTNAME=	Descent3-1.5.0-Source
PKGNAME=	descent3-1.5.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=DescentDevelopers/Descent3/releases/download/v1.5.0/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/DescentDevelopers/Descent3
COMMENT=	Descent 3 open source engine
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

CMAKE_CONFIGURE_ARGS+=		-DFORCE_PORTABLE_INSTALL:BOOL=Off
CMAKE_CONFIGURE_ARGS+=		-DCMAKE_INSTALL_DATADIR:PATH=${PREFIX}/share/Descent3
CMAKE_CONFIGURE_ARGS+=		-DCMAKE_INSTALL_LIBDIR:PATH=${PREFIX}/lib/Descent3
CMAKE_USE_GNU_INSTALL_DIRS=	no

.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
