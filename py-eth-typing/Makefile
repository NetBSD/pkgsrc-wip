# $NetBSD$

GITHUB_PROJECT=	eth-typing
GITHUB_TAG=	v2.2.2
DISTNAME=	v2.2.2
PKGNAME=	${PYPKGPREFIX}-${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
CATEGORIES=	finance python
MASTER_SITES=	${MASTER_SITE_GITHUB:=ethereum/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/ethereum/eth-typing
COMMENT=	eth-typing: Common type annotations for ethereum python packages
LICENSE=	mit

BUILD_DEPENDS+=	# TODO: bumpversion>=0.5.3,<1
BUILD_DEPENDS+=	# TODO: pytest-watch>=4.1.0,<5
BUILD_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
BUILD_DEPENDS+=	${PYPKGPREFIX}-twine-[0-9]*:../../net/py-twine
BUILD_DEPENDS+=	${PYPKGPREFIX}-ipython-[0-9]*:../../devel/py-ipython
BUILD_DEPENDS+=	# TODO: pytest>=4.4,<4.5
BUILD_DEPENDS+=	# TODO: pytest-xdist>=0
BUILD_DEPENDS+=	${PYPKGPREFIX}-tox-[0-9]*:../../devel/py-tox
BUILD_DEPENDS+=	# TODO: flake8==3.8.3>=0
BUILD_DEPENDS+=	${PYPKGPREFIX}-isort-[0-9]*:../../devel/py-isort
BUILD_DEPENDS+=	# TODO: mypy==0.782>=0
BUILD_DEPENDS+=	# TODO: pydocstyle>=3.0.0,<4
BUILD_DEPENDS+=	# TODO: Sphinx>=1.6.5,<2
BUILD_DEPENDS+=	# TODO: sphinx_rtd_theme>=0.1.9

USE_LANGUAGES=	# none

# TODO: Migrate MASTER_SITES to MASTER_SITE_PYPI
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
