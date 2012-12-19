# $NetBSD: Makefile,v 1.1 2012/12/19 15:47:11 othyro Exp $
#

DISTNAME=	smplayer-0.8.2.1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=smplayer/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://smplayer.sourceforge.net/
COMMENT=	Free open source media player
LICENSE=	gnu-gpl-v2 AND modified-bsd

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

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
