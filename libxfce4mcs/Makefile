# $NetBSD: Makefile,v 1.6 2006/07/14 10:52:25 thomasklausner Exp $

.include "../../wip/xfce4/Makefile.common"

DISTNAME=	libxfce4mcs-${XFCE4_VERSION}
CATEGORIES=	x11
COMMENT=	Xfce settings management library

CONFIGURE_ARGS+=	--with-html-dir=${PREFIX:Q}/share/doc/html

PKGCONFIG_OVERRIDE=	libxfce4mcs/libxfce4mcs-client-1.0.pc.in
PKGCONFIG_OVERRIDE+=	libxfce4mcs/libxfce4mcs-manager-1.0.pc.in

.include "../../wip/libxfce4util/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
