# $NetBSD: Makefile,v 1.3 2004/03/17 11:48:56 mpasternak Exp $
#

DISTNAME=		gtk+-2.4.0
CATEGORIES=		wip
MASTER_SITES=		ftp://ftp.gtk.org/pub/gtk/v2.4/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.gtk.org/
COMMENT=		Development version of x11/gtk2

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/contrib/gdk-pixbuf-xlib/gdk-pixbuf-xlib-2.0.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/gdk-2.0.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/gdk-pixbuf-2.0.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/gtk+-2.0.pc.in
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
