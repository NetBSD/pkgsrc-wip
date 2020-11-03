# $NetBSD$

DISTNAME=	mutter-3.36.4
PKGREVISION=	1
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/mutter/3.36/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	dan@alt.md
HOMEPAGE=	https://download.gnome.org/sources/mutter
COMMENT=	GNOME Window manager and Wayland compositor
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		pkg-config
USE_PKGLOCALEDIR=	yes

MESON_ARGS+=		-Dudev=false
MESON_ARGS+=		-Dnative_backend=false
MESON_ARGS+=		-Dlibwacom=false
MESON_ARGS+=		-Dremote_desktop=false
MESON_ARGS+=		-Dprofiler=false
MESON_ARGS+=		-Dwayland=false
MESON_ARGS+=		-Dtests=false #tests require Wayland support
MESON_ARGS+=		-Dsm=true

PKGCONFIG_OVERRIDE+=	clutter/clutter/mutter-clutter.pc.in
PKGCONFIG_OVERRIDE+=	cogl/cogl-pango/mutter-cogl-pango.pc.in
PKGCONFIG_OVERRIDE+=	cogl/cogl-path/mutter-cogl-path.pc.in
PKGCONFIG_OVERRIDE+=	cogl/cogl/mutter-cogl.pc.in
PKGCONFIG_OVERRIDE+=	src/libmutter.pc.in

LDFLAGS+=       ${COMPILER_RPATH_FLAG}${PREFIX}/lib/mutter-6

# workaround for enums not being generated
pre-build:
	cd ${WRKSRC} && ninja -C output/ cogl/cogl-path/cogl-path-enum-types.h

.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
#.include "../../wip/libinput/buildlink3.mk"
.include "../../audio/libcanberra/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../wip/gnome-desktop3/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../wip/gnome-settings-daemon/buildlink3.mk"
.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../wip/graphene/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
