# $NetBSD: Makefile,v 1.71 2021/12/08 16:07:11 adam Exp $

VERSION=	5.15.2
DISTNAME=	pyside-setup-opensource-src-${VERSION}
PKGNAME=	${PYPKGPREFIX}-Side2-${VERSION}
CATEGORIES=	x11 python
#MASTER_SITES=	${MASTER_SITE_PYPI:=P/PySide2/}
MASTER_SITES=	https://download.qt.io/official_releases/QtForPython/pyside2/PySide2-${VERSION}-src/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Python binding for Qt5
HOMEPAGE=	https://www.pyside.org/
#LICENSE=	some kind of GPL

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
.endif
.include "../../lang/python/egg.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtcharts/buildlink3.mk"
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtlocation/buildlink3.mk"
.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.include "../../x11/qt5-qtsensors/buildlink3.mk"
.include "../../x11/qt5-qtserialport/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.if ${OPSYS} == "Darwin"
.  include "../../x11/qt5-qtmacextras/buildlink3.mk"
.else
# currently qt5-qtwebkit does not build on Darwin
PLIST.webkit=	yes
.  include "../../x11/qt5-qtwebkit/buildlink3.mk"
.  include "../../x11/qt5-qtx11extras/buildlink3.mk"
.endif
.include "../../x11/qt5-qtwebchannel/buildlink3.mk"
.include "../../x11/qt5-qtwebsockets/buildlink3.mk"
.include "../../x11/qt5-qtxmlpatterns/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
