# $NetBSD: Makefile,v 1.4 2003/09/25 18:56:11 marc Exp $

.include "../xfce4/Makefile.common"

DISTNAME=	libxfce4mcs-${XFCE4_VERSION}
CATEGORIES=	x11
COMMENT=	XFce4 settings management library

PKGCONFIG_OVERRIDE=	libxfce4mcs/libxfce4mcs-client-1.0.pc.in
PKGCONFIG_OVERRIDE+=	libxfce4mcs/libxfce4mcs-manager-1.0.pc.in

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../wip/libxfce4util/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
