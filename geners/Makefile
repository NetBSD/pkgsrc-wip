# $NetBSD: Makefile,v 1.1 2014/11/22 12:22:53 jihbed Exp $

DISTNAME=	geners-1.5.0
CATEGORIES=	devel
MASTER_SITES=	http://www.hepforge.org/archive/geners/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://geners.hepforge.org/
COMMENT=	Generic Serialization for C++
LICENSE=	gnu-lgpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	geners.pc.in

.include "../../mk/bsd.pkg.mk"
