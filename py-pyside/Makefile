# $NetBSD: Makefile,v 1.1 2013/11/15 12:16:48 rhialto Exp $

VERSION=	1.2.1
QTVERSION=	4.8
DISTNAME=	pyside-qt${QTVERSION}+${VERSION}
PKGNAME=	${PYPKGPREFIX}-pyside-qt${QTVERSION}-${VERSION}
MASTER_SITES=	http://download.qt-project.org/official_releases/pyside/
EXTRACT_SUFX=   .tar.bz2
CATEGORIES=	devel

MAINTAINER=	rhialto@falu.nl
HOMEPAGE=	http://qt-project.org/wiki/Category:LanguageBindings::PySide
COMMENT=	Pyside Qt bindings for Python
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake cmake pkg-config
USE_LANGUAGES+=	c c++
USE_CMAKE=	yes
CMAKE_ARGS+=    -DCMAKE_INSTALL_PREFIX:STRING="${PREFIX}"

BUILDLINK_DEPMETHOD.qt4-tools=	full

PLIST_SUBST+=   PYSITELIB=${PYSITELIB}
PLIST_SUBST+=   PYVERSSUFFIX=${PYVERSSUFFIX}

pre-configure:
	cd ${WRKSRC} && ${MKDIR} build

do-configure:
	cd ${WRKSRC}/build && ${SETENV} ${CONFIGURE_ENV} ${CMAKE} ${CMAKE_ARGS} ..

do-build:
	cd ${WRKSRC}/build && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM}

do-install:
	cd ${WRKSRC}/build && ${SETENV} ${INSTALL_ENV} ${MAKE_PROGRAM} ${INSTALL_TARGET}

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../wip/py-pyside-shiboken/buildlink3.mk"
.include "../../lang/python/extension.mk"

.include "../../mk/bsd.pkg.mk"
