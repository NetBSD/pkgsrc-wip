# $NetBSD: Makefile,v 1.1 2007/02/24 21:21:15 bsadewitz Exp $
#

DISTNAME=	libXfontcache-1.0.4
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/lib/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Font cache library from modular X.org

BUILD_DEFS+=	VARBASE

CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
CONFIGURE_ARGS+=	--disable-dependency-tracking

PKG_DESTDIR_SUPPORT=	user-destdir
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config gmake
PKGCONFIG_OVERRIDE+=	${WRKSRC}/xfontcache.pc.in


.include "../../x11/fontcacheproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
