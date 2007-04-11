# $NetBSD: Makefile,v 1.7 2007/04/11 14:12:57 marttikuparinen Exp $

.include "../../wip/xfce4/Makefile.common"

DISTNAME=	libxfce4util-${XFCE4_VERSION}
CATEGORIES=	x11
COMMENT=	Xfce basic library

CONFIGURE_ARGS+=	--with-html-dir=${PREFIX:Q}/share/doc

PKGCONFIG_OVERRIDE=	libxfce4util/libxfce4util-1.0.pc.in

.include "../../mk/bsd.pkg.mk"
