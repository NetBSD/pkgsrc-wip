# $NetBSD$

DISTNAME=	toposort-1.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=t/toposort/}

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	https://gitlab.com/ericvsmith/toposort
COMMENT=	Implements a topological sort algorithm
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
