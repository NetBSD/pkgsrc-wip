# $NetBSD: Makefile,v 1.12 2015/04/15 22:03:05 rhialto Exp $

VERSION=	2.5.29dev
DISTNAME=	fs-uae-launcher-${VERSION}
CATEGORIES=	emulators
MASTER_SITES=	http://fs-uae.net/fs-uae/devel/${VERSION}/

MAINTAINER=	rhialto@falu.nl
HOMEPAGE=	http://fs-uae.net/
COMMENT=	Graphical launcher for FS-UAE, the Amiga Emulator
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake

INSTALL_ENV+=	prefix=${PREFIX}
INSTALL_ENV+=	DESTDIR=${DESTDIR}
INSTALL_ENV+=	PYTHONBIN=${PYTHONBIN}

# Imports urllib.parse which is 3+.
PYTHON_VERSIONS_INCOMPATIBLE=	27

REPLACE_PYTHON+=fs_uae_launcher/netplay/oyoyo/examplebot.py
REPLACE_PYTHON+=OpenGL/arrays/_buffers.py
REPLACE_PYTHON+=OpenGL/arrays/buffers.py

PLIST_SUBST+=   PYVERSSUFFIX=${PYVERSSUFFIX}	# 3.4
PLIST_SUBST+=   PYVERS=${PYPKGPREFIX:S/py//}	# py34 -> 34
PLIST_SUBST+=   VERSION=${VERSION}

DEPENDS+=	${PYPKGPREFIX}-setuptools>=1.1.5:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-qt4>=4.10.2nb1:../../x11/py-qt4
DEPENDS+=	${PYPKGPREFIX}-sqlite3>=1:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-lhafile>=0:../../wip/py-lhafile

pre-install:
	cd ${WRKSRC:Q}; ${PYTHONBIN:Q} setup.py install --prefix=${PREFIX:Q} --root=${DESTDIR:Q} --install-lib=${PREFIX:Q}/share/fs-uae-launcher --install-scripts=${PREFIX:Q}/share/fs-uae-launcher

post-install:
	${INSTALL_PROGRAM_DIR} ${DESTDIR}/${PREFIX}/bin
	cd ${DESTDIR}/${PREFIX}/bin; { echo "#!/bin/sh"; echo "exec ${PREFIX}/bin/fs-uae-launcher --fs-uae-arcade"; } > fs-uae-arcade; chmod +x fs-uae-arcade

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
