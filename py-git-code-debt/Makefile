# $NetBSD$

DISTNAME=	git_code_debt-1.1.0
PKGNAME=	${PYPKGPREFIX}-git-code-debt-1.1.0
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/git_code_debt/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/asottile/git-code-debt
COMMENT=	Dashboard for monitoring code debt in a git repository
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-sqlite3>=3.7.9:../../databases/py-sqlite3

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
