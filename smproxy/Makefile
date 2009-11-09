# $NetBSD: Makefile,v 1.3 2009/11/09 19:24:39 tnn2 Exp $
#

DISTNAME=	smproxy-1.0.3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	metaridley@mchsi.com
HOMEPAGE=	http://xorg.freedesktop.org/releases/individual/app/
COMMENT=	Proxy to allow non-XSMP apps to be managed by xsm

GNU_CONFIGURE=	yes
USE_TOOLS+= pkg-config

.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
