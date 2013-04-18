# $NetBSD: Makefile,v 1.5 2013/04/18 02:19:33 othyro Exp $

DISTNAME=	libepc-0.4.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libepc/0.4/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://live.gnome.org/libepc/
COMMENT=	Easy Publish and Consume Library
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake intltool msgfmt msgmerge perl pkg-config xgettext

PKGCONFIG_OVERRIDE=	libepc-1.0.pc.in libepc-ui-1.0.pc.in

CONFIGURE_ARGS+=	--enable-gtk-doc=no --enable-gtk-doc-html=no --enable-gtk-doc-pdf=no

.include "../../devel/at-spi2-core/buildlink3.mk"
.include "../../devel/atk/buildlink3.mk"
.include "../../devel/at-spi2-atk/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/cairo-gobject/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libXdmcp/buildlink3.mk"
.include "../../x11/libXau/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
BUILDLINK_DEPMETHOD.gtk3=	build
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
#.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../security/nettle/buildlink3.mk"
.include "../../security/libtasn1/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../net/avahi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
