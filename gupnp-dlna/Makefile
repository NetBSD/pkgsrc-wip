# $NetBSD: Makefile,v 1.2 2012/09/29 00:50:41 asau Exp $
#

DISTNAME=	gupnp-dlna-0.4.0
CATEGORIES=	net
MASTER_SITES=	http://www.gupnp.org/sites/all/files/sources/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gupnp.org/
COMMENT=	GUPnP DLNA is a small DLNA-related utility library
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	gupnp-dlna-1.0.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../net/gupnp/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gstreamer0.10+=	gstreamer0.10>=0.10.29.2
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
