# $NetBSD: Makefile,v 1.3 2004/01/25 02:23:36 grantbeattie Exp $
#

DISTNAME=		libXv-2.2.1
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/dist/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.freedesktop.org/Software/xlibs
COMMENT=		Xv Extension library

USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=	${WRKSRC}/xv.pc.in
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make

.include "../../wip/libXau/buildlink2.mk"
.include "../../wip/libX11/buildlink2.mk"
.include "../../wip/xextensions/buildlink2.mk"
.include "../../wip/xproto/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
