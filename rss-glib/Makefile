# $NetBSD: Makefile,v 1.8 2013/06/17 12:45:12 thomasklausner Exp $
#

DISTNAME=	rss-glib-0.2.2
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://ftp.dronelabs.com/sources/rss-glib/0.2/

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	http://dronelabs.com/
COMMENT=	Rss GLib is a RSS and Atom parser for GObject
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake


PKGCONFIG_OVERRIDE+=	bindings/mono/rss-glib-sharp-1.0.pc.in
PKGCONFIG_OVERRIDE+=	rss-glib.pc.in

PLIST_SRC+=		PLIST

.include "options.mk"

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../www/libmrss/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
