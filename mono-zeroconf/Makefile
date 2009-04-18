# $NetBSD: Makefile,v 1.1.1.1 2009/04/18 00:35:20 jihbed Exp $
#

DISTNAME=	mono-zeroconf-0.8.0
CATEGORIES=	net
MASTER_SITES=	http://download.banshee-project.org/mono-zeroconf/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.mono-project.com/Mono.Zeroconf
COMMENT=	Cross platform Zero Configuration Networking library for Mono and .NET

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	src/mono-zeroconf.pc.in

CONFIGURE_ARGS+=	--disable-mdnsresponder
CONFIGURE_ARGS+=	--disable-avahi

.include "../../lang/mono/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
