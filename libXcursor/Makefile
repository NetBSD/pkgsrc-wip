# $NetBSD: Makefile,v 1.1.1.1 2003/11/27 03:07:10 xtraeme Exp $
#

DISTNAME=		libXcursor-1.1.1
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/dist/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://freedesktop.org/
COMMENT=		Xcursor extension

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=    ${WRKSRC}/xcursor.pc.in

.include "../../wip/xproto/buildlink2.mk"
.include "../../wip/libX11/buildlink2.mk"
.include "../../wip/libXrender/buildlink2.mk"
.include "../../wip/libXfixes/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
