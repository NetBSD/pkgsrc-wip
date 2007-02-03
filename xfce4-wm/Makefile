# $NetBSD: Makefile,v 1.7 2007/02/03 09:24:11 thomasklausner Exp $

.include "../../wip/xfce4/Makefile.common"

DISTNAME=	xfwm4-${XFCE4_VERSION}
PKGNAME=	xfce4-wm-${XFCE4_VERSION}
CATEGORIES=	wm
COMMENT=	Xfce window manager

USE_DIRS+=	xdg-1.4

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../wip/xfce4-mcs-plugins/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
