# $NetBSD: Makefile,v 1.1.1.1 2008/10/15 20:30:10 hoka_adam Exp $

.include "../../wip/xfce4/Makefile.common"

DISTNAME=	libxfce4menu-${XFCE4_VERSION}
CATEGORIES=	x11
COMMENT=	Xfce menu library

CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc

PKGCONFIG_OVERRIDE+=	libxfce4menu/libxfce4menu-0.1.p.

.include "../../wip/libxfce4util/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
