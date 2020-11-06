# $NetBSD$

DISTNAME=	coconut-1.4.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	lang python
MASTER_SITES=	https://files.pythonhosted.org/packages/49/bd/c77663bf5525bcb3c0995ebe0257cc5a9ef6d191cdb354faccc9841afe99/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://coconut-lang.org
COMMENT=	Simple, elegant, Pythonic functional programming
LICENSE=	apache-2.0

BUILD_DEPENDS+=	${PYPKGPREFIX}-ipython>=6.5:../../devel/py-ipython
BUILD_DEPENDS+=	${PYPKGPREFIX}-jupyter-console>=5.2:../../wip/py-jupyter-console
BUILD_DEPENDS+=	${PYPKGPREFIX}-pyparsing>=2.4.5:../../devel/py-pyparsing
BUILD_DEPENDS+=	${PYPKGPREFIX}-psutil>=5.7.2:../../sysutils/py-psutil
BUILD_DEPENDS+=	${PYPKGPREFIX}-vprof>=0.36:../../wip/py-vprof
BUILD_DEPENDS+=	${PYPKGPREFIX}-requests>=2.24.0:../../devel/py-requests
BUILD_DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.7.4:../../textproc/py-sphinx
BUILD_DEPENDS+=	${PYPKGPREFIX}-sphinx-bootstrap-theme>=0.4:../../wip/py-sphinx-bootstrap-theme
BUILD_DEPENDS+=	${PYPKGPREFIX}-jupyter>=1.0:../../devel/py-jupyter
BUILD_DEPENDS+=	${PYPKGPREFIX}-ipykernel>=5.1:../../devel/py-ipykernel
BUILD_DEPENDS+=	${PYPKGPREFIX}-test>=6.1.2:../../devel/py-test
BUILD_DEPENDS+=	${PYPKGPREFIX}-recommonmark>=0.6:../../wip/py-recommonmark
BUILD_DEPENDS+=	${PYPKGPREFIX}-watchdog>=0.9:../../sysutils/py-watchdog
BUILD_DEPENDS+=	${PYPKGPREFIX}-pygments>=2.3.1:../../textproc/py-pygments
BUILD_DEPENDS+=	${PYPKGPREFIX}-pexpect>=4.8.0:../../devel/py-pexpect
BUILD_DEPENDS+=	${PYPKGPREFIX}-mypy>=0.761:../../lang/py-mypy
BUILD_DEPENDS+=	pre-commit>=2.8.2:../../wip/pre-commit
DEPENDS+=	${PYPKGPREFIX}-cPyparsing>=2.4.5.0.1.1:../../wip/py-cPyparsing
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.3.1:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-prompt_toolkit>=3.0.8:../../devel/py-prompt_toolkit

USE_LANGUAGES=	# none

BUILDLINK_DEPENDS.${PYPKGPREFIX}-numpy+=	build
BUILDLINK_API_DEPENDS.${PYPKGPREFIX}-numpy+=	${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
