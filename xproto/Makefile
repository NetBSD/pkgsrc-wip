# $NetBSD: Makefile,v 1.7 2004/01/25 22:40:25 minskim Exp $
#

DISTNAME=		xproto-6.6.1
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/release/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xlibs.freedesktop.org/
COMMENT=		X protocol and ancillary headers

CONFLICTS+=		XFree86-libs-[0-9]*

USE_BUILDLINK2=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/xproto.pc.in
GNU_CONFIGURE=		yes

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
