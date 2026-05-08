# $NetBSD$

#.include "../../meta-pkgs/lxqt/Makefile.common"

DISTNAME=	lxqt-clip-2.4.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=lxqt/}
#GITHUB_RELEASE=	${PKGVERSION_NOREV}
#EXTRACT_SUFX=	.tar.xz
GITHUB_TAG=	cbf818b0aaa9523e7cdb8b58e0d3951660aae916

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/
COMMENT=	Clipboard history applet
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		pkg-config perl
USE_LANGUAGES=		c c++
USE_CXX_FEATURES=	c++20

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_INSTALL_PREFIX=${PREFIX}

#TOOL_DEPENDS+=	qt6-qttools-[0-9]*:../../devel/qt6-qttools

.include "../../devel/cmake/build.mk"
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../x11/kf6-kguiaddons/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
