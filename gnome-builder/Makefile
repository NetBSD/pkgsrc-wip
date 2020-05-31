# $NetBSD$

DISTNAME=	gnome-builder-3.36.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-builder/3.36/}
EXTRACT_SUFX=	.tar.xz
PKGREVISION=	1

MAINTAINER=	dan@alt.md
HOMEPAGE=	https://wiki.gnome.org/Apps/Builder
COMMENT=	IDE/toolsmith for GNOME-based applications
LICENSE=	gnu-gpl-v3

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config

MESON_ARGS+=		-Dfusermount_wrapper=false
MESON_ARGS+=		-Dplugin_flatpak=false
MESON_ARGS+=		-Dplugin_git=false
MESON_ARGS+=		-Dplugin_sysprof=false
MESON_ARGS+=		-Dplugin_update_manager=false

CFLAGS+=		-Wno-error=shadow

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../lang/clang/buildlink3.mk"
.include "../../textproc/gspell/buildlink3.mk"
.include "../../devel/glade/buildlink3.mk"
.include "../../devel/devhelp/buildlink3.mk"
.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../x11/vte3/buildlink3.mk"
.include "../../wip/template-glib/buildlink3.mk"
.include "../../devel/libpeas/buildlink3.mk"
.include "../../wip/jsonrpc-glib/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../x11/gtksourceview4/buildlink3.mk"
.include "../../devel/libdazzle/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
