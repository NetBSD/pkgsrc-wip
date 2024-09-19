# $NetBSD$

DISTNAME=	smplayer-19.1.0
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=smplayer/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://smplayer.sourceforge.net/
COMMENT=	Free open source media player
LICENSE=	gnu-gpl-v2 AND modified-bsd

DEPENDS+=	mpv>=0.29.1:../../multimedia/mpv

USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	zlib/zlib.pc.in
PKGCONFIG_OVERRIDE+=	zlib/contrib/minizip/minizip.pc.in

BUILD_TARGET=		src/smplayer
QMAKE=			${QTDIR}/bin/qmake
LRELEASE=		${QTDIR}/bin/lrelease
MAKE_ENV+=		QMAKE=${QMAKE}
BUILD_MAKE_FLAGS+=	QMAKE=${QMAKE} PREFIX=${PREFIX} LRELEASE=${LRELEASE}
INSTALL_MAKE_FLAGS+=	PREFIX=${PREFIX}

SUBST_CLASSES+=		dirs
SUBST_FILES.dirs=	Makefile
SUBST_MESSAGE.dirs=	Fixing documentation directory and PKGMANDIR.
SUBST_SED.dirs=		-e "s|share/man|${PKGMANDIR}|g"
SUBST_SED.dirs+=	-e "s|doc/packages|doc|1"
SUBST_STAGE.dirs=	pre-build

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_SED.paths+=	-e 's,/usr/local,${PREFIX},g'
SUBST_FILES.paths+=	Makefile
SUBST_MESSAGE.paths=	Fixing header search paths.

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qt5-qtscript/buildlink3.mk"
#.include "../../x11/qt5-qtwebkit/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
