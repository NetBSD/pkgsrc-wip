# $NetBSD: Makefile,v 1.12 2012/10/03 09:10:41 asau Exp $

.include "../../wip/xfce48/Makefile.common"

DISTNAME=	libxfce4util-${XFCE4_VERSION}
XFCE4_VERSION=	4.8.2
CATEGORIES=	x11
COMMENT=	Xfce basic library

XFCE4_PROJECT=  libxfce4util
XFCE4_BRANCH=   4.8

PKGCONFIG_OVERRIDE=	libxfce4util/libxfce4util-1.0.pc.in

MAKE_DIRS+=	${PREFIX}/include/xfce4

.include "../../mk/bsd.pkg.mk"
