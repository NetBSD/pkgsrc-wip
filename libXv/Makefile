# $NetBSD: Makefile,v 1.4 2004/02/01 22:22:18 minskim Exp $
#

DISTNAME=		libXv-2.2.1
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/release/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xlibs.freedesktop.org/
COMMENT=		Xv Extension library

USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=	${WRKSRC}/xv.pc.in
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make

.include "../../wip/libX11/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
