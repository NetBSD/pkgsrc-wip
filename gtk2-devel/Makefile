# $NetBSD: Makefile,v 1.2 2004/02/17 02:55:38 blef Exp $
#

DISTNAME=		gtk+-2.3.1
PKGNAME=		gtk2-devel-2.3.1
CATEGORIES=		wip
MASTER_SITES=		ftp://ftp.gtk.org/pub/gtk/v2.3/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.gtk.org/
COMMENT=		Development version of x11/gtk2

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/contrib/gdk-pixbuf-xlib/gdk-pixbuf-xlib-2.0.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/gdk-2.0.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/gdk-pixbuf-2.0.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/gtk+-2.0.pc.in
GNU_CONFIGURE=		yes

CONFLICTS=		gtk2+-*

.include "../../wip/pango-devel/buildlink2.mk"
.include "../../wip/atk-devel/buildlink2.mk"
.include "../../wip/glib2-devel/buildlink2.mk"

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../fonts/Xft2/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
