# $NetBSD: Makefile,v 1.1.1.1 2003/11/26 23:15:10 jeremy-c-reed Exp $
#

DISTNAME=		libX11-6.2.1
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/dist/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.freedesktop.org/Software/X11
COMMENT=		Base X libraries from freedesktop.org

CONFLICTS+=		XFree86-libs-[0-9]*

# later use buildlink
DEPENDS+=		xproto>=6.6:../../new/xproto
DEPENDS+=		xextensions>=1.0:../../new/xextensions
DEPENDS+=		xtrans>=0.1:../../new/xtrans
DEPENDS+=		libXau>=0.1:../../new/libXau

# need to buildlink for xtrans for include/X11/Xtrans/transport.c
#USE_BUILDLINK2=		yes

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=	${WRKSRC}/x11.pc.in
GNU_CONFIGURE=		yes
USE_GMAKE=		yes

CONFIGURE_ENV+=		KEYSYMDEF=${X11PREFIX}/include/X11/keysymdef.h

.include "../../mk/bsd.pkg.mk"
