# $NetBSD: Makefile,v 1.1.1.1 2010/06/06 16:02:26 jihbed Exp $
#

DISTNAME=	liboglappth-0.98
CATEGORIES=	biology
MASTER_SITES=	http://www.bioinformatics.org/ghemical/download/release20090911/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.bioinformatics.org/ghemical/ghemical/
COMMENT=	Support libraries of science/ghemical port
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	liboglappth.pc.in

.include "../../graphics/glut/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
