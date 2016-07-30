# $NetBSD$

DISTNAME=	tribe-1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tribe/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/DistrictDataLabs/tribe
COMMENT=	Graph extraction tool for email MBox files
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-networkx>=1.11:../../math/py-networkx

WRKSRC=		${WRKDIR}/tribe-1.3
USE_LANGUAGES=	# none

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

post-extract:
	${MV} ${WRKSRC}/tribe-admin.py ${WRKSRC}/tribe-admin.py${PYVERSSUFFIX}

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
