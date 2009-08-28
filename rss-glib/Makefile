# $NetBSD: Makefile,v 1.3 2009/08/28 11:48:15 jihbed Exp $
#

DISTNAME=	rss-glib-0.2.2
CATEGORIES=	www
MASTER_SITES=	http://ftp.dronelabs.com/sources/rss-glib/0.2/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://dronelabs.com/
COMMENT=	Rss GLib is a RSS and Atom parser for GObject
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake


PKGCONFIG_OVERRIDE+=	bindings/mono/rss-glib-sharp-1.0.pc.in
PKGCONFIG_OVERRIDE+=	rss-glib.pc.in

PLIST_SRC+=		PLIST

.include "options.mk"

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../wip/libmrss/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
