# $NetBSD: Makefile,v 1.1.1.1 2003/06/04 07:39:20 marttikuparinen Exp $

.include "../xfce4/Makefile.common"

PKGNAME=	xfce4-mcs-manager-${XFCE4_VERSION}
COMMENT=	XFce4 settings manager

WRKSRC=		${WRKDIR}/xfce-devel/xfce-mcs-manager

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../wip/libxfce4gui/buildlink2.mk"
.include "../../wip/libxfce4mcs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
