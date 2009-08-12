# $NetBSD: Makefile,v 1.3 2009/08/12 02:32:04 obache Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake bash:run
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	src/mono-zeroconf.pc.in

CONFIGURE_ARGS+=	--disable-mdnsresponder \
			--disable-avahi

REPLACE_BASH+=	src/MZClient/mzclient.in

.include "../../lang/mono/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
