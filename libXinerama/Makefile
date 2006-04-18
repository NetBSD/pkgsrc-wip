# $NetBSD: Makefile,v 1.9 2006/04/18 18:27:51 jeremy-c-reed Exp $

DISTNAME=	libXinerama-1.0.1
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/lib/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	X PanoramiX extension library

CONFLICTS+=	XFree86-libs-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	xinerama.pc.in

.include "../../wip/libX11/buildlink3.mk"
.include "../../wip/libXext/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../wip/xineramaproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
