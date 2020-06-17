# $NetBSD$

DISTNAME=	gnome-autoar-0.2.4
CATEGORIES=	archivers gnome
MASTER_SITES=	http://ftp.gnome.org/pub/gnome/sources/gnome-autoar/0.2/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	dan@alt.md
HOMEPAGE=	http://ftp.gnome.org/pub/gnome/sources/gnome-autoar/0.2/
COMMENT=	GLib wrapper around libarchive
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	autoconf autoreconf pkg-config gmake
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--disable-schemas-compile
CONFIGURE_ARGS+=	--enable-introspection

.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../archivers/libarchive/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
