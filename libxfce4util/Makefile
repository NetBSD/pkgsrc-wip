# $NetBSD: Makefile,v 1.6 2006/07/14 10:52:26 thomasklausner Exp $

.include "../../wip/xfce4/Makefile.common"

DISTNAME=	libxfce4util-${XFCE4_VERSION}
CATEGORIES=	x11
COMMENT=	Xfce basic library

CONFIGURE_ARGS+=	--with-html-dir=${PREFIX:Q}/share/doc/html

PKGCONFIG_OVERRIDE=	libxfce4util/libxfce4util-1.0.pc.in

.include "../../mk/bsd.pkg.mk"
