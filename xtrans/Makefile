# $NetBSD: Makefile,v 1.4 2004/01/29 03:17:17 minskim Exp $
#

DISTNAME=		libXtrans-0.1
PKGNAME=		xtrans-0.1
CATEGORIES=		x11 net
MASTER_SITES=		http://freedesktop.org/~xlibs/release/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xlibs.freedesktop.org/
COMMENT=		Network API translation layer to insulate X

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=    ${WRKSRC}/xtrans.pc.in

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
