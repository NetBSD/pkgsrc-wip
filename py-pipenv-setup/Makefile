# $NetBSD$

DISTNAME=	pipenv-setup-3.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pipenv-setup/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/Madoshakalaka/pipenv-setup
COMMENT=	Sync Pipfile/Pipfile.lock to setup.py
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE+=	27

BUILD_DEPENDS+=	${PYPKGPREFIX}-test>=5.3.10:../../devel/py-test
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-mypy>=0.7.0:../../wip/py-test-mypy
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-cov>=2.10.1:../../devel/py-test-cov
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-datadir>=1.3.1:../../wip/py-test-datadir
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=1.34.0:../../devel/py-test-xdist
BUILD_DEPENDS+=	${PYPKGPREFIX}-tox>=3.20.1:../../devel/py-tox
DEPENDS+=	${PYPKGPREFIX}-pipfile>=0.0.2:../../wip/py-pipfile
DEPENDS+=	${PYPKGPREFIX}-black-[0-9]*:../../textproc/py-black
DEPENDS+=	${PYPKGPREFIX}-colorama>=0.4.3:../../comms/py-colorama
DEPENDS+=	${PYPKGPREFIX}-packaging>=19.2:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-vistir>=0.4:../../wip/py-vistir
DEPENDS+=	${PYPKGPREFIX}-autopep8>=1.5.4:../../devel/py-autopep8
DEPENDS+=	${PYPKGPREFIX}-six>=1.15.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-requirementslib>=0.5.15:../../wip/py-requirementslib

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
