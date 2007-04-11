# $NetBSD: Makefile,v 1.7 2007/04/11 00:42:23 hoka_adam Exp $

.include "../../wip/xfce4/Makefile.common"

DISTNAME=	libxfce4mcs-${XFCE4_VERSION}
CATEGORIES=	x11
COMMENT=	Xfce settings management library

CONFIGURE_ARGS+=	--with-html-dir=${PREFIX:Q}/share/doc/html

PKGCONFIG_OVERRIDE=	libxfce4mcs/libxfce4mcs-client-1.0.pc.in
PKGCONFIG_OVERRIDE+=	libxfce4mcs/libxfce4mcs-manager-1.0.pc.in

.include "../../x11/startup-notification/buildlink3.mk"
.include "../../wip/libxfce4util/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
