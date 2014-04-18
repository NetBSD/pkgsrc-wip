# $NetBSD: Makefile,v 1.1 2014/04/18 21:35:51 thomasklausner Exp $

DISTNAME=	farstream-0.2.3
CATEGORIES=	chat multimedia
MASTER_SITES=	http://freedesktop.org/software/farstream/releases/farstream/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.freedesktop.org/wiki/Software/Farstream/
COMMENT=	Audio/video communications framework
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	farstream.pc.in

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.16.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../net/gupnp-igd/buildlink3.mk"
BUILDLINK_API_DEPENDS.libnice+=	libnice>=0.1.0
.include "../../net/libnice/buildlink3.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
