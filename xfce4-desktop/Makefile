# $NetBSD: Makefile,v 1.1.1.1 2003/06/04 07:36:50 marttikuparinen Exp $

.include "../xfce4/Makefile.common"

PKGNAME=	xfce4-desktop-${XFCE4_VERSION}
COMMENT=	XFce4 desktop background manager

WRKSRC=		${WRKDIR}/xfce-devel/xfdesktop

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../wip/xfce4-mcs-plugins/buildlink2.mk"
.include "../../x11/startup-notification/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
