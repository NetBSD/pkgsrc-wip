# $NetBSD$

DISTNAME=	openai-0.27.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=o/openai/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://pypi.org/project/openai/
COMMENT=	OpenAI Python Library
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-aiohttp-[0-9]*:../../www/py-aiohttp
DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-openpyxl>=3.0.7:../../textproc/py-openpyxl
DEPENDS+=	${PYPKGPREFIX}-pandas>=1.2.3:../../math/py-pandas
#DEPENDS+=	${PYPKGPREFIX}-plotly-[0-9]*:../../graphics/py-plotly
DEPENDS+=	${PYPKGPREFIX}-requests>=2.20:../../devel/py-requests
#DEPENDS+=	${PYPKGPREFIX}-scikit-learn>=1.0.2:../../math/py-scikit-learn
DEPENDS+=	${PYPKGPREFIX}-scipy-[0-9]*:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-tenacity>=8.0.1:../../devel/py-tenacity
DEPENDS+=	${PYPKGPREFIX}-tqdm-[0-9]*:../../misc/py-tqdm
DEPENDS+=	${PYPKGPREFIX}-typing-extensions-[0-9]*:../../devel/py-typing-extensions
#DEPENDS+=	${PYPKGPREFIX}-wandb-[0-9]*:../../math/py-wandb

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 37 # py-scipy

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/openai ${DESTDIR}${PREFIX}/bin/openai-${PYVERSSUFFIX}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
