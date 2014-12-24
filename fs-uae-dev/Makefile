# $NetBSD: Makefile,v 1.7 2014/12/24 20:17:47 rhialto Exp $

VERSION=	2.5.22dev
DISTNAME=	fs-uae-${VERSION}
CATEGORIES=	emulators
MASTER_SITES=	http://fs-uae.net/fs-uae/devel/${VERSION}/

MAINTAINER=	rhialto@falu.nl
HOMEPAGE=	http://fs-uae.net/
COMMENT=	FS-UAE Amiga Emulator
LICENSE=	gnu-gpl-v2

#USE_TOOLS+=	gmake
USE_TOOLS+=	pkg-config
USE_TOOLS+=	autoheader automake autoconf
USE_LANGUAGES+=	c c++
GNU_CONFIGURE=	yes
#MAKE_JOBS_SAFE= no
#WRKSRC=		${WRKDIR}/fs-uae-2.5.8dev
# The default value of WRKSRC is ${WRKDIR}/${DISTNAME}.

PKG_CFLAGS=	-I${BUILDLINK_PREFIX.openal}/include
PKG_LDFLAGS=	${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openal}/lib
PKG_LDFLAGS+=	-L${BUILDLINK_PREFIX.openal}/lib

BUILD_ENV+=	X11_CFLAGS=-I${BUILDLINK_PREFIX.libX11}/include
BUILD_ENV+=	X11_LDFLAGS=${X11_LDFLAGS}
BUILD_ENV+=	PKG_CFLAGS=${PKG_CFLAGS}
BUILD_ENV+=	PKG_LDFLAGS=${PKG_LDFLAGS}

INSTALL_ENV+=	prefix=${PREFIX}
INSTALL_ENV+=	DESTDIR=${DESTDIR}

#pre-configure:
#	cd ${WRKSRC} && ./bootstrap.sh

# My notes say that building fails on NetBSD 6.0 and that 6.1 headers
# are required.

#BUILD_DEPENDS+=              python34>=3:../../lang/python34

.include "../../audio/openal/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
#.include "../../multimedia/libmpeg2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libX11/buildlink3.mk"

# This does not include fs-uae-launcher any more.
# See its own pkgsrc/wip entry.

.include "../../mk/bsd.pkg.mk"
