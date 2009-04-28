# $NetBSD: Makefile,v 1.2 2009/04/28 00:04:57 jihbed Exp $
#

DISTNAME=	libgdata-0.2.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libgdata/0.2/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://live.gnome.org/libgdata
COMMENT=	Google Data API based Glib client library

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool gmake

PKGCONFIG_OVERRIDE+=	libgdata.pc.in

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.16.0

.include "../../devel/glib2/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
