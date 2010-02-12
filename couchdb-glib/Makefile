# $NetBSD: Makefile,v 1.2 2010/02/12 00:51:08 jihbed Exp $
#

DISTNAME=	couchdb-glib-0.5.99
CATEGORIES=	databases gnome
MASTER_SITES=	ftp://ftp.gnome.org/pub/gnome/sources/couchdb-glib/0.5/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://launchpad.net/couchdb-glib
COMMENT=	GLib-based api to access couchdb databases
LICENSE=	gnu-gpl-v2

DEPENDS+=	gobject-introspection>=0.6.7:../../wip/gobject-introspection

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake

PKGCONFIG_OVERRIDE+=	couchdb-glib.pc.in
PKGCONFIG_OVERRIDE+=	desktopcouch-glib.pc.in


.include "../../devel/glib2/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
.include "../../security/gnome-keyring/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../wip/libuuid/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
