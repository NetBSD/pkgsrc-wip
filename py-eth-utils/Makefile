# $NetBSD$

GITHUB_PROJECT=	eth-utils
GITHUB_TAG=	v1.9.5
DISTNAME=	v1.9.5
PKGNAME=	${PYPKGPREFIX}-${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
CATEGORIES=	finance python
MASTER_SITES=	${MASTER_SITE_GITHUB:=ethereum/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/ethereum/eth-utils
COMMENT=	Common utility functions for ethereum codebases
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-twine-[0-9]*:../../net/py-twine
BUILD_DEPENDS+=	# TODO: Sphinx>=1.5.5,<2
BUILD_DEPENDS+=	# TODO: sphinx_rtd_theme>=0.1.9,<2
BUILD_DEPENDS+=	# TODO: towncrier>=19.2.0,<20
BUILD_DEPENDS+=	${PYPKGPREFIX}-black-[0-9]*:../../wip/py-black
BUILD_DEPENDS+=	${PYPKGPREFIX}-flake8-[0-9]*:../../devel/py-flake8
BUILD_DEPENDS+=	# TODO: isort==4.3.18>=0
BUILD_DEPENDS+=	# TODO: mypy==0.720>=0
BUILD_DEPENDS+=	# TODO: pytest>=3.4.1,<4.0.0
BUILD_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis
BUILD_DEPENDS+=	# TODO: pytest>=3.4.1,<4.0.0
BUILD_DEPENDS+=	# TODO: pytest-pythonpath>=0.3,<1.0
BUILD_DEPENDS+=	# TODO: bumpversion>=0.5.3,<1.0.0
BUILD_DEPENDS+=	${PYPKGPREFIX}-tox-[0-9]*:../../devel/py-tox
BUILD_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	# TODO: eth-hash>=0.1.0,<1.0.0
DEPENDS+=	# TODO: eth-typing>=2.2.1,<3.0.0
DEPENDS+=	${PYPKGPREFIX}-toolz-[0-9]*:../../devel/py-toolz
DEPENDS+=	${PYPKGPREFIX}-cytoolz-[0-9]*:../../wip/py-cytoolz

USE_LANGUAGES=	# none

# TODO: Migrate MASTER_SITES to MASTER_SITE_PYPI
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
