# $NetBSD$

DISTNAME=	qt1-1.45
CATEGORIES=	x11
MASTER_SITES=	http://nishi.boats/

MAINTAINER=	nishi@nishi.boats
HOMEPAGE=	https://github.com/nishiowo/qt1
COMMENT=	QT version 1
LICENSE=	qpl-v1.0

CMAKE_CONFIGURE_ARGS=	-DBYACC_EXECUTABLE=/usr/bin/yacc

USE_TOOLS+=	pkg-config

USE_LANGUAGES=	c c++

.include "../../devel/cmake/build.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
