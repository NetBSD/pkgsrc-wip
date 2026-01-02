# $NetBSD: $

VERSION=	6.10.1
DISTNAME=	pyside-setup-everywhere-src-${VERSION}
PKGNAME=	${PYPKGPREFIX}-pyside6-${VERSION}
MASTER_SITES=	https://download.qt.io/official_releases/QtForPython/pyside6/PySide6-${VERSION}-src/

EXTRACT_SUFX=	.tar.xz
CATEGORIES=	x11

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.qt.io/Qt_for_Python
COMMENT=	Qt6 bindings for Python
LICENSE=	gnu-gpl-v2

USE_TOOLS+=			pkg-config bash
USE_LANGUAGES+=			c c++
CMAKE_CONFIGURE_ARGS+=		-DCMAKE_INSTALL_PREFIX:STRING="${PREFIX}"

PLIST_SUBST+=	PYSITELIB=${PYSITELIB}
PLIST_SUBST+=	PYTHON_VERSION=${PYTHON_VERSION}

REPLACE_PYTHON+=	sources/pyside-tools/pyside_tool.py
REPLACE_PYTHON+=	sources/pyside-tools/qtpy2cpp_lib/tests/baseline/basic_test.py
REPLACE_PYTHON+=	sources/shiboken6/shiboken_tool.py

SUBST_CLASSES+=		bash
SUBST_MESSAGE.bash=	Replace bash path in cmake generated wrapper
SUBST_STAGE.bash=	post-extract
SUBST_FILES.bash=	sources/shiboken6/cmake/ShibokenHelpers.cmake
SUBST_SED.bash=		-e "s|\#!/bin/bash|\#!${BASH}|g"

.include "../../devel/cmake/build.mk"

.include "../../audio/qt6-qtspeech/buildlink3.mk"
.include "../../comms/qt6-qtconnectivity/buildlink3.mk"
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../geography/qt6-qtlocation/buildlink3.mk"
.include "../../geography/qt6-qtpositioning/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/qt6-qt3d/buildlink3.mk"
.include "../../graphics/qt6-qtcharts/buildlink3.mk"
.include "../../graphics/qt6-qtdatavis3d/buildlink3.mk"
.include "../../graphics/qt6-qtquick3d/buildlink3.mk"
.include "../../lang/clang/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/qt6-qtscxml/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../misc/qt6-qtsensors/buildlink3.mk"
.include "../../multimedia/qt6-qtmultimedia/buildlink3.mk"
.include "../../net/qt6-qtremoteobjects/buildlink3.mk"
.include "../../net/qt6-qtwebsockets/buildlink3.mk"
.include "../../security/qt6-qtnetworkauth/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../www/qt6-qthttpserver/buildlink3.mk"
.include "../../www/qt6-qtwebchannel/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../x11/qt6-qtserialport/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
