# $NetBSD: Makefile,v 1.2 2015/08/06 00:09:22 jihbed Exp $

DISTNAME=	geners-1.9.0
CATEGORIES=	devel
MASTER_SITES=	https://geners.hepforge.org/downloads/?f=

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://geners.hepforge.org/
COMMENT=	Generic Serialization for C++
LICENSE=	gnu-lgpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	geners.pc.in

.include "../../mk/bsd.pkg.mk"
