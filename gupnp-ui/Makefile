# $NetBSD: Makefile,v 1.1.1.1 2009/12/07 14:53:35 jihbed Exp $
#

DISTNAME=	gupnp-ui-0.1.1
CATEGORIES=	net
MASTER_SITES=	http://www.gupnp.org/sources/gupnp-ui/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://www.gupnp.org/
COMMENT=	GTK+ widgets for use with GUPnP
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool msgfmt
USE_LANGUAGES= c c++

PKGCONFIG_OVERRIDE+=	gupnp-ui-1.0.pc.in

.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gupnp+=	gupnp>=0.12.6
.include "../../net/gupnp/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
