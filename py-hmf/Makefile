# $NetBSD$

DISTNAME=	hmf-2.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://pypi.python.org/packages/68/8b/8c566eb5fcfed49470862cbab4b173cb3d93db34494b3a915dd2dbfaa45a/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/steven-murray/hmf
COMMENT=	Halo mass function calculator
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.17.0:../../math/py-scipy

WRKSRC=		${WRKDIR}/hmf-2.0.1

USE_LANGUAGES=	# none

post-extract:
	${MV} ${WRKSRC}/scripts/hmf  ${WRKSRC}/scripts/hmf${PYVERSSUFFIX}
	${MV} ${WRKSRC}/scripts/hmf-fit  ${WRKSRC}/scripts/hmf-fit${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
