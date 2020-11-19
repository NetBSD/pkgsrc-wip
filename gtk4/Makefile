# $NetBSD: Makefile,v 1.156 2020/10/01 11:54:11 prlw1 Exp $

DISTNAME=	gtk-3.99.4
PKGNAME=	${DISTNAME:S/gtk/gtk4/}
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtk/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gtk.org/
COMMENT=	Multi-platform toolkit for creating graphical user interfaces
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		c c++
USE_TOOLS+=		ggrep pkg-config bash xgettext msgmerge
PTHREAD_AUTO_VARS=	yes
TOOL_DEPENDS+=		gdbus-codegen-[0-9]*:../../devel/gdbus-codegen
TOOL_DEPENDS+=		gettext-tools>=0.19.4nb1:../../devel/gettext-tools
TOOL_DEPENDS+=		sassc-[0-9]*:../../www/sassc
#TOOL_DEPENDS+=		pandoc-[0-9]*:../../converters/pandoc

CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/libdata
MESON_ARGS+=		-Dgtk_doc=false #meson bug with macOS frameworks
MESON_ARGS+=		-Ddemos=false
MESON_ARGS+=		-Dbuild-examples=false
MESON_ARGS+=		-Dbuild-tests=false
MESON_ARGS+=		--wrap-mode=nodownload
TEST_TARGET=		check

PKGCONFIG_OVERRIDE+=	gdk-4.0.pc.in
PKGCONFIG_OVERRIDE+=	gtk+-4.0.pc.in
PKGCONFIG_OVERRIDE+=	gtk+-unix-print-4.0.pc.in
PKGCONFIG_OVERRIDE+=	gail-4.0.pc.in

INSTALLATION_DIRS+=	lib/gtk-4.0/immodules
INSTALLATION_DIRS+=	lib/gtk-4.0/modules
INSTALLATION_DIRS+=	lib/gtk-4.0/4.0.0/filesystems

#BUILD_DIRS=		. demos/gtk-demo

.include "../../mk/bsd.prefs.mk"

CFLAGS.SunOS+=		-std=gnu99

CPPFLAGS+=		-DPREFIX="\"${PREFIX}\""

# We remove the module databases during post-install since we create them
# anew in the +INSTALL script as part of the POST-INSTALL action.
#
post-install:
	${RM} -f ${DESTDIR}${GTK3_IMMODULES_DB}

FILES_SUBST+=		GTK_UPDATE_ICON_CACHE="${PREFIX}/bin/gtk4-update-icon-cache"
FILES_SUBST+=		ICON_THEME_DIR="${PREFIX}/share/icons"
INSTALL_TEMPLATES+=	../../x11/gtk2/files/icon-cache.tmpl

_BUILDING_GTK3=	yes
.include "modules.mk"

.include "../../converters/fribidi/buildlink3.mk"
.include "../../databases/shared-mime-info/buildlink3.mk"
BUILDLINK_API_DEPENDS.atk+=	atk>=2.15.1
.include "../../devel/atk/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.57.2
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gdk-pixbuf2+=	gdk-pixbuf2>=2.30.0
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
BUILDLINK_DEPMETHOD.gobject-introspection:=	build
BUILDLINK_API_DEPENDS.gobject-introspection+=	gobject-introspection>=1.39.0
.include "../../devel/gobject-introspection/buildlink3.mk"

.include "options.mk"

.include "../../devel/glib2/schemas.mk"

BUILDLINK_API_DEPENDS.gtk-doc+=	gtk-doc>=1.33
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../graphics/graphene/buildlink3.mk"
BUILDLINK_API_DEPENDS.pango+=	pango>=1.47
.include "../../wip/pango/buildlink3.mk"
BUILDLINK_API_DEPENDS.fontconfig+=	fontconfig>=2.11.91
.include "../../fonts/fontconfig/buildlink3.mk"
BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.14.0
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/cairo-gobject/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
BUILDLINK_API_DEPENDS.libepoxy+=	libepoxy>=1.4
.include "../../graphics/libepoxy/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
