# $NetBSD: Makefile,v 1.1 2013/05/19 02:31:14 othyro Exp $
#

DISTNAME=	xf86dga-1.0.3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Simple test client for the XFree86-DGA extension
#LICENSE=	# TODO: (see mk/license.mk)

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

BUILDLINK_API_DEPENDS.libXxf86dga+=	libXxf86dga>=1.1
.include "../../x11/libXxf86dga/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
