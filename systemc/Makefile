# $NetBSD$

DISTNAME=	systemc-2.3.3
CATEGORIES=	lang
MASTER_SITES=	https://accellera.org/images/downloads/standards/systemc/
EXTRACT_USING=	bsdtar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://accellera.org/community/systemc/
COMMENT=	C language for system design
LICENSE=	apache-2.0

#GNU_CONFIGURE=	yes
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DENABLE_PTHREADS=ON

PKGCONFIG_OVERRIDE+=	src/systemc.pc.in

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
