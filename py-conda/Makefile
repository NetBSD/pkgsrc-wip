# $NetBSD$

DISTNAME=	conda-3.17.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/conda/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/conda/conda
COMMENT=	Package management tool
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-requests>=2.7.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.11:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-conda-env>=2.4.2:../../wip/py-conda-env
DEPENDS+=	${PYPKGPREFIX}-cosat>=0.6.1:../../wip/py-cosat

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} runtests.sh

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
