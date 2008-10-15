# $NetBSD: Makefile,v 1.8 2008/10/15 20:28:10 hoka_adam Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../wip/xfce4/Makefile.common"

DISTNAME=	libxfce4util-${XFCE4_VERSION}
CATEGORIES=	x11
COMMENT=	Xfce basic library

CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc

PKGCONFIG_OVERRIDE=	libxfce4util/libxfce4util-1.0.pc.in

.include "../../mk/bsd.pkg.mk"
