# $NetBSD: Makefile,v 1.12 2005/11/11 22:53:35 jeremy-c-reed Exp $
#

DISTNAME=		libXrender-0.9.0
CATEGORIES=		x11 devel
MASTER_SITES=		http://xorg.freedesktop.org/releases/X11R7.0-RC2/lib/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		X Render Library

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=	xrender.pc.in

.include "../../wip/libX11/buildlink3.mk"
.include "../../wip/renderproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
