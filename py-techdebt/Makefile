# $NetBSD$

DISTNAME=	techdebt-0.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/techdebt/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/lcetinsoy/tech-debt
COMMENT=	Technical debt tracker package
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE=	27 36

DEPENDS+=	${PYPKGPREFIX}-matplotlib>=3.2.2:../../graphics/py-matplotlib
#DEPENDS+=	${PYPKGPREFIX}-pandas>=0.23.0:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.1:../../textproc/py-yaml

post-extract:
	${MV} ${WRKSRC}/techdebt ${WRKSRC}/techdebt${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
