# $NetBSD$

DISTNAME=	qtimageformats-everywhere-src-${QTVERSION}
PKGNAME=	qt5-qtimageformats-${QTVERSION}
COMMENT=	Qt5 module for Image formats

BUILD_TARGET=		sub-src
MAKE_ENV+=		QTDIR=${QTDIR}

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

post-extract:
	${RM} -r ${WRKSRC}/src/3rdparty/jasper*

.include "../../wip/qt5-qtbase/Makefile.common"

.include "../../archivers/xz/buildlink3.mk"
.include "../../graphics/jasper/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/mng/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../wip/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
