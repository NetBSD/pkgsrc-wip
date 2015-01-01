# $NetBSD: Makefile,v 1.1 2015/01/01 08:40:44 obache Exp $

DISTNAME=	mate-media-1.8.0
CATEGORIES=	multimedia
MASTER_SITES=	http://pub.mate-desktop.org/releases/1.8/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.mate-desktop.org/
COMMENT=	MATE media tools for MATE Desktop
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.1 AND gnu-lgpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_PKGLOCALEDIR=	yes

EXTRACT_USING=	gtar

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples/mate-media

.include "options.mk"

.include "../../devel/glib2/schemas.mk"

.include "../../audio/libcanberra/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../wip/mate-desktop/buildlink3.mk"
.include "../../wip/mate-panel/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-gst-mixer-applet
CONFIGURE_ARGS+=	--enable-gstmix
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
