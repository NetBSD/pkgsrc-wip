# $NetBSD$

DISTNAME=	kdelibs-1.1.2
CATEGORIES=	x11
MASTER_SITES=	http://nishi.boats/

MAINTAINER=	nishi@nishi.boats
HOMEPAGE=	https://github.com/nishiowo/kde1-kdelibs
COMMENT=	KDE library for 1.x
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2

DEPENDS+=	qt1-[0-9]*:../../wip/qt1

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

.include "../../devel/cmake/build.mk"
.include "../../wip/qt1/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
