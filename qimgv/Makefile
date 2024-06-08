# $NetBSD$

DISTNAME=	qimgv-1.0.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=easymodo/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/easymodo/qimgv/
COMMENT=	Fast and easy to use image viewer
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c++
USE_TOOLS+=	pkg-config

.include "../../devel/cmake/build.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/opencv/buildlink3.mk"
.include "../../multimedia/mpv/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
