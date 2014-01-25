# $NetBSD: Makefile,v 1.2 2014/01/25 10:38:12 thomasklausner Exp $

VERSION=	2.2.3
DISTNAME=	fs-uae-${VERSION}
CATEGORIES=	emulators
MASTER_SITES=	http://fs-uae.net/fs-uae/stable/${VERSION}/

MAINTAINER=	rhialto@falu.nl
HOMEPAGE=	http://fs-uae.net/
COMMENT=	FS-UAE Amiga Emulator
LICENSE=	gnu-gpl-v2

MAKE_JOBS_SAFE=	no

USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES+=	c c++
NO_CONFIGURE=	yes

PKG_CFLAGS=	-I${BUILDLINK_PREFIX.openal}/include
PKG_LDFLAGS=	${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openal}/lib
PKG_LDFLAGS+=	-L${BUILDLINK_PREFIX.openal}/lib

BUILD_ENV+=	X11_CFLAGS=-I${BUILDLINK_PREFIX.libX11}/include
BUILD_ENV+=	X11_LDFLAGS=${X11_LDFLAGS}
BUILD_ENV+=	PKG_CFLAGS=${PKG_CFLAGS}
BUILD_ENV+=	PKG_LDFLAGS=${PKG_LDFLAGS}

INSTALL_ENV+=	prefix=${PREFIX}
INSTALL_ENV+=	DESTDIR=${DESTDIR}

.include "../../audio/openal/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libX11/buildlink3.mk"

# Stuff below here is for fs-uae-launcher.

REPLACE_PYTHON+=launcher/fs_uae_launcher/netplay/oyoyo/examplebot.py

.include "../../lang/python/application.mk"
PLIST_SUBST+=   PYSITELIB=${PYSITELIB}
PYTHON_VERSIONS_INCOMPATIBLE=	33 # py-wxWidgets

DEPENDS+=	${PYPKGPREFIX}-game>=1.8.1:../../devel/py-game
DEPENDS+=	${PYPKGPREFIX}-wxWidgets>=2.8.10:../../x11/py-wxWidgets
# Launcher build (actually binary package create)-only:
DEPENDS+=	${PYPKGPREFIX}-setuptools>=1.1.5:../../devel/py-setuptools

# Install the launcher after the main program,
post-install:
	cd ${WRKSRC}/launcher; ${PYTHONBIN} setup.py install --prefix=${PREFIX:Q} --root=${DESTDIR:Q}

.include "../../mk/bsd.pkg.mk"
