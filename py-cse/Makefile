# $NetBSD: Makefile,v 1.2 2014/01/26 15:49:53 thomasklausner Exp $

DISTNAME=	pycse-1.42
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/source/p/pycse/
EXTRACT_SUFX=	.zip#md5=acb390d6ddb068c301ae5debabe0f37c

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/nipy/PySurfer
COMMENT=	Python computations in science and engineering
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.2:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-docutils>=0.11:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-report-[0-9]*:../../wip/py-report

FETCH_USING= curl

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	33 # py-docutils

post-extract:
	${MV} ${WRKSRC}/pycse/publish.py ${WRKSRC}/pycse/publish.py${PYVERSSUFFIX}

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
