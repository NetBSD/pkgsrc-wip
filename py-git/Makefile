# $NetBSD: Makefile,v 1.3 2014/12/31 13:58:32 thomasklausner Exp $

DISTNAME=	GitPython-2.0.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/GitPython/git/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=G/GitPython/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://github.com/gitpython-developers/GitPython
COMMENT=	Python library used to interact with Git repositories
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-smmap>=0.8.5:../../wip/py-smmap
DEPENDS+=	${PYPKGPREFIX}-gitdb>=0.6.1:../../wip/py-gitdb
DEPENDS+=	git>=1.7.0:../../devel/git

# TEST_DEPENDS
BUILD_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
BUILD_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose

#PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # not yet ported as of 0.3.2.RC1

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
