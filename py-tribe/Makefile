# $NetBSD$

DISTNAME=	tribe-1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	mail python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tribe/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/DistrictDataLabs/tribe
COMMENT=	Graph extraction tool for email MBox files
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-networkx>=1.11:../../math/py-networkx
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	# none

post-extract:
	${MV} ${WRKSRC}/tribe-admin.py ${WRKSRC}/tribe-admin.py${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
