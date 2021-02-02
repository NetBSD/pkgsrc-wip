# $NetBSD$

PKGNAME=	${DISTNAME:tl}
DISTNAME=	PrusaSlicer-2.3.0
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=prusa3d/}
GITHUB_PROJECT=	PrusaSlicer
GITHUB_TAG=	version_${PKGVERSION_NOREV}
# Needed, else we strip the 'v' and look for "ersion".
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

MAINTAINER=	stix@stix.id.au
HOMEPAGE=	https://www.prusa3d.com/prusaslicer/
COMMENT=	Converts STL models into gcode for 3d printing
LICENSE=	gnu-agpl-v3

ONLY_FOR_PLATFORM=	*-*-aarch64 *-*-x86_64 *-*-earmv6 *-*-earmv7 *-*-i386

USE_LANGUAGES=	c c++
USE_TOOLS+=	cmake gmake
USE_CMAKE=	yes

.include "../../mk/bsd.prefs.mk"

CMAKE_ARGS+=	-DSLIC3R_WX_STABLE=1

.include "../../comms/libhidapi/buildlink3.mk"
.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../devel/atk/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/graphite2/buildlink3.mk"
.include "../../graphics/ilmbase/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../math/cgal/buildlink3.mk"
.include "../../math/eigen3/buildlink3.mk"
.include "../../parallel/threadingbuildingblocks/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../wip/cereal/buildlink3.mk"
.include "../../wip/nlopt/buildlink3.mk"
.include "../../wip/openvdb/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../x11/xcb-proto/buildlink3.mk"
.include "../../x11/xcursor/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
