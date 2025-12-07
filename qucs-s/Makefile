# $NetBSD$

DISTNAME=	qucs-s-25.2.0
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=ra3xdh/}
GITHUB_PROJECT=	qucs_s
GITHUB_RELEASE=	25.2.0
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	ea1abz@gmail.com
HOMEPAGE=	https://github.com/ra3xdh/qucs_s/
COMMENT=	Circuit simulation program based on Qucs circuit simulator
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS+=	bison cmake
TOOL_DEPENDS+=	dos2unix-[0-9]*:../../converters/dos2unix
TOOL_DEPENDS+=	gperf-[0-9]*:../../devel/gperf

CMAKE_CONFIGURE_ARGS+=	-DBISON_DIR=${PREFIX}/bin


.include "../../devel/cmake/build.mk"
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../graphics/qt6-qtsvg/buildlink3.mk"
.include "../../graphics/qt6-qtcharts/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
