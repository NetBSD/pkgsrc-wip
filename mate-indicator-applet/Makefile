# $NetBSD: Makefile,v 1.6 2015/04/09 20:38:31 krytarowski Exp $

.include "../../wip/mate/Makefile.common"

DISTNAME=	mate-indicator-applet-${MATE_VERSION}
CATEGORIES=	x11

COMMENT=	MATE indicator applet

.include "../../wip/mate-panel/buildlink3.mk"
.include "../../wip/libindicator/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
