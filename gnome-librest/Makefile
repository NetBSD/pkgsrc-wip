# $NetBSD: Makefile,v 1.2 2012/09/29 00:50:36 asau Exp $
#

DISTNAME=	rest-0.7.10
PKGNAME=	gnome-lib${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	http://ftp.acc.umu.se/pub/GNOME/sources/rest/0.7/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	http://www.gnome.org/
COMMENT=	GNOME Rest library
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	rest-extras.pc.in
PKGCONFIG_OVERRIDE+=	rest.pc.in

.include "../../devel/gobject-introspection/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.18.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
