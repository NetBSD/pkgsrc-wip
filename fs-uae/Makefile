# $NetBSD: Makefile,v 1.6 2014/07/13 17:18:39 rhialto Exp $

VERSION=	2.4.1
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

.include "../../mk/bsd.pkg.mk"
