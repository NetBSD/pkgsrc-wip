# $NetBSD: Makefile,v 1.8 2013/04/18 01:25:26 othyro Exp $
#

DISTNAME=	couchdb-glib-0.7.4
CATEGORIES=	databases gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/couchdb-glib/0.7/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	https://launchpad.net/couchdb-glib
COMMENT=	GLib-based api to access couchdb databases
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	couchdb-glib.pc.in
PKGCONFIG_OVERRIDE+=	desktopcouch-glib.pc.in

.include "options.mk"

BUILD_DEPENDS+=	p5-XML-LibXML-[0-9]*:../../textproc/p5-XML-LibXML
.include "../../x11/gtk-sharp/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
BUILDLINK_DEPMETHOD.gnome-keyring=	build
.include "../../security/gnome-keyring/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
