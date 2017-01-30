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

.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
