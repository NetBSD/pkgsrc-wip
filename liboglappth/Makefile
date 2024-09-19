# $NetBSD: Makefile,v 1.2 2012/10/03 09:10:40 asau Exp $
#

DISTNAME=	liboglappth-0.98
CATEGORIES=	biology
MASTER_SITES=	http://www.bioinformatics.org/ghemical/download/release20090911/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://www.bioinformatics.org/ghemical/ghemical/
COMMENT=	Support libraries of science/ghemical port
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	liboglappth.pc.in

.include "../../graphics/freeglut/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
