# $NetBSD$

DISTNAME=	git_bayesect-1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/git_bayesect/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://hauntsaninja.github.io/git_bayesect.html
COMMENT=	Bayesian git bisect
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core-[0-9]*:../../devel/py-flit_core

USE_LANGUAGES=	# none

PY_RENAME_BINARIES+=	git-bayesect
PY_RENAME_BINARIES+=	git_bayesect

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
