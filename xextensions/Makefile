# $NetBSD: Makefile,v 1.4 2004/01/31 18:00:52 minskim Exp $
#

DISTNAME=		xextensions-1.0.1
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/release/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xlibs.freedesktop.org/
COMMENT=		Various extension headers for xlibs from freedesktop.org

CONFLICTS+=		XFree86-libs-[0-9]*

USE_BUILDLINK2=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/xextensions.pc.in
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
