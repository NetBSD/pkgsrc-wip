# $NetBSD: Makefile,v 1.6 2015/04/09 20:38:31 krytarowski Exp $

.include "../../wip/mate/Makefile.common"

DISTNAME=	mate-media-${MATE_VERSION}
CATEGORIES=	multimedia

COMMENT=	MATE media tools for MATE Desktop
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.1 AND gnu-lgpl-v2

EXTRACT_USING=	gtar

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples/mate-media

.include "options.mk"

.include "../../devel/glib2/schemas.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../audio/libcanberra/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../wip/libmatemixer/buildlink3.mk"
.include "../../wip/mate-desktop/buildlink3.mk"
.include "../../wip/mate-panel/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-gst-mixer-applet
CONFIGURE_ARGS+=	--enable-gstmix
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
