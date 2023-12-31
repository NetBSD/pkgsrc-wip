# $NetBSD$

DISTNAME=	dd-0.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dd/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/dd/
COMMENT=	Binary decision diagrams in Python, wrappers of CUDD, Sylvan, BuDDy
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-astutils>=0.0.5:../../wip/py-astutils

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
