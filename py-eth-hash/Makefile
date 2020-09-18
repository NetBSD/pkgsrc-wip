# $NetBSD$

GITHUB_PROJECT=	eth-hash
GITHUB_TAG=	v0.2.0
DISTNAME=	v0.2.0
PKGNAME=	${PYPKGPREFIX}-${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
CATEGORIES=	finance python
MASTER_SITES=	${MASTER_SITE_GITHUB:=ethereum/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/ethereum/eth-hash
COMMENT=	eth-hash: The Ethereum hashing function, keccak256, sometimes (erroneously) called sha3
LICENSE=	mit

BUILD_DEPENDS+=	# TODO: bumpversion>=0.5.3,<1
BUILD_DEPENDS+=	# TODO: pytest-xdist>=0
BUILD_DEPENDS+=	# TODO: pytest-watch>=4.1.0,<5
BUILD_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
BUILD_DEPENDS+=	${PYPKGPREFIX}-ipython-[0-9]*:../../devel/py-ipython
BUILD_DEPENDS+=	# TODO: pytest==3.3.2>=0
BUILD_DEPENDS+=	${PYPKGPREFIX}-tox-[0-9]*:../../devel/py-tox
BUILD_DEPENDS+=	# TODO: flake8==3.4.1>=0
BUILD_DEPENDS+=	${PYPKGPREFIX}-isort-[0-9]*:../../devel/py-isort
BUILD_DEPENDS+=	# TODO: Sphinx>=1.6.5,<2
BUILD_DEPENDS+=	# TODO: sphinx_rtd_theme>=0.1.9
BUILD_DEPENDS+=	# TODO: setuptools-markdown>=0

USE_LANGUAGES=	# none

# TODO: Migrate MASTER_SITES to MASTER_SITE_PYPI
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
