# $NetBSD$

DISTNAME=	asyncore-v1.0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-v/-/1}
CATEGORIES=	python devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=simonrob/}
DIST_SUBDIR=	${GITHUB_PROJECT}
GITHUB_PROJECT=	pyasyncore
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/simonrob/pyasyncore/
COMMENT=	The asyncore module found in Python prior to 3.12
LICENSE=	python-software-foundation

# Only for 3.12 and onwards, for backward compatibility with the latter of:
PYTHON_VERSIONS_INCOMPATIBLE=	27 38 39 310 311

USE_LANGUAGES=	c

# Probably only works after "make install":
do-test:
	${PYTHONBIN} ${WRKSRC}/tests/test_asyncore.py

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
