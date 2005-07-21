# $NetBSD: Makefile,v 1.5 2005/07/21 16:34:04 thomasklausner Exp $

DISTNAME=	libXinerama-1.0.2
CATEGORIES=	x11
MASTER_SITES=	http://freedesktop.org/~xlibs/release/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://xlibs.freedesktop.org/
COMMENT=	X PanoramiX extension library

CONFLICTS+=	XFree86-libs-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

PKGCONFIG_OVERRIDE+=	xinerama.pc.in

.include "../../devel/pkg-config/buildlink3.mk"
.include "../../wip/libX11/buildlink3.mk"
.include "../../wip/libXext/buildlink3.mk"
.include "../../wip/panoramixext/buildlink3.mk"
.include "../../wip/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
