# $NetBSD: Makefile,v 1.12 2011/07/10 16:23:31 reinoudz70 Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/xfce4/Makefile.common"

MIXER_VERSION=	4.8.0

DISTNAME=	xfce4-mixer-${MIXER_VERSION}
#PKGREVISION=	1
CATEGORIES=	audio
COMMENT=	Xfce mixer plugin

MASTER_SITES=	http://archive.xfce.org/src/apps/xfce4-mixer/4.8/

MAKE_DIRS+=	${PREFIX}/libexec/xfce4 ${PREFIX}/libexec/xfce4/panel-plugins
MAKE_DIRS+=	${PREFIX}/share/xfce4 ${PREFIX}/share/xfce4/panel-plugins

BUILDLINK_API_DEPENDS.gst-plugins0.10-base+=	gst-plugins0.10-base>=0.10.14

.include "../../wip/xfconf/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../wip/libxfce4ui/buildlink3.mk"
.include "../../wip/libxfce4util/buildlink3.mk"
.include "../../wip/xfce4-panel/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
