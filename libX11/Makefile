# $NetBSD: Makefile,v 1.3 2003/11/26 23:56:47 xtraeme Exp $
#

DISTNAME=		libX11-6.2.1
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/dist/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.freedesktop.org/Software/X11
COMMENT=		Base X libraries from freedesktop.org

CONFLICTS+=		XFree86-libs-[0-9]*

USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=	${WRKSRC}/x11.pc.in
GNU_CONFIGURE=		yes
USE_GMAKE=		yes

CONFIGURE_ENV+=		KEYSYMDEF=${X11PREFIX}/include/X11/keysymdef.h

.include "../../wip/xextensions/buildlink2.mk"
.include "../../wip/xproto/buildlink2.mk"
.include "../../wip/xtrans/buildlink2.mk"
.include "../../wip/libXau/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
