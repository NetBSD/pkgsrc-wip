# $NetBSD: Makefile,v 1.2 2003/04/25 12:08:24 rhx Exp $

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

USE_BUILDLINK2=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
USE_X11=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-x

GCONF2_SCHEMAS=         gst-player.schemas

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../misc/gst-plugins/buildlink2.mk"
.include "../../misc/gstreamer/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
