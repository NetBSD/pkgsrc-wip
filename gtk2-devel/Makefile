# $NetBSD: Makefile,v 1.6 2004/05/09 02:39:03 minskim Exp $
#

DISTNAME=		gtk+-2.4.0
PKGNAME=		${DISTNAME:S/gtk/gtk2/}
CATEGORIES=		wip
MASTER_SITES=		ftp://ftp.gtk.org/pub/gtk/v2.4/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.gtk.org/
COMMENT=		Development version of x11/gtk2

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
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
