# $NetBSD$

DISTNAME=	conda-env-2.4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/conda-env/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/conda/conda-env
COMMENT=	Tools for interacting with conda environments
LICENSE=	modified-bsd

USE_TOOLS+=	bash
USE_LANGUAGES=	# none

REPLACE_BASH+=	bin/activate${PYVERSSUFFIX} bin/deactivate${PYVERSSUFFIX}

post-extract:
	${MV} ${WRKSRC}/bin/activate ${WRKSRC}/bin/activate${PYVERSSUFFIX}
	${MV} ${WRKSRC}/bin/conda-env ${WRKSRC}/bin/conda-env${PYVERSSUFFIX}
	${MV} ${WRKSRC}/bin/deactivate ${WRKSRC}/bin/deactivate${PYVERSSUFFIX}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
