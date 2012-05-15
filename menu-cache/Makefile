# $NetBSD: Makefile,v 1.2 2012/05/15 03:18:31 jeremy-c-reed Exp $
#

DISTNAME=	menu-cache-0.3.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lxde/}

MAINTAINER=	INSERT_YOUR_MAIL_ADDRESS_HERE
HOMEPAGE=	http://lxde.sourceforge.net/
COMMENT=	Cache for freedesktop.org menu spec

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libmenu-cache/libmenu-cache.pc.in

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.16.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
