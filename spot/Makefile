# $NetBSD$

DISTNAME=	spot-2.7.1
CATEGORIES=	math
MASTER_SITES=	http://www.lrde.epita.fr/dload/spot/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://spot.lrde.epita.fr/
COMMENT=	Library for omega automata manipulation and model checking
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config perl
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	buddy/src/libbddx.pc.in
PKGCONFIG_OVERRIDE+=	spot/ltsmin/libspotltsmin.pc.in
PKGCONFIG_OVERRIDE+=	spot/libspot.pc.in
PKGCONFIG_OVERRIDE+=	spot/gen/libspotgen.pc.in

#Minimum configuration.

CONFIGURE_ARGS+=	--enable-doxygen
CONFIGURE_ARGS+=	--disable-python

DEPENDS+=	doxygen>=1.8.15:../../devel/doxygen

.include "../../mk/bsd.pkg.mk"
