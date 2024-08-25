# $NetBSD$

GITHUB_PROJECT=	neovim-qt
GITHUB_TAG=	refs/tags/staging
DISTNAME=	staging
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
CATEGORIES=	editors x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=equalsraf/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/equalsraf/neovim-qt/
COMMENT=	Neovim client library and GUI, in Qt5
LICENSE=	isc

WRKSRC=		${WRKDIR}/neovim-qt-${DISTNAME}
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_INSTALL_PREFIX=${PREFIX}
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_CONFIGURE_ARGS+=	-DUSE_SYSTEM_MSGPACK=ON

pre-configure:
	${MKDIR} -p ${WRKSRC}/build

DEPENDS+=	neovim-[0-9]*:../../wip/neovim

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../devel/msgpack/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
