# $NetBSD: Makefile,v 1.9 2006/09/07 10:08:42 marttikuparinen Exp $

.include "../../wip/xfce4/Makefile.common"

DISTNAME=		xfce4-panel-${XFCE4_VERSION}
CATEGORIES=		x11
COMMENT=		Xfce panel

PKGCONFIG_OVERRIDE=	panel/xfce4-panel-1.0.pc.in
PTHREAD_AUTO_VARS=	yes

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../wip/xfce4-mcs-plugins/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
