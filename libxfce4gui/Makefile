# $NetBSD: Makefile,v 1.1.1.1 2003/06/04 07:34:29 marttikuparinen Exp $

.include "../xfce4/Makefile.common"

PKGNAME=	libxfce4gui-${XFCE4_VERSION}
COMMENT=	XFce4 widget library

WRKSRC=		${WRKDIR}/xfce-devel/libxfcegui4

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../wip/libxfce4util/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
