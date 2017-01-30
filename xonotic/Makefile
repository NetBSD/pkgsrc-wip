# $NetBSD$

DISTNAME=	xonotic-0.8.1
CATEGORIES=	games
MASTER_SITES=	http://nl.dl.xonotic.org/
EXTRACT_SUFX=	.zip

MAINTAINER=	cfkoch@edgebsd.org
COMMENT=	The free and fast arena shooter
HOMEPAGE=	http://xonotic.org/
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake
USE_LANGUAGES+=	c c++

WRKSRC=		${WRKDIR}/Xonotic
BUILD_TARGET=	all-zip-source
INSTALL_TARGET=	install-data-zip-source install-engine-zip-source install-links
INSTALL_ENV+=	LIBDIR=$(PREFIX)/lib

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
