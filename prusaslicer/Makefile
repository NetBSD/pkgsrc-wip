# $NetBSD$

PKGVERSION=	2.9.1
PKGNAME=	prusaslicer-${PKGVERSION}
DISTNAME=	PrusaSlicer-${PKGVERSION:C/(alpha|beta|rc)/-\1/}
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=prusa3d/}
GITHUB_PROJECT=	PrusaSlicer
GITHUB_TAG=	version_${PKGVERSION:C/(alpha|beta|rc)/-\1/}
# Needed, else we strip the 'v' and look for "ersion".
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

MAINTAINER=	stix@stix.id.au
HOMEPAGE=	https://www.prusa3d.com/prusaslicer/
COMMENT=	Converts 3D models into G-code for 3D printing
LICENSE=	gnu-agpl-v3

ONLY_FOR_PLATFORM=	*-*-aarch64 *-*-x86_64 *-*-earmv6 *-*-earmv7 *-*-i386

# Uses std::to_chars_result from <charconv> which is actually gcc8+.
# GCC_REQD+=		10
USE_LANGUAGES=		c c++
USE_CXX_FEATURES=	c++17
USE_TOOLS+=		gmake pkg-config:run
ICON_THEMES=		yes

BUILDLINK_TRANSFORM.NetBSD+=	rm:-ldl
BUILDLINK_TRANSFORM.NetBSD+=	l:libexpat:expat
BUILDLINK_TRANSFORM+=		rm:-lTKXDESTEP
BUILDLINK_TRANSFORM+=		rm:-lTKSTEP
BUILDLINK_TRANSFORM+=		rm:-lTKSTEP209
BUILDLINK_TRANSFORM+=		rm:-lTKSTEPAttr
BUILDLINK_TRANSFORM+=		rm:-lTKSTEPBase

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

CMAKE_CONFIGURE_ARGS+=	-DSLIC3R_FHS:BOOL=TRUE
CMAKE_CONFIGURE_ARGS+=	-DSLIC3R_PCH:BOOL=FALSE

.include "../../archivers/brotli/buildlink3.mk"
.include "../../comms/libhidapi/buildlink3.mk"
.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../devel/asio/buildlink3.mk"
.include "../../devel/at-spi2-core/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/catch2/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/libepoll-shim/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/freeimage/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/graphite2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libjpeg-turbo/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../math/imath/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../math/qhull/buildlink3.mk"
.include "../../math/z3/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../parallel/threadingbuildingblocks/buildlink3.mk"
.include "../../security/heimdal/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/libxml/buildlink3.mk"
.include "../../wip/cereal/buildlink3.mk"
.include "../../wip/cgal/buildlink3.mk"
.include "../../wip/libbgcode/buildlink3.mk"
.include "../../wip/nanosvg/buildlink3.mk"
.include "../../wip/nlopt/buildlink3.mk"
.include "../../cad/occt/buildlink3.mk"
.include "../../wip/openvdb/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../www/webkit-gtk/buildlink3.mk"
BUILDLINK_API_DEPENDS.Xrandr+=  Xrandr>=1.0.2
.include "../../x11/xcursor/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/wxGTK32/buildlink3.mk"
.include "../../x11/xcb-proto/buildlink3.mk"
.include "../../x11/xcursor/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
