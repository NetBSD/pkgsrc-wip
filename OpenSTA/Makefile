# $NetBSD$

GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}
DISTNAME=	OpenSTA-2.2.0
CATEGORIES=	cad devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=The-OpenROAD-Project/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/The-OpenROAD-Project/OpenSTA/
COMMENT=	Gate level static timing verifier
LICENSE=	gnu-gpl-v3

WRKSRC=	${WRKDIR}/${DISTNAME}

GCC_REQD+=	10

USE_LANGUAGES=	c++

.include "../../wip/cudd/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
