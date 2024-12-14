# $NetBSD: Makefile,v 1.46 2024/11/17 07:16:53 wiz Exp $

DISTNAME=	gnome-shell-44.0
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/${PKGBASE}/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	cirnatdan@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/GnomeShell
COMMENT=	Next generation GNOME shell
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config perl msgfmt xgettext gdbus-codegen

MESON_ARGS+=	-Dnetworkmanager=false
MESON_ARGS+=	-Dsystemd=false
MESON_ARGS+=	-Dextensions_app=false
MESON_ARGS+=	-Dextensions_tool=false
MESON_ARGS+=	-Dman=true
MESON_ARGS+=	-Dtests=false

TOOL_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc

DEPENDS+=	libgdm>=40.0:../../x11/libgdm

MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/subprojects/gvc

LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/gnome-shell

PYTHON_FOR_BUILD_ONLY=	tool

post-extract:
	cp ${FILESDIR}/*.xml ${WRKSRC}/data/dbus-interfaces/

.include "../../devel/meson/build.mk"
BUILDLINK_API_DEPENDS.libgweather+=	libgweather>=40.0
.include "../../devel/libgweather/buildlink3.mk"
.include "../../x11/gtk4/buildlink3.mk"
.include "../../archivers/gnome-autoar/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../devel/at-spi2-core/buildlink3.mk"
.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../graphics/adwaita-icon-theme/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../wip/gjs/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../wip/evolution-data-server/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../security/gcr/buildlink3.mk"
.include "../../security/libsecret/buildlink3.mk"
.include "../../security/polkit/buildlink3.mk"
.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"
.include "../../wip/gcr4/buildlink3.mk"
.include "../../wip/mutter/buildlink3.mk"
.include "../../wip/gnome-desktop4/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
