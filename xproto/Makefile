# $NetBSD: Makefile,v 1.6 2003/11/26 23:58:59 jeremy-c-reed Exp $
#

DISTNAME=		xproto-6.6
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/dist/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.freedesktop.org/Software/xlibs
COMMENT=		X protocol and ancilary headers

CONFLICTS+=		XFree86-libs-[0-9]*

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/xproto.pc.in
GNU_CONFIGURE=		yes

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
