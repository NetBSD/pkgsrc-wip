# $NetBSD: Makefile,v 1.2 2010/01/18 09:38:23 thomasklausner Exp $
#

PKGNAME=	gst-plugins0.10-farsight-0.12.11
DISTNAME=	gst-plugins-farsight-0.12.11
PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://farsight.freedesktop.org/releases/gst-plugins-farsight/

MAINTAINER=	yacht@users.sourceforge.net
HOMEPAGE=	http://farsight.freedesktop.org/wiki/
COMMENT=	GStreamer farsight2 plugin
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

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
