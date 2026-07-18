# $NetBSD$

DISTNAME=	prysk-0.20.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/prysk/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.prysk.net/
COMMENT=	Functional tests for command line applications
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core-[0-9]*:../../devel/py-poetry-core

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	prysk

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
