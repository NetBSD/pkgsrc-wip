# $NetBSD: Makefile,v 1.8 2004/08/17 18:27:09 tvierling Exp $
#

DISTNAME=		gtk+-2.4.0
PKGNAME=		${DISTNAME:S/gtk/gtk2/}
CATEGORIES=		x11
MASTER_SITES=		ftp://ftp.gtk.org/pub/gtk/v2.4/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.gtk.org/
COMMENT=		Development version of x11/gtk2

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_LA_FILES+=	lib/gtk-2.0/2.4.0/immodules/im-am-et.la
LIBTOOL_LA_FILES+=	lib/gtk-2.0/2.4.0/immodules/im-cedilla.la
LIBTOOL_LA_FILES+=	lib/gtk-2.0/2.4.0/immodules/im-cyrillic-translit.la
LIBTOOL_LA_FILES+=	lib/gtk-2.0/2.4.0/immodules/im-inuktitut.la
LIBTOOL_LA_FILES+=	lib/gtk-2.0/2.4.0/immodules/im-ipa.la
LIBTOOL_LA_FILES+=	lib/gtk-2.0/2.4.0/immodules/im-thai-broken.la
LIBTOOL_LA_FILES+=	lib/gtk-2.0/2.4.0/immodules/im-ti-er.la
LIBTOOL_LA_FILES+=	lib/gtk-2.0/2.4.0/immodules/im-ti-et.la
LIBTOOL_LA_FILES+=	lib/gtk-2.0/2.4.0/immodules/im-viqr.la
LIBTOOL_LA_FILES+=	lib/gtk-2.0/2.4.0/immodules/im-xim.la
LIBTOOL_LA_FILES+=	lib/gtk-2.0/2.4.0/loaders/libpixbufloader-ani.la
LIBTOOL_LA_FILES+=	lib/gtk-2.0/2.4.0/loaders/libpixbufloader-bmp.la
LIBTOOL_LA_FILES+=	lib/gtk-2.0/2.4.0/loaders/libpixbufloader-gif.la
LIBTOOL_LA_FILES+=	lib/gtk-2.0/2.4.0/loaders/libpixbufloader-ico.la
LIBTOOL_LA_FILES+=	lib/gtk-2.0/2.4.0/loaders/libpixbufloader-jpeg.la
LIBTOOL_LA_FILES+=	lib/gtk-2.0/2.4.0/loaders/libpixbufloader-pcx.la
LIBTOOL_LA_FILES+=	lib/gtk-2.0/2.4.0/loaders/libpixbufloader-png.la
LIBTOOL_LA_FILES+=	lib/gtk-2.0/2.4.0/loaders/libpixbufloader-pnm.la
LIBTOOL_LA_FILES+=	lib/gtk-2.0/2.4.0/loaders/libpixbufloader-ras.la
LIBTOOL_LA_FILES+=	lib/gtk-2.0/2.4.0/loaders/libpixbufloader-tga.la
LIBTOOL_LA_FILES+=	lib/gtk-2.0/2.4.0/loaders/libpixbufloader-tiff.la
LIBTOOL_LA_FILES+=	lib/gtk-2.0/2.4.0/loaders/libpixbufloader-wbmp.la
LIBTOOL_LA_FILES+=	lib/gtk-2.0/2.4.0/loaders/libpixbufloader-xbm.la
LIBTOOL_LA_FILES+=	lib/gtk-2.0/2.4.0/loaders/libpixbufloader-xpm.la
LIBTOOL_LA_FILES+=	lib/libgdk-x11-2.0.la
LIBTOOL_LA_FILES+=	lib/libgdk_pixbuf-2.0.la
LIBTOOL_LA_FILES+=	lib/libgdk_pixbuf_xlib-2.0.la
LIBTOOL_LA_FILES+=	lib/libgtk-x11-2.0.la
LIBTOOL_OVERRIDE=	${WRKSRC}/ltmain.sh ${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=	contrib/gdk-pixbuf-xlib/gdk-pixbuf-xlib-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gdk-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gdk-pixbuf-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gtk+-2.0.pc.in
GNU_CONFIGURE=		yes

.include "../../wip/pango-devel/buildlink3.mk"
.include "../../wip/atk-devel/buildlink3.mk"
.include "../../wip/glib2-devel/buildlink3.mk"

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
