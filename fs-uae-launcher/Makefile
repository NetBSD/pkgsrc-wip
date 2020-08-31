# $NetBSD$

VERSION=	2.9.7dev2
DISTNAME=	fs-uae-launcher-${VERSION}
CATEGORIES=	emulators
MASTER_SITES=	https://fs-uae.net/fs-uae/devel/${VERSION}/
#MASTER_SITES=	https://fs-uae.net/stable/${VERSION}/

MAINTAINER=	rhialto@falu.nl
HOMEPAGE=	https://fs-uae.net/
COMMENT=	Graphical launcher for FS-UAE, the Amiga Emulator
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake

INSTALL_ENV+=	prefix=${PREFIX}
INSTALL_ENV+=	DESTDIR=${DESTDIR}
INSTALL_ENV+=	PYTHONBIN=${PYTHONBIN}

# Imports urllib.parse which is 3+.
# byte-compiling /pkg_comp/obj/pkgsrc/wip/fs-uae-launcher/default/.destdir/usr/pkg/share/fs-uae-launcher/OpenGL/GL/SGIX/async.py to async.cpython-37.pyc
#   File "/usr/pkg/share/fs-uae-launcher/OpenGL/GL/SGIX/async.py", line 58
#       from OpenGL.raw.GL.SGIX.async import *
#                                       ^
#                                       SyntaxError: invalid syntax
# (async keyword is new in python 3.7)
PYTHON_VERSIONS_INCOMPATIBLE=	27 37

REPLACE_PYTHON+=	OpenGL/arrays/_buffers.py
REPLACE_PYTHON+=	OpenGL/arrays/buffers.py

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}	# 3.5
PLIST_SUBST+=	PYVERS=${PYPKGPREFIX:S/py//}	# py35 -> 35
PLIST_SUBST+=	VERSION=${VERSION}

#DEPENDS+=	${PYPKGPREFIX}-qt4>=4.10.2nb1:../../x11/py-qt4
# when building with qt5 it should co-exist with calibre and qbzr.
DEPENDS+=	${PYPKGPREFIX}-qt5>=5.4:../../x11/py-qt5
DEPENDS+=	${PYPKGPREFIX}-sqlite3>=1:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-lhafile>=0:../../archivers/py-lhafile

PYTHON_VERSIONED_DEPENDENCIES+=	setuptools

# Use the normal "gmake install" to install; not setup.py via "../../lang/python/extension.mk".

post-install:
	${INSTALL_PROGRAM_DIR} ${DESTDIR}/${PREFIX}/bin
	cd ${DESTDIR}/${PREFIX}/bin; { ${ECHO} "#!/bin/sh"; ${ECHO} "exec ${PREFIX}/bin/fs-uae-launcher --fs-uae-arcade"; } > fs-uae-arcade; chmod +x fs-uae-arcade

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
