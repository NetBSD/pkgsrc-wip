# $NetBSD: Makefile,v 1.1.1.1 2009/03/28 23:10:54 jihbed Exp $
#

DISTNAME=	xesam-glib-0.5.0
CATEGORIES=	sysutils
MASTER_SITES=	http://xesam.org/people/kamstrup/xesam-glib/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://xesam.org/main/XesamGLib
COMMENT=	Xesam GLib is a client library for the XESAM specification

PKG_DESTDIR_SUPPORT= 	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config perl intltool
USE_LANGUAGES+=	c c++

PKGCONFIG_OVERRIDE+=	xesam-glib.pc.in

BUILDLINK_API_DEPENDS.glib2+=           glib2>=2.10.0


.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
