# $NetBSD: Makefile,v 1.19 2024/11/14 22:22:24 wiz Exp $

DISTNAME=	pyqt6_webengine-${PKGVERSION_NOREV}
PKGNAME=	${PYPKGPREFIX}-qt6-webengine-6.9.0
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyQt6-WebEngine/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.riverbankcomputing.com/software/pyqtwebengine/
COMMENT=	Python module for QtWebEngine (Chromium-based)
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-sip6-[0-9]*:../../x11/py-sip6
TOOL_DEPENDS+=	${PYPKGPREFIX}-qt-builder-[0-9]*:../../x11/py-qt-builder
DEPENDS+=	${PYPKGPREFIX}-qt6-[0-9]*:../../x11/py-qt6

USE_LANGUAGES=	c c++

WHEEL_ARGS+=	-C=--verbose

pre-configure:
	${LN} -sf ${QTDIR}/bin/qmake ${BUILDLINK_DIR}/bin/

.include "../../lang/python/wheel.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../geography/qt6-qtlocation/buildlink3.mk"
.include "../../www/qt6-qtwebchannel/buildlink3.mk"
.include "../../wip/qt6-qtwebengine/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
