# $NetBSD$

DISTNAME=	github3.py-1.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/github3.py/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github3py.readthedocs.org/
COMMENT=	Python wrapper for the GitHub API
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.6.0:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-jwcrypto>=0.5.0:../../wip/py-jwcrypto
DEPENDS+=	${PYPKGPREFIX}-requests>=2.18:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-uritemplate>=3.0.0:../../textproc/py-uritemplate

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
