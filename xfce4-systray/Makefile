# $NetBSD: Makefile,v 1.2 2003/06/09 06:30:50 marttikuparinen Exp $

.include "../xfce4/Makefile.common"

BROKEN=		No distfile available yet

PKGNAME=	xfce4-systray-${XFCE4_VERSION}
COMMENT=	XFce4 systray plugin

WRKSRC=		${WRKDIR}/xfce4-extras/xfce4-systray

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../wip/xfce4-panel/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
