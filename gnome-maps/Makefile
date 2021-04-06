# $NetBSD$

DISTNAME=	gnome-maps-v40.0
PKGNAME=	${DISTNAME:S,-v,-,}
CATEGORIES=	geography
MASTER_SITES=	https://gitlab.gnome.org/GNOME/gnome-maps/-/archive/v40.0/

MAINTAINER=	cirnatdan@NetBSD.org
HOMEPAGE=	https://gitlab.gnome.org/GNOME/gnome-maps/-/archive/v40.0/
COMMENT=	Maps application for GNOME
LICENSE=	gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config

.include "../../wip/libgfbgraph/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../www/librest07/buildlink3.mk"
.include "../../geography/libchamplain012/buildlink3.mk"
.include "../../geography/geocode-glib/buildlink3.mk"
.include "../../chat/libfolks/buildlink3.mk"
.include "../../devel/libgee/buildlink3.mk"
.include "../../devel/libhandy1/buildlink3.mk"
.include "../../geography/geoclue/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../lang/gjs/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
