# $NetBSD: Makefile,v 1.10 2014/05/09 07:38:49 thomasklausner Exp $

DISTNAME=	sh-1.12.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sh/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/sh
COMMENT=	Python subprocess interface
LICENSE=	mit

# TEST_DEPENDS
BUILD_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
