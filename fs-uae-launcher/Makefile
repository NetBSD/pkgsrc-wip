# $NetBSD: Makefile,v 1.1 2013/11/15 12:23:21 rhialto Exp $

VERSION=	2.3.9dev
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

REPLACE_PYTHON+=fs_uae_launcher/netplay/oyoyo/examplebot.py

PLIST_SUBST+=   PYSITELIB=${PYSITELIB}
PLIST_SUBST+=   PYVERSSUFFIX=${PYVERSSUFFIX}

DEPENDS+=	${PYPKGPREFIX}-pyside-qt4.8>=1.2.1:../../wip/py-pyside
# Launcher build (actually binary package create)-only:
DEPENDS+=	${PYPKGPREFIX}-setuptools>=1.1.5:../../devel/py-setuptools

pre-install:
	cd ${WRKSRC:Q}; ${PYTHONBIN:Q} setup.py install --prefix=${PREFIX:Q} --root=${DESTDIR:Q} --install-lib=${PREFIX:Q}/share/fs-uae-launcher --install-scripts=${PREFIX:Q}/share/fs-uae-launcher

post-install:
	${INSTALL_PROGRAM_DIR} ${DESTDIR}/${PREFIX}/bin
	cd ${DESTDIR}/${PREFIX}/bin; ln -s ../share/fs-uae-launcher/fs-uae-launcher .

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
