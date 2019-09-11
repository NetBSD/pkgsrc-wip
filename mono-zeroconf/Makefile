# $NetBSD: Makefile,v 1.6 2013/06/26 12:18:25 noud4 Exp $
#

DISTNAME=	mono-zeroconf-0.9.0
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://download.banshee-project.org/mono-zeroconf/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://www.mono-project.com/Mono.Zeroconf
COMMENT=	Cross platform Zero Configuration Networking library for Mono and .NET
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake bash:run
USE_LANGUAGES=	c c++
MAKE_JOBS_SAFE=	NO

PKGCONFIG_OVERRIDE+=	src/mono-zeroconf.pc.in

CONFIGURE_ARGS+=	--disable-mdnsresponder \
			--disable-avahi

REPLACE_BASH+=	src/MZClient/mzclient.in

.include "../../lang/mono2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
