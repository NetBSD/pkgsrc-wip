# $NetBSD: Makefile,v 1.4 2012/10/03 15:09:56 asau Exp $
#

DISTNAME=	mono-zeroconf-0.9.0
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://download.banshee-project.org/mono-zeroconf/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.mono-project.com/Mono.Zeroconf
COMMENT=	Cross platform Zero Configuration Networking library for Mono and .NET
LICENSE=	LICENSE

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake bash:run
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	src/mono-zeroconf.pc.in

CONFIGURE_ARGS+=	--disable-mdnsresponder \
			--disable-avahi

REPLACE_BASH+=	src/MZClient/mzclient.in

.include "../../lang/mono/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
