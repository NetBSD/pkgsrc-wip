# $NetBSD: Makefile,v 1.1 2013/06/18 07:16:46 noud4 Exp $
#

DISTNAME=	libgrss-0.4.0
CATEGORIES=	www
MASTER_SITES=	http://gtk.mplat.es/libgrss/tarballs/

MAINTAINER=	noud4@home.nl
HOMEPAGE=	http://live.gnome.org/Libgrss
COMMENT=	Easy management of RSS/Atom/Pie feeds
LICENSE=	gnu-lgpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	libgrss.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
