# $NetBSD: Makefile,v 1.1.1.1 2003/11/26 23:13:32 jeremy-c-reed Exp $
#

DISTNAME=		xextensions-1.0
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/dist/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.freedesktop.org/Software/xlibs
COMMENT=		Various extension headers for xlibs from freedesktop.org

CONFLICTS+=		XFree86-libs-[0-9]*

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/xextensions.pc.in
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
