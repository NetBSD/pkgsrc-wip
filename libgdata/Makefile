# $NetBSD: Makefile,v 1.1.1.1 2009/04/08 09:06:49 jihbed Exp $
#

DISTNAME=	libgdata-0.1.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libgdata/0.1/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://live.gnome.org/libgdata
COMMENT=	Google Data API based Glib client library

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool gmake
USE_LANGUAGES+=	c c++

PKGCONFIG_OVERRIDE+=	libgdata.pc.in

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.15.3
BUILDLINK_API_DEPENDS.libsoup24+=	libsoup24>=2.4.0


.include "../../devel/glib2/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
