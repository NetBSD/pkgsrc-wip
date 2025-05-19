# $NetBSD: Makefile,v 1.6 2015/04/17 06:56:55 thomasklausner Exp $

DISTNAME=	smproxy-1.0.8
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	metaridley@mchsi.com
HOMEPAGE=	https://xorg.freedesktop.org/releases/individual/app/
COMMENT=	Proxy to allow non-XSMP apps to be managed by xsm

USE_TOOLS+=	pkg-config

.include "../../devel/meson/build.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
