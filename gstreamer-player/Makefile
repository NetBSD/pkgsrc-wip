# $NetBSD: Makefile,v 1.6 2004/02/27 03:28:37 minskim Exp $

DISTNAME=		gst-player-0.5.0
PKGNAME=		gstreamer-player-0.5.0
CATEGORIES=		audio graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gstreamer/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		benedikt.meurer@unix-ag.uni-siegen.de
HOMEPAGE=		http://www.gstreamer.net/
COMMENT=		GStreamer Media Player

BUILD_USES_MSGFMT=	YES
DEPENDS=                gnome2-dirs>=1.0:../../misc/gnome2-dirs

USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
USE_X11=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-x

GCONF2_SCHEMAS=         gst-player.schemas

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../multimedia/gst-plugins/buildlink3.mk"
.include "../../multimedia/gstreamer/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
