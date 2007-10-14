# $NetBSD: Makefile,v 1.1.1.1 2007/10/14 12:47:25 hoka_adam Exp $
#

DISTNAME=	libconfig-1.1.3
CATEGORIES=	devel
MASTER_SITES=	http://www.hyperrealm.com/libconfig/

MAINTAINER=	adam.hoka@gmail.com
HOMEPAGE=	http://www.hyperrealm.com/libconfig/
COMMENT=	Simple library for manipulating structured configuration files

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config cpp bison
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	libconfig++.pc.in
PKGCONFIG_OVERRIDE+=	libconfig.pc.in

.include "../../mk/bsd.pkg.mk"
