# $NetBSD$

DISTNAME=	gnat-${GNATVER}
CATEGORIES=	lang
MASTER_SITES=	https://community.download.adacore.com/v1/649a561ec6de9e476c54b02715b79f7503600ce5?filename=

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://community.download.adacore.com/v1/
COMMENT=	Tools for ada lang
LICENSE=	gnu-gpl-v3

GNATVER=	2020-20200429-19B04-src
USE_LANGUAGES=	c c++ ada
USE_TOOLS=	gmake makeinfo automake
#GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/gnat-2020-20200429-19B04-src/src
CHECK_PORTABILITY_SKIP+= contrib/*.sh # not used during the build


#.include "../../lang/gcc9/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
