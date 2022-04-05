# $NetBSD: Makefile.common,v 1.24 2022/03/12 07:19:24 nia Exp $

DISTNAME=		evince-42.1
CATEGORIES=		print gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/evince/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://wiki.gnome.org/Apps/Evince
COMMENT=		Document viewer
LICENSE=		gnu-gpl-v2

USE_TOOLS+=		intltool msgfmt pkg-config itstool
USE_TOOLS+=		gdbus-codegen gsed
USE_LANGUAGES=		c c++

MESON_ARGS+=		-Dgtk_doc=false
MESON_ARGS+=		-Dnautilus=false

.include "options.mk"

BUILDLINK_API_DEPENDS.libarchive+=	libarchive>=3.2.0
.include "../../archivers/libarchive/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.36.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/adwaita-icon-theme/buildlink3.mk"
BUILDLINK_API_DEPENDS.gdk-pixbuf2+=	gdk-pixbuf2>=2.36.5
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../print/libspectre/buildlink3.mk"
BUILDLINK_API_DEPENDS.poppler-glib+=	poppler-glib>=0.33.0
.include "../../print/poppler-glib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libxml2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk3+=	gtk3+>=3.15.3
.include "../../x11/gtk3/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
BUILDLINK_API_DEPENDS.libhandy1+=	libhandy1>=1.5.0
.include "../../wip/libhandy1/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/libsecret/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../mk/bsd.pkg.mk"
