# $NetBSD: Makefile,v 1.3 2003/11/27 00:00:20 xtraeme Exp $
#

DISTNAME=		libXau-0.1
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/dist/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.freedesktop.org/Software/xlibs
COMMENT=		Authorization Protocol for X from freedesktop.org

CONFLICTS+=		XFree86-libs-[0-9]*

USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=    ${WRKSRC}/xau.pc.in

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
