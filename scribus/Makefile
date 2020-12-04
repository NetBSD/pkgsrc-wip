# $NetBSD$

DISTNAME=	scribus-1.5.5
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scribus/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.scribus.net/
COMMENT=	Desktop publishing software
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qttools

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++11

# C++11
GCC_REQD+=	4.7

CMAKE_ARGS+=	-Wno-dev

.for component in Core Widgets Gui Xml Network Xml OpenGL LinguistTools PrintSupport
CMAKE_ARGS+=	-DQt5${component}_DIR=${QTDIR}/lib/cmake/Qt5${component}
.endfor

CMAKE_ARGS+=	-DCAIRO_DIR=${WRKSRC}/cmake/modules
CMAKE_ARGS+=	-DFONTCONFIG_DIR=${WRKSRC}/cmake/modules

REPLACE_PYTHON+=	scribus/plugins/scriptplugin/samples/*.py
REPLACE_PYTHON+=	scribus/plugins/scriptplugin/scripts/*.py

# Not ported yet?
PYTHON_VERSIONS_ACCEPTED=	27

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../converters/libcdr/buildlink3.mk"
.include "../../converters/libfreehand/buildlink3.mk"
.include "../../converters/libmspub/buildlink3.mk"
.include "../../converters/libpagemaker/buildlink3.mk"
.include "../../converters/libqxp/buildlink3.mk"
.include "../../converters/libvisio/buildlink3.mk"
.include "../../converters/libzmf/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/osg/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../print/cups-base/buildlink3.mk"
.include "../../print/podofo/buildlink3.mk"
.include "../../print/poppler-cpp/buildlink3.mk"
.include "../../print/poppler-includes/buildlink3.mk"
.include "../../textproc/hunspell/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
