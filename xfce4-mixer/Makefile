# $NetBSD: Makefile,v 1.8 2006/07/15 15:23:24 thomasklausner Exp $

.include "../../wip/xfce4/Makefile.common"

DISTNAME=	xfce4-mixer-${XFCE4_VERSION}
CATEGORIES=	audio
COMMENT=	Xfce mixer plugin
USE_TOOLS+=	intltool

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../wip/xfce4-panel/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
