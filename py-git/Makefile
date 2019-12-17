# $NetBSD: Makefile,v 1.3 2014/12/31 13:58:32 thomasklausner Exp $

DISTNAME=	GitPython-3.0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/GitPython/git/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=G/GitPython/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://github.com/gitpython-developers/GitPython
COMMENT=	Python library used to interact with Git repositories
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-gitdb2>=2.0.0:../../wip/py-gitdb2
DEPENDS+=	git-base>=1.7.0:../../devel/git-base

# tests are not intended to be run from pypi distfile,
# since they operate on GitPython's git repository, see
# https://github.com/gitpython-developers/GitPython/issues/673
TEST_DEPENDS+=	${PYPKGPREFIX}-ddt-[0-9]*:../../devel/py-ddt
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose

USE_LANGUAGES=	# none

# Only for Python 3.x
PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
