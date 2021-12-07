# $NetBSD$

DISTNAME=	spice-gtk-0.39
CATEGORIES=	sysutils
MASTER_SITES=	https://www.spice-space.org/download/gtk/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.spice-space.org/spice-gtk.html
COMMENT=	GTK+ widget for SPICE clients
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=		pkg-config
USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE+=	spice-client-glib-2.0.pc.in
PKGCONFIG_OVERRIDE+=	spice-client-gtk-3.0.pc.in

MESON_ARGS+=		-Dintrospection=enabled
MESON_ARGS+=		-Dvapi=enabled

PYTHON_VERSIONED_DEPENDENCIES+=	pyparsing

.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../devel/meson/build.mk"
.include "../../audio/libopus/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/spice-protocol/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
