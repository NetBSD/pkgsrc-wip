# $NetBSD: Makefile,v 1.5 2012/09/29 00:50:40 asau Exp $
#

PKGNAME=	gst-plugins0.10-farsight-0.12.11
DISTNAME=	gst-plugins-farsight-0.12.11
PKGREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	http://farsight.freedesktop.org/releases/gst-plugins-farsight/

MAINTAINER=	yacht@users.sourceforge.net
#HOMEPAGE=	http://farsight.freedesktop.org/wiki/
COMMENT=	GStreamer farsight2 plugin
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake intltool pkg-config
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--with-libj2k

.include "../../audio/gsm/buildlink3.mk"
.include "../../wip/libjingle/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../graphics/jasper/buildlink3.mk"
.include "../../multimedia/farsight2/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
