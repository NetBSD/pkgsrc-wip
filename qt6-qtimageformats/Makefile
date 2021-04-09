# $NetBSD$

DISTNAME=	qtimageformats-everywhere-src-${QTVERSION}
PKGNAME=	qt6-qtimageformats-${QTVERSION}
COMMENT=	Extra image handlers for Qt6
CATEGORIES=	graphics

QT_ADDLIB=	yes
.include "../../wip/qt6-qtbase/Makefile.common"

post-extract:
	${CP} ${FILESDIR}/FindWrapMNG.cmake ${WRKSRC}/cmake

.include "../../graphics/jasper/buildlink3.mk"
.include "../../graphics/mng/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../wip/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
