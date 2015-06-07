# $NetBSD: Makefile,v 1.5 2015/06/07 14:24:48 yrmt Exp $

DISTNAME=	libgrss-0.5.0
CATEGORIES=	www
MASTER_SITES=	http://gtk.mplat.es/libgrss/tarballs/

MAINTAINER=	noud4@users.sourceforge.net
HOMEPAGE=	https://wiki.gnome.org/Projects/Libgrss
COMMENT=	Easy management of RSS/Atom/Pie feeds
LICENSE=	gnu-lgpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	libgrss.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
