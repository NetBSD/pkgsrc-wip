# $NetBSD: Makefile,v 1.46 2021/04/13 17:35:45 cirnatdan Exp $
SUPERSEDES=	gnome-desktop3-[0-9]*
DISTNAME=	gnome-desktop-44.1
PKGNAME=	${DISTNAME:S/desktop/desktop4/}
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-desktop/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	cirnatdan@NetBSD.org
HOMEPAGE=	https://www.gnome.org/
COMMENT=	GNOME3 desktop-wide documents and libgnome-desktop library
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2 AND gnu-fdl-v1.1

USE_TOOLS+=		pkg-config xgettext gdbus-codegen
PKGCONFIG_OVERRIDE+=	libgnome-desktop/gnome-desktop-3.0.pc.in

MESON_ARGS+=		-Dsystemd=disabled
MESON_ARGS+=		-Dudev=disabled
MESON_ARGS+=		-Ddesktop_docs=false
MESON_ARGS+=		-Dgtk_doc=false
MESON_ARGS+=		-Ddebug_tools=false

PYTHON_FOR_BUILD_ONLY=	tool

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Linux"
.include "../../wip/mk/libseccomp.buildlink3.mk"
.endif

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.44.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
BUILDLINK_API_DEPENDS.gdk-pixbuf2+=	gdk-pixbuf2>=2.36.5
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gsettings-desktop-schemas+=	gsettings-desktop-schemas>=3.27.0
.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/gtk4/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../x11/xkeyboard-config/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
