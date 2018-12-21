# $NetBSD$

DISTNAME=	libdazzle-3.30.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libdazzle/3.30/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.gnome.org/GNOME/libdazzle/
COMMENT=	Companion library to GObject and Gtk+
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config

MESON_ARGS+=	-D enable_tests=false
# XXX: Build fails with that, please see TODO
MESON_ARGS+=	-D with_introspection=false

.include "../../devel/glib2/buildlink3.mk"
#.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/py-meson/build.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
