# $NetBSD: Makefile,v 1.8 2004/08/17 18:29:32 tvierling Exp $
#

DISTNAME=		libXres-1.0.1
PKGREVISION=		1
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/release/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://xlibs.freedesktop.org/
COMMENT=		X Resource usage library

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
LIBTOOL_LA_FILES+=	lib/libXRes.la
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	xres.pc.in

.include "../../wip/libX11/buildlink3.mk"
.include "../../wip/libXau/buildlink3.mk"
.include "../../wip/libXext/buildlink3.mk"
.include "../../wip/xproto/buildlink3.mk"
.include "../../x11/xextensions/buildlink3.mk"
.include "../../wip/resourceext/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
