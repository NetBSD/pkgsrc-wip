# $NetBSD: Makefile,v 1.1.1.1 2003/11/27 04:16:03 xtraeme Exp $
#

DISTNAME=		libXres-1.0.1
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/dist/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://freedesktop.org/
COMMENT=		Xresources extension (Library)

USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=    ${WRKSRC}/xres.pc.in

.include "../../wip/libX11/buildlink2.mk"
.include "../../wip/libXau/buildlink2.mk"
.include "../../wip/xproto/buildlink2.mk"
.include "../../wip/xextensions/buildlink2.mk"
.include "../../wip/resourceext/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
