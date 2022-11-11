# $NetBSD$

PKGVERSION=	2.5.0
PKGNAME=	prusaslicer-${PKGVERSION}
DISTNAME=	PrusaSlicer-${PKGVERSION:S/rc/-rc/}
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=prusa3d/}
GITHUB_PROJECT=	PrusaSlicer
GITHUB_TAG=	version_${PKGVERSION:S/rc/-rc/}
# Needed, else we strip the 'v' and look for "ersion".
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

MAINTAINER=	stix@stix.id.au
HOMEPAGE=	https://www.prusa3d.com/prusaslicer/
COMMENT=	Converts STL models into gcode for 3d printing
LICENSE=	gnu-agpl-v3

ONLY_FOR_PLATFORM=	*-*-aarch64 *-*-x86_64 *-*-earmv6 *-*-earmv7 *-*-i386

# Uses std::to_chars_result from <charconv> which is actually gcc8+.
GCC_REQD+=	10
USE_LANGUAGES=	c c++17
USE_TOOLS+=	cmake gmake pkg-config:run
USE_CMAKE=	yes
ICON_THEMES=	yes

BUILDLINK_TRANSFORM.NetBSD+=	rm:-ldl
BUILDLINK_TRANSFORM.NetBSD+=	l:libexpat:expat

.include "../../mk/bsd.prefs.mk"

CMAKE_ARGS+=	-DSLIC3R_WX_STABLE:BOOL=TRUE
CMAKE_ARGS+=	-DSLIC3R_FHS:BOOL=TRUE
#CMAKE_ARGS+=	-DCMAKE_CXX_FLAGS:STRING=-g

.include "../../comms/libhidapi/buildlink3.mk"
.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../devel/at-spi2-atk/buildlink3.mk"
.include "../../devel/atk/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/graphite2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libjpeg-turbo/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../math/cgal/buildlink3.mk"
.include "../../math/eigen3/buildlink3.mk"
.include "../../math/imath/buildlink3.mk"
.include "../../math/qhull/buildlink3.mk"
.include "../../parallel/threadingbuildingblocks/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../wip/cereal/buildlink3.mk"
.include "../../wip/nlopt/buildlink3.mk"
.include "../../wip/opencascade-git/buildlink3.mk"
.include "../../wip/openvdb/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/xcursor/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../x11/xcb-proto/buildlink3.mk"
.include "../../x11/xcursor/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
