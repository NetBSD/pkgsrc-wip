# $NetBSD$

DISTNAME=	symbolic_equation-0.2.0
PKGNAME=	${PYPKGPREFIX}-symbolic-equation-0.2.0
CATEGORIES=	math python
MASTER_SITES=	https://files.pythonhosted.org/packages/1c/a3/075eebd0186279c12eabd4466dcbbac2b57f39991151f3c1bbef34de6f7f/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/goerz/symbolic_equation
COMMENT=	Class for multiline symbolic equations in the Jupyter Notebook
LICENSE=	modified-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-black-[0-9]*:../../wip/py-black
BUILD_DEPENDS+=	${PYPKGPREFIX}-coverage>=5.2.1:../../devel/py-coverage
BUILD_DEPENDS+=	${PYPKGPREFIX}-coveralls>=2.4.2:../../wip/py-coveralls
BUILD_DEPENDS+=	${PYPKGPREFIX}-flake8>=3.8.3:../../devel/py-flake8
BUILD_DEPENDS+=	${PYPKGPREFIX}-gitpython>=3.1.8:../../devel/py-gitpython
BUILD_DEPENDS+=	${PYPKGPREFIX}-isort>=4.3.21:../../devel/py-isort
BUILD_DEPENDS+=	${PYPKGPREFIX}-ipython>=7.18.1:../../devel/py-ipython
BUILD_DEPENDS+=	${PYPKGPREFIX}-jupyter_core>=4.6.3:../../devel/py-jupyter_core
BUILD_DEPENDS+=	${PYPKGPREFIX}-nbsphinx>=0.7.1:../../wip/py-nbsphinx
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-nbval>=0.9.6:../../wip/py-test-nbval
BUILD_DEPENDS+=	pre-commit>=2.7.1:../../wip/pre-commit
BUILD_DEPENDS+=	${PYPKGPREFIX}-pylint>=1.9.3:../../devel/py-pylint
BUILD_DEPENDS+=	${PYPKGPREFIX}-test>=5.3.5:../../devel/py-test
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-cov>=2.10.1:../../devel/py-test-cov
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=1.34.0:../../devel/py-test-xdist
BUILD_DEPENDS+=	${PYPKGPREFIX}-sympy>=1.6.2:../../math/py-sympy
BUILD_DEPENDS+=	${PYPKGPREFIX}-twine>=1.13.0:../../net/py-twine
BUILD_DEPENDS+=	${PYPKGPREFIX}-watermark>=2.0.2:../../wip/py-watermark
BUILD_DEPENDS+=	${PYPKGPREFIX}-wheel>=0.35.1:../../devel/py-wheel

DEPENDS+=	${PYPKGPREFIX}-uniseg>=0.7.1:../../wip/py-uniseg

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
