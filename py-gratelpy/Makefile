# $NetBSD: Makefile,v 1.2 2014/01/26 15:49:55 thomasklausner Exp $

DISTNAME=	GraTeLPy-0.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/source/G/GraTeLPy/
FETCH_USING=	curl

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://pypi.python.org/packages/source/G/GraTeLPy/
COMMENT=	Graph theoretic linear stability analysis
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-networkx>=1.7:../../math/py-networkx

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	33 # py-networkx

post-extract:
	${MV} ${WRKSRC}/bin/gratelpy_benchmark ${WRKSRC}/bin/gratelpy_benchmark${PYVERSSUFFIX}
	${MV} ${WRKSRC}/bin/gratelpy_check_data ${WRKSRC}/bin/gratelpy_check_data${PYVERSSUFFIX}
	${MV} ${WRKSRC}/bin/gratelpy_fragment_server ${WRKSRC}/bin/gratelpy_fragment_server${PYVERSSUFFIX}
	${MV} ${WRKSRC}/bin/gratelpy_subclient ${WRKSRC}/bin/gratelpy_subclient${PYVERSSUFFIX}
	${MV} ${WRKSRC}/bin/gratelpy_test ${WRKSRC}/bin/gratelpy_test${PYVERSSUFFIX}
	${MV} ${WRKSRC}/bin/gratelpy_time ${WRKSRC}/bin/gratelpy_time${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
