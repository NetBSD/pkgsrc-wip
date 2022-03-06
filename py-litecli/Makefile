# $NetBSD$

DISTNAME=	litecli-1.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_PYPI:=l/litecli/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://litecli.com
COMMENT=	CLI for SQLite Databases with auto-completion and syntax highlighting
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-cli_helpers-[0-9]*:../../wip/py-cli_helpers
DEPENDS+=	${PYPKGPREFIX}-sqlparse-[0-9]*:../../databases/py-sqlparse

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
