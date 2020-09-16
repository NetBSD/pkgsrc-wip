# $NetBSD$

DISTNAME=	dill-0.3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://files.pythonhosted.org/packages/e2/96/518a8ea959a734b70d2e95fef98bcbfdc7adad1c1e5f5dd9148c835205a5/
EXTRACT_SUFX=	.zip

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://pypi.org/project/dill
COMMENT=	Serialize all of python
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-readline>=3.7.6:../../devel/py-readline
DEPENDS+=	${PYPKGPREFIX}-objgraph>=1.7.2:../../graphics/py-objgraph

post-extract:
	${MV} ${WRKSRC}/scripts/undill ${WRKSRC}/scripts/undill${PYVERSSUFFIX}
	${MV} ${WRKSRC}/scripts/get_objgraph ${WRKSRC}/scripts/get_objgraph${PYVERSSUFFIX}


.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
