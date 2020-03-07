# $NetBSD$

DISTNAME=	gitdb-4.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/gitdb/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://github.com/gitpython-developers/gitdb
COMMENT=	Git Object Database
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-smmap-[0-9]*:../../wip/py-smmap
# Tests are not intended to be run from pypi distfile, but git repository
# https://github.com/gitpython-developers/gitdb/issues/42
TEST_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
