# $NetBSD: Makefile,v 1.1 2013/11/15 12:14:47 rhialto Exp $

VERSION=	0.2.15
DISTNAME=	tools-${VERSION}
PKGNAME=	${PYPKGPREFIX}-pyside-tools-${VERSION}
MASTER_SITES=	${MASTER_SITE_GITHUB:=PySide/}
GITHUB_PROJECT=	Tools
EXTRACT_SUFX=	.tar.gz
CATEGORIES=	devel

MAINTAINER=	rumko@netbsd.org
HOMEPAGE=	http://qt-project.org/wiki/Get-PySide
COMMENT=	Pyside tools
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/Tools-${VERSION}

USE_TOOLS+=	gmake cmake pkg-config
USE_LANGUAGES+=	c c++
USE_CMAKE=	yes
CMAKE_ARGS+=	-DCMAKE_INSTALL_PREFIX:STRING="${PREFIX}"

REPLACE_PYTHON+=	pyside-uic

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../wip/py-pyside-shiboken/buildlink3.mk"
.include "../../wip/py-pyside/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"

PLIST_SUBST+=	PYSITELIB=${PYSITELIB}
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

pre-configure:
	cd ${WRKSRC} && ${MKDIR} build

do-configure:
	cd ${WRKSRC}/build && ${SETENV} ${CONFIGURE_ENV} ${CMAKE} ${CMAKE_ARGS} ..

do-build:
	cd ${WRKSRC}/build && ${SETENV} ${MAKE_ENV:Q} ${MAKE_PROGRAM}

do-install:
	cd ${WRKSRC}/build && ${SETENV} ${INSTALL_ENV} ${MAKE_PROGRAM} ${INSTALL_TARGET}

.include "../../mk/bsd.pkg.mk"
