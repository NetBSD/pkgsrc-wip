# $NetBSD: Makefile,v 1.1 2013/11/15 12:14:47 rhialto Exp $

VERSION=	1.2.1
DISTNAME=	shiboken-${VERSION}
PKGNAME=	${PYPKGPREFIX}-pyside-shiboken-${VERSION}
MASTER_SITES=	http://download.qt-project.org/official_releases/pyside/
EXTRACT_SUFX=   .tar.bz2
CATEGORIES=	devel

MAINTAINER=	rhialto@falu.nl
HOMEPAGE=	http://qt-project.org/wiki/Get-PySide
COMMENT=	Pyside (shiboken prerequisite)
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake cmake pkg-config
USE_LANGUAGES+=	c c++
USE_CMAKE=	yes
CMAKE_ARGS+=    -DCMAKE_INSTALL_PREFIX:STRING="${PREFIX}"

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../lang/python/extension.mk"

PLIST_SUBST+=   PYSITELIB=${PYSITELIB}
PLIST_SUBST+=   PYVERSSUFFIX=${PYVERSSUFFIX}

pre-configure:
	cd ${WRKSRC} && ${MKDIR} build

do-configure:
	cd ${WRKSRC}/build && ${SETENV} ${CONFIGURE_ENV} ${CMAKE} ${CMAKE_ARGS} ..

do-build:
	cd ${WRKSRC}/build && ${SETENV} ${MAKE_ENV:Q} ${MAKE_PROGRAM}

do-install:
	cd ${WRKSRC}/build && ${SETENV} ${INSTALL_ENV} ${MAKE_PROGRAM} ${INSTALL_TARGET}

.include "../../mk/bsd.pkg.mk"
