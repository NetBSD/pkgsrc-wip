# $NetBSD: Makefile,v 1.1 2013/04/09 07:48:05 jgoamakf Exp $
#

DISTNAME=	libcaca-0.99.beta18
PKGNAME=	libcaca-0.99beta18
CATEGORIES=	graphics
MASTER_SITES=	http://caca.zoy.org/files/libcaca/
#EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://caca.zoy.org/
COMMENT=	Graphics library that outputs text instead of pixels, in colour

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_NCURSES=		yes
USE_LANGUAGES=		c c++
PKGCONFIG_OVERRIDE+=    caca/caca.pc.in

CONFIGURE_ARGS+=	--enable-network
CONFIGURE_ARGS+=	--enable-imlib2

CONFIGURE_ARGS+=	--enable-ncurses
CONFIGURE_ARGS+=	--disable-slang
CONFIGURE_ARGS+=	--disable-x11
CONFIGURE_ARGS+=	--disable-gl
CONFIGURE_ARGS+=	--disable-cocoa

CONFIGURE_ARGS+=	--disable-csharp
CONFIGURE_ARGS+=	--disable-java
CONFIGURE_ARGS+=	--disable-cxx
CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--disable-ruby
CONFIGURE_ARGS+=	--disable-doc
CONFIGURE_ARGS+=	--disable-cppunit
CONFIGURE_ARGS+=	--disable-zzuf

.include "../../mk/bsd.prefs.mk"

.include "../../devel/ncurses/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
