# $NetBSD: Makefile,v 1.14 2006/04/12 23:17:18 jeremy-c-reed Exp $
#

DISTNAME=		libXres-1.0.0
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/lib/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		X Resource Information Extension Library

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=	xres.pc.in

.include "../../wip/libX11/buildlink3.mk"
.include "../../wip/libXext/buildlink3.mk"
.include "../../wip/resourceproto/buildlink3.mk"
.include "../../wip/xextproto/buildlink3.mk"
.include "../../wip/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
