# $NetBSD: Makefile,v 1.4 2003/09/25 18:56:11 marc Exp $

.include "../xfce4/Makefile.common"

PKGNAME=	xfce4-mcs-manager-${XFCE4_VERSION}
DISTNAME=	xfce-mcs-manager-${XFCE4_VERSION}
CATEGORIES=	x11
COMMENT=	XFce4 settings manager

PKGCONFIG_OVERRIDE=	xfce-mcs-manager/xfce-mcs-manager.pc.in

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../wip/libxfce4gui/buildlink2.mk"
.include "../../wip/libxfce4mcs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
