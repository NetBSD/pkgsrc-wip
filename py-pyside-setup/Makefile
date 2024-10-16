# $NetBSD: $

VERSION=	5.15.15
DISTNAME=	pyside-setup-opensource-src-${VERSION}
PKGNAME=	${PYPKGPREFIX}-pyside-setup-${VERSION}
MASTER_SITES=	https://download.qt.io/official_releases/QtForPython/pyside2/PySide2-${VERSION}-src/

EXTRACT_SUFX=	.tar.xz
CATEGORIES=	x11

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.qt.io/Qt_for_Python
COMMENT=	Qt for Python
LICENSE=	gnu-gpl-v2

#WRKSRC=		${WRKDIR}/PySide-${VERSION}

USE_TOOLS+=		pkg-config
USE_LANGUAGES+=		c c++
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_INSTALL_PREFIX:STRING="${PREFIX}"

PLIST_SUBST+=	PYSITELIB=${PYSITELIB}
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

.include "../../devel/cmake/build.mk"

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
#.include "../../x11/qt5-qtcharts/buildlink3.mk"
.include "../../x11/qt5-qtquickcontrols/buildlink3.mk"
.include "../../x11/qt5-qtquickcontrols2/buildlink3.mk"
.include "../../x11/qt5-qtscript/buildlink3.mk"
.include "../../x11/qt5-qtscxml/buildlink3.mk"
.include "../../x11/qt5-qtserialport/buildlink3.mk"
#.include "../../x11/qt5-qtspeech/buildlink3.mk"
#.include "../../x11/qt5-qtwebengine/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../lang/clang/buildlink3.mk"
.include "../../lang/python/extension.mk"

.include "../../mk/bsd.pkg.mk"
